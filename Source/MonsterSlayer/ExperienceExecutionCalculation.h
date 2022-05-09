#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "ExperienceExecutionCalculation.generated.h"

UCLASS()
class MONSTERSLAYER_API UExperienceExecutionCalculation : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
	
public:
	UExperienceExecutionCalculation();

	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& Params, FGameplayEffectCustomExecutionOutput& Output) const override;

};
