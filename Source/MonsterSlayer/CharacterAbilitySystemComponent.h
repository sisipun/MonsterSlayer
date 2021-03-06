#pragma once

#include "CoreMinimal.h"

#include "AbilitySystemComponent.h"
#include "CharacterGameplayAbility.h"

#include "CharacterAbilitySystemComponent.generated.h"

UCLASS()
class MONSTERSLAYER_API UCharacterAbilitySystemComponent final : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	UCharacterAbilitySystemComponent();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	TArray<UCharacterGameplayAbility*> GetActiveAbilitiesWithTags(const TArray<FGameplayTagContainer>& Tags) const;
};
