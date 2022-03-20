#pragma once

#include "CoreMinimal.h"

#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "EngineUtils.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"

#include "Weapon.h"
#include "Monster.h"

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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attack")
		UBoxComponent* AttackCollider;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attack")
		AMonster* AttackTarget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
		AWeapon* CurrentWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
		TArray<TSubclassOf<AWeapon>> Weapons;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "State")
		float Health;

public:
	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void ChangeWeapon(int index);

	UFUNCTION(BlueprintCallable, Category = "Attack")
		void SetAttackTarget(AMonster* Monster);

	UFUNCTION(BlueprintCallable, Category = "Attack")
		void ClearAttackTarget();

	UFUNCTION(BlueprintCallable, Category = "Attack")
		void Attack();

	UFUNCTION(BlueprintCallable, Category = "Attack")
		void FinishAttack();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Attack")
		bool isAttack();

	UFUNCTION(BlueprintCallable, Category = "Hit")
		void Hit(float Power);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "State")
		bool isDead();


public:
	ASlayer();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	void BeginPlay() override;

private:
	void MoveForward(float Scale);

	void MoveRight(float Scale);

private:
	bool bIsAttack;

	static FName WEAPON_SOCKET_NAME;
};
