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
	UFUNCTION(BlueprintGetter, Category = "State")
		bool IsDead() const;

	UFUNCTION(BlueprintGetter, Category = "State")
		bool IsMovementBlock() const;

	UFUNCTION(BlueprintGetter, Category = "State")
		bool IsAttacking() const;

	UFUNCTION(BlueprintGetter, Category = "State")
		float GetMaxHealth() const;

	UFUNCTION(BlueprintGetter, Category = "State")
		float GetHealth() const;

	UFUNCTION(BlueprintGetter, Category = "State")
		float GetMaxMana() const;

	UFUNCTION(BlueprintGetter, Category = "State")
		float GetMana() const;

	UFUNCTION(BlueprintGetter, Category = "State")
		float GetAttackPower() const;

	UFUNCTION(BlueprintGetter, Category = "State")
		float GetLevel() const;

	UFUNCTION(BlueprintGetter, Category = "State")
		float GetExperience() const;

	UFUNCTION(BlueprintGetter, Category = "State")
		float GetNextLevelExperience() const;

	UFUNCTION(BlueprintGetter, Category = "State")
		virtual FGenericTeamId GetGenericTeamId() const override;

	UFUNCTION(BlueprintCallable, Category = "State")
		void ReloadStats();

	UFUNCTION(BlueprintCallable, Category = "Abilitiy")
		bool ActivateAbilitiesWithTags(FGameplayTagContainer AbilityTags);

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void EquipWeapon(TSubclassOf<AWeapon> WeaponType);

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void RemoveCurrentWeapon();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Attack")
		void BeginPunch();

public:
	UPROPERTY(BlueprintReadOnly, Category = "Weapon")
		AWeapon* CurrentWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon")
		TArray<TSubclassOf<AWeapon>> Weapons;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Ability")
		UCharacterAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY(VisibleDefaultsOnly, Category = "Ability")
		UCharacterAttributeSet* Attributes;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability")
		TArray<TSubclassOf<UCharacterGameplayAbility>> Abilities;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability")
		TSubclassOf<UGameplayEffect> LevelEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability")
		TSubclassOf<UGameplayEffect> StatsEffect;

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

private:
	void InitializeAbilities();

	void ApplyEffect(const TSubclassOf<UGameplayEffect>& Effect);

protected:
	FGenericTeamId TeamId;

private:
	static FName WEAPON_SOCKET_NAME;
};
