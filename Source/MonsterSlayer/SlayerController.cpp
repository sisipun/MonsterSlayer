#include "SlayerController.h"

#include "BaseCharacter.h"

ASlayerController::ASlayerController()
{
	PrimaryActorTick.bCanEverTick = true;
}

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
	ABaseCharacter* ControlledCharacter = Cast<ABaseCharacter>(GetPawn());
	if (ControlledCharacter && !ControlledCharacter->IsMovementBlock())
	{
		FRotator YawRotation = FRotator(0.0f, GetControlRotation().Yaw, 0.0f);

		ControlledCharacter->AddMovementInput(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X), Scale);
	}
}

void ASlayerController::MoveRight(float Scale)
{
	ABaseCharacter* ControlledCharacter = Cast<ABaseCharacter>(GetPawn());
	if (ControlledCharacter && !ControlledCharacter->IsMovementBlock())
	{
		FRotator YawRotation = FRotator(0.0f, GetControlRotation().Yaw, 0.0f);

		ControlledCharacter->AddMovementInput(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y), Scale);
	}
}