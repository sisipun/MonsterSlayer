#pragma once

#include "CoreMinimal.h"

#include "BaseCharacter.h"
#include "BehaviorTree/BehaviorTree.h"
#include "GameFramework/Character.h"

#include "Monster.generated.h"

UCLASS()
class MONSTERSLAYER_API AMonster : public ABaseCharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI")
		UBehaviorTree* BehaviorTree;

public:
	AMonster();

	virtual void Hit(float Power) override;
};
