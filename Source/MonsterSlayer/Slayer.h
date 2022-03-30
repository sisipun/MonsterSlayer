#pragma once

#include "CoreMinimal.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"

#include "BaseCharacter.h"

#include "Slayer.generated.h"

UCLASS()
class MONSTERSLAYER_API ASlayer : public ABaseCharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Camera")
		USpringArmComponent* SpringArm;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Camera")
		UCameraComponent* FollowCamera;

public:
	ASlayer();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void MoveForward(float Scale);

	void MoveRight(float Scale);
};
