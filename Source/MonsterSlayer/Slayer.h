#pragma once

#include "CoreMinimal.h"

#include "Camera/CameraComponent.h"
#include "EngineUtils.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"

#include "Weapon.h"

#include "Slayer.generated.h"

UCLASS()
class MONSTERSLAYER_API ASlayer : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
		USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
		UCameraComponent* FollowCamera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
		AWeapon* CurrentWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
		TArray<TSubclassOf<AWeapon>> Weapons;

public:
	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void ChangeWeapon(int index);


public:
	ASlayer();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	void BeginPlay() override;

private:
	void MoveForward(float Scale);

	void MoveRight(float Scale);

private:
	static FName WEAPON_SOCKET_NAME;
};
