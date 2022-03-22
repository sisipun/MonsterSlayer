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
	Super::Hit(Power);
	if (Health <= 0)
	{
		Destroy();
	}
}