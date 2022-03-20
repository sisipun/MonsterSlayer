#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Character.h"

#include "Monster.generated.h"

UCLASS()
class MONSTERSLAYER_API AMonster : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "State")
		float Health;

public:
	UFUNCTION(BlueprintCallable, Category = "Hit")
		void Hit(float Power);

	UFUNCTION(BlueprintCallable, Category = "State")
		bool isDead();

public:
	AMonster();

};
