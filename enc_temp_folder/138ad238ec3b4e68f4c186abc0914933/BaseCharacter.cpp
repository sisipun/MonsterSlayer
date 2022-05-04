#include "BaseCharacter.h"

#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TimerManager.h"

FName ABaseCharacter::WEAPON_SOCKET_NAME = TEXT("weapon");

ABaseCharacter::ABaseCharacter() : ABaseCharacter(-1)
{
}

ABaseCharacter::ABaseCharacter(FGenericTeamId TeamId) : TeamId(TeamId)
{
	PrimaryActorTick.bCanEverTick = false;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;

	GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
	GetMesh()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);

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
		EquipWeapon(Weapons[0]);
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

float ABaseCharacter::GetLevel() const
{
	return Attributes->GetLevel();
}

float ABaseCharacter::GetExperience() const
{
	return Attributes->GetExperience();
}

float ABaseCharacter::GetNextLevelExperience() const
{
	return Attributes->GetNextLevelExperience();
}

bool ABaseCharacter::IsDead() const
{
	return GetHealth() <= 0;
}

bool ABaseCharacter::IsMovementBlock() const
{
	return IsDead() || AbilitySystemComponent->GetActiveAbilitiesWithTags(MovementBlockTags).Num() > 0;
}

bool ABaseCharacter::IsAttacking() const
{
	return AbilitySystemComponent->GetActiveAbilitiesWithTags(AttackTags).Num() > 0;
}

FGenericTeamId ABaseCharacter::GetGenericTeamId() const
{
	return TeamId;
}

bool ABaseCharacter::ActivateAbilitiesWithTags(FGameplayTagContainer AbilityTags)
{
	if (!IsDead()) 
	{
		return AbilitySystemComponent->TryActivateAbilitiesByTag(AbilityTags);
	}
	 
	return false;
}

void ABaseCharacter::EquipWeapon(TSubclassOf<AWeapon> WeaponType)
{
	RemoveCurrentWeapon();

	FTransform SocketTransform = GetMesh()->GetSocketTransform(ABaseCharacter::WEAPON_SOCKET_NAME);
	FActorSpawnParameters SpawnParams = FActorSpawnParameters();
	SpawnParams.Instigator = this;
	AActor* Weapon = GetWorld()->SpawnActor(WeaponType, &SocketTransform, SpawnParams);
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

void ABaseCharacter::RemoveCurrentWeapon()
{
	if (IsValid(CurrentWeapon))
	{
		CurrentWeapon->Destroy();
	}
}

void ABaseCharacter::Destroyed()
{
	RemoveCurrentWeapon();
	Super::Destroyed();
}