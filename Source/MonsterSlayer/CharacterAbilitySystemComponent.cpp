#include "CharacterAbilitySystemComponent.h"

TArray<UCharacterGameplayAbility*> UCharacterAbilitySystemComponent::GetActiveAbilitiesWithTags(const FGameplayTagContainer& Tags) const
{
	TArray<UCharacterGameplayAbility*> ActiveAbilities;

	TArray<FGameplayAbilitySpec*> AbilitiesSpecs;
	GetActivatableGameplayAbilitySpecsByAllMatchingTags(Tags, AbilitiesSpecs, false);

	for (FGameplayAbilitySpec* Spec : AbilitiesSpecs)
	{
		TArray<UGameplayAbility*> AbilityInstances = Spec->GetAbilityInstances();
		for (UGameplayAbility* ActiveAbility : AbilityInstances)
		{
			ActiveAbilities.Add(Cast<UCharacterGameplayAbility>(ActiveAbility));
		}
	}

	return ActiveAbilities;
}