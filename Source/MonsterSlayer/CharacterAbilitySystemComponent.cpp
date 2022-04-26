#include "CharacterAbilitySystemComponent.h"

UCharacterAbilitySystemComponent::UCharacterAbilitySystemComponent()
{
}

TArray<UCharacterGameplayAbility*> UCharacterAbilitySystemComponent::GetActiveAbilitiesWithTags(const TArray<FGameplayTagContainer>& Tags) const
{
	TArray<UCharacterGameplayAbility*> ActiveAbilities;

	for (const FGameplayTagContainer Tag : Tags)
	{
		TArray<FGameplayAbilitySpec*> AbilitiesSpecs;
		GetActivatableGameplayAbilitySpecsByAllMatchingTags(Tag, AbilitiesSpecs, false);

		for (FGameplayAbilitySpec* Spec : AbilitiesSpecs)
		{
			TArray<UGameplayAbility*> AbilityInstances = Spec->GetAbilityInstances();
			for (UGameplayAbility* ActiveAbility : AbilityInstances)
			{
				ActiveAbilities.Add(Cast<UCharacterGameplayAbility>(ActiveAbility));
			}
		}
	}

	return ActiveAbilities;
}