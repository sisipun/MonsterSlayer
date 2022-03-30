#include "BaseCharacter.h"

#include "Components/SkeletalMeshComponent.h"
#include "TimerManager.h"

FName ABaseCharacter::WEAPON_SOCKET_NAME = TEXT("weapon");

ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;
	Mana = MaxMana;
	if (Weapons.Num() > 0) {
		ChangeWeapon(0);
	}
}

void ABaseCharacter::Attack()
{
	if (!CurrentWeapon || bIsAttacking) {
		return;
	}

	bIsAttacking = true;
	CurrentWeapon->BeginAttack();
	FTimerHandle TimerHandler;
	GetWorldTimerManager().SetTimer(TimerHandler, this, &ABaseCharacter::OnAttackEnd, CurrentWeapon->AttackDelay, false);
}

void ABaseCharacter::OnAttackEnd()
{
	CurrentWeapon->EndAttack();
	bIsAttacking = false;
}

void ABaseCharacter::Hit(float Power)
{
	Health -= Power;
	if (Health < 0)
	{
		Health = 0;
	}
}

bool ABaseCharacter::isDead()
{
	return Health <= 0;
}

bool ABaseCharacter::isAttacking()
{
	return bIsAttacking;
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
