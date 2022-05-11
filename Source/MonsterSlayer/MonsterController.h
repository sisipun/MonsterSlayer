#pragma once

#include "CoreMinimal.h"

#include "AIController.h"
#include "Perception/AIPerceptionComponent.h"

#include "MonsterController.generated.h"

UCLASS()
class MONSTERSLAYER_API AMonsterController : public AAIController
{
	GENERATED_BODY()

public:
	UFUNCTION()
		void OnTargetPerceptionUpdate(AActor* Actor, FAIStimulus Stimulus);

public:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AI")
		UAIPerceptionComponent* AIPerception;

public:
	AMonsterController();

	virtual void OnPossess(APawn* PossessedPawn) override;

protected:
	virtual void BeginPlay() override;

private:
	static FName TARGET_BLACKBOARD_KEY;
};
