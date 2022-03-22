#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Character.h"

#include "BaseCharacter.generated.h"

UCLASS(Abstract)
class MONSTERSLAYER_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "State")
		float Health;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "State")
		float MaxHealth;

public:
	UFUNCTION(BlueprintCallable, Category = "State")
		virtual void Hit(float Power);

	UFUNCTION(BlueprintCallable, Category = "State")
		virtual bool isDead();

public:
	ABaseCharacter();

protected:
	virtual void BeginPlay() override;

};
