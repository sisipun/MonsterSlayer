#include "BaseCharacter.h"

ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	Health = MaxHealth;
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