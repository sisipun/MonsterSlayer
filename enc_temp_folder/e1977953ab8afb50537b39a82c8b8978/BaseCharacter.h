#pragma once

#include "CoreMinimal.h"

#include "AbilitySystemInterface.h"
#include "Animation/AnimMontage.h"
#include "GameFramework/Character.h"

#include "Weapon.h"
#include "CharacterAbilitySystemComponent.h"
#include "CharacterAttributeSet.h"
#include "CharacterGameplayAbility.h"

#include "BaseCharacter.generated.h"

UCLASS(Abstract)
class MONSTERSLAYER_API ABaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "State")
		bool IsDead() const;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "State")
		bool IsMovementBlock() const;

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
		void ChangeWeapon(int index);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Attack")
		void BeginPunch();

public:
	UPROPERTY(BlueprintReadWrite, Category = "Weapon")
		AWeapon* CurrentWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
		TArray<TSubclassOf<AWeapon>> Weapons;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Ability")
		UCharacterAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY()
		UCharacterAttributeSet* Attributes;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability")
		TArray<TSubclassOf<UCharacterGameplayAbility>> Abilities;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability")
		TArray<TSubclassOf<UGameplayEffect>> PassiveEffects;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability")
		TArray<FGameplayTagContainer> MovementBlockTags;
public:
	ABaseCharacter();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual void PossessedBy(AController* OwnerController) override;

	virtual void BeginPlay() override;

	virtual void Destroyed() override;

private:
	void InitializeAbilities();

private:
	static FName WEAPON_SOCKET_NAME;
};
