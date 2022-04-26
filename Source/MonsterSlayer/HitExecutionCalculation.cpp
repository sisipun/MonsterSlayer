#include "HitExecutionCalculation.h"
#include "CharacterAttributeSet.h"
#include "BaseCharacter.h"

struct HitExecutionCapture
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(Health);
	DECLARE_ATTRIBUTE_CAPTUREDEF(AttackPower);

	HitExecutionCapture()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UCharacterAttributeSet, Health, Target, true);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UCharacterAttributeSet, AttackPower, Source, true);
	}
};

static HitExecutionCapture& GetHitExecutionCapture()
{
	static HitExecutionCapture Capture;
	return Capture;
}

UHitExecutionCalculation::UHitExecutionCalculation()
{
	RelevantAttributesToCapture.Add(GetHitExecutionCapture().HealthDef);
	RelevantAttributesToCapture.Add(GetHitExecutionCapture().AttackPowerDef);
}

void UHitExecutionCalculation::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& Params, FGameplayEffectCustomExecutionOutput& Output) const
{
	float HealthMagnitude = 0.0f;
	float AttackPowerMagnitude = 0.0f;

	Params.AttemptCalculateCapturedAttributeMagnitude(GetHitExecutionCapture().HealthDef, FAggregatorEvaluateParameters(), HealthMagnitude);
	Params.AttemptCalculateCapturedAttributeMagnitude(GetHitExecutionCapture().AttackPowerDef, FAggregatorEvaluateParameters(), AttackPowerMagnitude);

	if (Params.GetSourceAbilitySystemComponent())
	{
		ABaseCharacter* BaseCharacter = Cast<ABaseCharacter>(Params.GetSourceAbilitySystemComponent()->AvatarActor);
		if (IsValid(BaseCharacter->CurrentWeapon))
		{
			AttackPowerMagnitude += BaseCharacter->CurrentWeapon->Power;
		}
	}

	HealthMagnitude -= AttackPowerMagnitude;

	Output.AddOutputModifier(FGameplayModifierEvaluatedData(GetHitExecutionCapture().HealthProperty, EGameplayModOp::Override, HealthMagnitude));
}