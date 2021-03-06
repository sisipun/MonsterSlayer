#pragma once

#include "CoreMinimal.h"

#include "AttributeSet.h"
#include "AbilitySystemComponent.h"

#include "CharacterAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
 GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
 GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
 GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
 GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class MONSTERSLAYER_API UCharacterAttributeSet final : public UAttributeSet
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes")
		FGameplayAttributeData Health;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes")
		FGameplayAttributeData MaxHealth;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes")
		FGameplayAttributeData Mana;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes")
		FGameplayAttributeData MaxMana;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes")
		FGameplayAttributeData AttackPower;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes")
		FGameplayAttributeData Level;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes")
		FGameplayAttributeData Experience;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes")
		FGameplayAttributeData NextLevelExperience;

public:
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, Health);
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, MaxHealth);
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, Mana);
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, MaxMana);
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, AttackPower);
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, Level);
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, Experience);
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, NextLevelExperience);

public:
	UCharacterAttributeSet();

	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
};
