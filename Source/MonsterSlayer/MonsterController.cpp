#include "MonsterController.h"

#include "Perception/AISenseConfig_Sight.h"

#include "Monster.h"

AMonsterController::AMonsterController()
{
	AIPerception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AI Perception"));
	SetPerceptionComponent(*AIPerception);

	UAISenseConfig_Sight* Sight = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Sense"));
	Sight->DetectionByAffiliation.bDetectNeutrals = true;

	GetPerceptionComponent()->SetDominantSense(*Sight->GetSenseImplementation());
	GetPerceptionComponent()->ConfigureSense(*Sight);
}

void AMonsterController::OnPossess(APawn* Pawn) 
{
	Super::OnPossess(Pawn);

	AMonster* Monster = Cast<AMonster>(Pawn);
	RunBehaviorTree(Monster->BehaviorTree);
}