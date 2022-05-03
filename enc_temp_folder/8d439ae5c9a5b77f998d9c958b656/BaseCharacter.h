#pragma once

#include "CoreMinimal.h"

#include "AbilitySystemInterface.h"
#include "Animation/AnimMontage.h"
#include "GameFramework/Character.h"
#include "GenericTeamAgentInterface.h"

#include "Weapon.h"
#include "CharacterAbilitySystemComponent.h"
#include "CharacterAttributeSet.h"
#include "CharacterGameplayAbility.h"

#include "BaseCharacter.generated.h"

UCLASS(Abstract)
class MONSTERSLAYER_API ABaseCharacter : public ACharacter, public IAbilitySystemInterface, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "State")
		bool IsDead() const;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "State")
		bool IsMovementBlock() const;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "State")
		bool IsAttacking() const;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "State")
		float GetMaxHealth() const;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "State")
		float GetHealth() const;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "State")
		float GetMaxMana() const;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "State")
		float GetMana() const;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "State")
		float GetAttackPower() const;

	UFUNCTION(BlueprintCallable, Category = "Abilitiy")
		bool ActivateAbilitiesWithTags(FGameplayTagContainer AbilityTags);

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void EquipWeapon(TSubclassOf<AWeapon> WeaponType);

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void RemoveCurrentWeapon();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Attack")
		void BeginPunch();

public:
	UPROPERTY(BlueprintReadWrite, Category = "Weapon")
		AWeapon* CurrentWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
		TArray<TSubclassOf<AWeapon>> Weapons;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Ability")
		UCharacterAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY(VisibleDefaultsOnly)
		UCharacterAttributeSet* Attributes;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability")
		TArray<TSubclassOf<UCharacterGameplayAbility>> Abilities;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability")
		TArray<TSubclassOf<UGameplayEffect>> PassiveEffects;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability")
		TArray<FGameplayTagContainer> MovementBlockTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability")
		TArray<FGameplayTagContainer> AttackTags;

	UPROPERTY(BlueprintReadWrite, Category = "State")
		bool bAttackComboActivated;

public:
	ABaseCharacter();

	ABaseCharacter(FGenericTeamId TeamId);

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual void PossessedBy(AController* OwnerController) override;

	virtual void BeginPlay() override;

	virtual void Destroyed() override;

	virtual FGenericTeamId GetGenericTeamId() const override;

private:
	void InitializeAbilities();

protected:
	FGenericTeamId TeamId;

private:
	static FName WEAPON_SOCKET_NAME;
};
