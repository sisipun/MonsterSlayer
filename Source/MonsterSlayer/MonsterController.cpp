#include "MonsterController.h"

#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AISenseConfig_Damage.h"

#include "Monster.h"

void AMonsterController::OnPossess(APawn* PossessedPawn)
{
	Super::OnPossess(PossessedPawn);

	AMonster* Monster = Cast<AMonster>(PossessedPawn);
	RunBehaviorTree(Monster->BehaviorTree);
}