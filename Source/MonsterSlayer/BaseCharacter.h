#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Character.h"

#include "Weapon.h"

#include "BaseCharacter.generated.h"

UCLASS(Abstract)
class MONSTERSLAYER_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Weapon")
		virtual void Attack();

	UFUNCTION(BlueprintCallable, Category = "State")
		virtual void Hit(float Power);

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void ChangeWeapon(int index);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "State")
		virtual bool isDead();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "State")
		virtual bool isAttacking();

public:
	UPROPERTY(BlueprintReadOnly, Category = "State")
		float Health;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "State")
		float MaxHealth;

	UPROPERTY(BlueprintReadOnly, Category = "State")
		float Mana;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "State")
		float MaxMana;

	UPROPERTY(BlueprintReadWrite, Category = "Weapon")
		AWeapon* CurrentWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
		TArray<TSubclassOf<AWeapon>> Weapons;

public:
	ABaseCharacter();

	virtual void BeginPlay() override;

private:
	void OnAttackEnd();

private:
	bool bIsAttacking;

	static FName WEAPON_SOCKET_NAME;
};
