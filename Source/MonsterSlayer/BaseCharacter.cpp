#include "BaseCharacter.h"

#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TimerManager.h"

FName ABaseCharacter::WEAPON_SOCKET_NAME = TEXT("weapon");

ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;

	GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
	GetMesh()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);

	AttackAnimation = CreateDefaultSubobject<UAnimMontage>(TEXT("Attack Animation"));

	AbilitySystemComponent = CreateDefaultSubobject<UCharacterAbilitySystemComponent>(TEXT("Ability System Component"));
	Attributes = CreateDefaultSubobject<UCharacterAttributeSet>(TEXT("Attributes"));
}

void ABaseCharacter::PossessedBy(AController* OwnerController)
{
	Super::PossessedBy(OwnerController);

	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	InitializeAbilities();
}

void ABaseCharacter::InitializeAbilities()
{
	for (TSubclassOf<UCharacterGameplayAbility>& Ability : Abilities)
	{
		AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(Ability, 1.0f, INDEX_NONE, this));
	}

	for (TSubclassOf<UGameplayEffect>& Effect : PassiveEffects)
	{
		FGameplayEffectContextHandle ContextHandle = AbilitySystemComponent->MakeEffectContext();
		ContextHandle.AddSourceObject(this);

		FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(Effect, 1.0f, ContextHandle);
		if (SpecHandle.IsValid())
		{
			FActiveGameplayEffectHandle GameplayEffectHandle = AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
		}
	}
}


void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (Weapons.Num() > 0)
	{
		ChangeWeapon(0);
	}
}

UAbilitySystemComponent* ABaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

float ABaseCharacter::GetMaxHealth() const
{
	return Attributes->GetMaxHealth();
}

float ABaseCharacter::GetHealth() const
{
	return Attributes->GetHealth();
}

float ABaseCharacter::GetMaxMana() const
{
	return Attributes->GetMaxMana();
}

float ABaseCharacter::GetMana() const
{
	return Attributes->GetMana();
}

float ABaseCharacter::GetAttackPower() const
{
	return Attributes->GetAttackPower();
}

bool ABaseCharacter::IsDead() const
{
	return GetHealth() <= 0;
}

bool ABaseCharacter::IsMovementBlock() const
{
	return IsDead() || AbilitySystemComponent->GetActiveAbilitiesWithTags(MovementBlockTags).Num() > 0;
}

bool ABaseCharacter::ActivateAbilitiesWithTags(FGameplayTagContainer AbilityTags)
{
	if (!IsDead()) 
	{
		return AbilitySystemComponent->TryActivateAbilitiesByTag(AbilityTags);
	}
	 
	return false;
}

void ABaseCharacter::ChangeWeapon(int index)
{
	if (CurrentWeapon)
	{
		CurrentWeapon->Destroy();
	}

	FTransform SocketTransform = GetMesh()->GetSocketTransform(ABaseCharacter::WEAPON_SOCKET_NAME);
	FActorSpawnParameters SpawnParams = FActorSpawnParameters();
	SpawnParams.Instigator = this;
	AActor* Weapon = GetWorld()->SpawnActor(Weapons[index], &SocketTransform, SpawnParams);
	CurrentWeapon = Cast<AWeapon>(Weapon);
	CurrentWeapon->AttachToComponent(
		GetMesh(),
		FAttachmentTransformRules(
			EAttachmentRule::SnapToTarget,
			EAttachmentRule::SnapToTarget,
			EAttachmentRule::KeepWorld,
			true
		),
		ABaseCharacter::WEAPON_SOCKET_NAME
	);
}

void ABaseCharacter::Destroyed()
{
	Super::Destroyed();

	if (CurrentWeapon)
	{
		CurrentWeapon->Destroy();
	}
}