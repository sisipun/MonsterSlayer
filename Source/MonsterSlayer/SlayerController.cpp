#include "SlayerController.h"

#include "BaseCharacter.h"

void ASlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis(TEXT("LookUp"), this, &ASlayerController::AddPitchInput);
	InputComponent->BindAxis(TEXT("LookRight"), this, &ASlayerController::AddYawInput);

	InputComponent->BindAxis(TEXT("MoveForward"), this, &ASlayerController::MoveForward);
	InputComponent->BindAxis(TEXT("MoveRight"), this, &ASlayerController::MoveRight);
}

void ASlayerController::MoveForward(float Scale)
{
	ABaseCharacter* Character = Cast<ABaseCharacter>(GetPawn());
	if (Character && Character->CanUseAbility())
	{
		FRotator YawRotation = FRotator(0.0f, GetControlRotation().Yaw, 0.0f);

		Character->AddMovementInput(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X), Scale);
	}
}

void ASlayerController::MoveRight(float Scale)
{
	ABaseCharacter* Character = Cast<ABaseCharacter>(GetPawn());
	if (Character && Character->CanUseAbility())
	{
		FRotator YawRotation = FRotator(0.0f, GetControlRotation().Yaw, 0.0f);

		Character->AddMovementInput(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y), Scale);
	}
}