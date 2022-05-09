#include "ExperienceExecutionCalculation.h"

#include "BaseCharacter.h"
#include "CharacterAttributeSet.h"

FGameplayAttributeData NextLevelExperience;

struct HitExecutionCapture
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(Level);
	DECLARE_ATTRIBUTE_CAPTUREDEF(Experience);
	DECLARE_ATTRIBUTE_CAPTUREDEF(NextLevelExperience);

	HitExecutionCapture()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UCharacterAttributeSet, Level, Target, true);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UCharacterAttributeSet, Experience, Target, true);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UCharacterAttributeSet, NextLevelExperience, Target, true);
	}
};

static HitExecutionCapture& GetExperienceExecutionCapture()
{
	static HitExecutionCapture Capture;
	return Capture;
}

UExperienceExecutionCalculation::UExperienceExecutionCalculation()
{
	RelevantAttributesToCapture.Add(GetExperienceExecutionCapture().LevelDef);
	RelevantAttributesToCapture.Add(GetExperienceExecutionCapture().ExperienceDef);
	RelevantAttributesToCapture.Add(GetExperienceExecutionCapture().NextLevelExperienceDef);
}

void UExperienceExecutionCalculation::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& Params, FGameplayEffectCustomExecutionOutput& Output) const
{
	float LevelMagnitude = 0.0f;
	float ExperienceMagnitude = 0.0f;
	float NextLevelExperienceMagnitude = 0.0f;

	Params.AttemptCalculateCapturedAttributeMagnitude(GetExperienceExecutionCapture().LevelDef, FAggregatorEvaluateParameters(), LevelMagnitude);
	Params.AttemptCalculateCapturedAttributeMagnitude(GetExperienceExecutionCapture().ExperienceDef, FAggregatorEvaluateParameters(), ExperienceMagnitude);
	Params.AttemptCalculateCapturedAttributeMagnitude(GetExperienceExecutionCapture().NextLevelExperienceDef, FAggregatorEvaluateParameters(), NextLevelExperienceMagnitude);

	// TODO use value from monster
	ExperienceMagnitude += 50.0f;

	if (ExperienceMagnitude >= NextLevelExperienceMagnitude)
	{
		ExperienceMagnitude -= NextLevelExperienceMagnitude;
		LevelMagnitude++;

		Output.AddOutputModifier(FGameplayModifierEvaluatedData(GetExperienceExecutionCapture().LevelProperty, EGameplayModOp::Override, LevelMagnitude));
	}

	Output.AddOutputModifier(FGameplayModifierEvaluatedData(GetExperienceExecutionCapture().ExperienceProperty, EGameplayModOp::Override, ExperienceMagnitude));
}