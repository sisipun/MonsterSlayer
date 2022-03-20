#include "Monster.h"

#include "Components/SkeletalMeshComponent.h"

#include "MonsterController.h"

AMonster::AMonster()
{
	PrimaryActorTick.bCanEverTick = false;

	AIControllerClass = AMonsterController::StaticClass();
}

void AMonster::Hit(float Power)
{
	Health -= Power;
	if (Health <= 0)
	{
		Health = 0;
		Destroy();
	}
}

bool AMonster::isDead()
{
	return Health <= 0;
}