#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Slayer.generated.h"

UCLASS()
class MONSTERSLAYER_API ASlayer : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="Camera")
		USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category="Camera")
		UCameraComponent* FollowCamera;

public:
	ASlayer();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
