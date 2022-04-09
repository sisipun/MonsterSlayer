#pragma once

#include "CoreMinimal.h"

#include "Animation/AnimMontage.h"
#include "GameFramework/Character.h"

#include "Weapon.h"

#include "BaseCharacter.generated.h"

UCLASS(Abstract)
class MONSTERSLAYER_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "State")
		virtual void Hit(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "State")
		bool CanUseAbility() const;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "State")
		bool IsDead() const;

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void ChangeWeapon(int index);

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void Attack();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void BeginAttack();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void EndAttack();

public:
	UPROPERTY(BlueprintReadOnly, Category=State)
		float Health;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=State)
		float MaxHealth;

	UPROPERTY(BlueprintReadOnly, Category=State)
		float Mana;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=State)
		float MaxMana;

	UPROPERTY(BlueprintReadWrite, Category=Weapon)
		AWeapon* CurrentWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Weapon)
		TArray<TSubclassOf<AWeapon>> Weapons;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Weapon)
		UAnimMontage* AttackAnimation;

public:
	ABaseCharacter();

	virtual void BeginPlay() override;

	virtual void Destroyed() override;

private:
	bool bIsAttacking;
	int currentWeaponIndex;

	static FName WEAPON_SOCKET_NAME;
};
