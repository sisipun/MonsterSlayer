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
}

void ABaseCharacter::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	Health = MaxHealth;
	Mana = MaxMana;
}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;
	Mana = MaxMana;
	if (Weapons.Num() > 0) 
	{
		ChangeWeapon(0);
	}

	OnTakeAnyDamage.AddDynamic(this, &ABaseCharacter::Hit);
}

void ABaseCharacter::Attack()
{
	if (!CurrentWeapon || !CanUseAbility())
	{
		return;
	}


	bIsAttacking = true;
	PlayAnimMontage(AttackAnimation);
}

void ABaseCharacter::BeginAttack()
{
	if (CurrentWeapon) 
	{
		CurrentWeapon->BeginAttack();
	}
}

void ABaseCharacter::EndAttack()
{
	if (CurrentWeapon) 
	{
		CurrentWeapon->EndAttack();
	}

	bIsAttacking = false;
}

void ABaseCharacter::Hit(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	Health = FMath::Clamp(Health - Damage, 0.0f, MaxHealth);
}

bool ABaseCharacter::CanUseAbility() const
{
	return !IsDead() && !bIsAttacking && !GetCharacterMovement()->IsFalling();
}

bool ABaseCharacter::IsDead() const
{
	return Health <= 0;
}

void ABaseCharacter::ChangeWeapon(int index)
{
	if (!CanUseAbility())
	{
		return;
	}

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
