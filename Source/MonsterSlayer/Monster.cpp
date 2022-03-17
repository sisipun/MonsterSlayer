#include "Monster.h"
#include "MonsterController.h"

AMonster::AMonster()
{
	PrimaryActorTick.bCanEverTick = false;

	AIControllerClass = AMonsterController::StaticClass();
}
