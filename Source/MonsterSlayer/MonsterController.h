#pragma once

#include "CoreMinimal.h"

#include "AIController.h"

#include "MonsterController.generated.h"

UCLASS()
class MONSTERSLAYER_API AMonsterController : public AAIController
{
	GENERATED_BODY()

protected:
	void BeginPlay() override;
};