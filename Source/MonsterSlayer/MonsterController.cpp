#include "MonsterController.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AISenseConfig_Damage.h"

#include "Monster.h"

FName AMonsterController::TARGET_BLACKBOARD_KEY = TEXT("target");

AMonsterController::AMonsterController()
{
	PrimaryActorTick.bCanEverTick = true;

	AIPerception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception"));
	
	UAISenseConfig_Sight* Sight = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightSense"));
	UAISenseConfig_Damage* Damage = CreateDefaultSubobject<UAISenseConfig_Damage>(TEXT("DamageSense"));

	AIPerception->ConfigureSense(*Sight);
	AIPerception->ConfigureSense(*Damage);
	AIPerception->SetDominantSense(Sight->GetSenseImplementation());
}

void AMonsterController::BeginPlay()
{
	Super::BeginPlay();

	AIPerception->OnTargetPerceptionUpdated.AddDynamic(this, &AMonsterController::OnTargetPerceptionUpdate);
}

void AMonsterController::OnPossess(APawn* PossessedPawn)
{
	Super::OnPossess(PossessedPawn);

	AMonster* Monster = Cast<AMonster>(PossessedPawn);
	if (Monster)
	{
		UE_LOG(LogTemp, Warning, TEXT("Monst"));
		SetGenericTeamId(Monster->GetGenericTeamId());
		bool run = RunBehaviorTree(Monster->BehaviorTree);
		if (run)
		{
			UE_LOG(LogTemp, Warning, TEXT("Run"));
		}
	}
}

void AMonsterController::OnTargetPerceptionUpdate(AActor* Actor, FAIStimulus Stimulus)
{
	UE_LOG(LogTemp, Warning, TEXT("Targ"));
	ABaseCharacter* BaseCharacter = Cast<ABaseCharacter>(Actor);
	if (!BaseCharacter)
	{
		return;
	}

	if (Stimulus.WasSuccessfullySensed())
	{
		GetBlackboardComponent()->SetValueAsObject(TARGET_BLACKBOARD_KEY, BaseCharacter);
	}
	else
	{
		GetBlackboardComponent()->ClearValue(TARGET_BLACKBOARD_KEY);
	}
}