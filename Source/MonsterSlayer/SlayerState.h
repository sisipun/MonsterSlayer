#pragma once

#include "CoreMinimal.h"

#include "GameFramework/PlayerState.h"

#include "SlayerState.generated.h"

UCLASS()
class MONSTERSLAYER_API ASlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, Category = "Score")
		float SlayerScore;

public:
	ASlayerState();
};
