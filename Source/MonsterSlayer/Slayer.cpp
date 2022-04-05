#include "Slayer.h"

#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"

ASlayer::ASlayer()
{
	PrimaryActorTick.bCanEverTick = false;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->SetupAttachment(RootComponent);

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
}

void ASlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &ASlayer::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &ASlayer::AddControllerYawInput);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ASlayer::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ASlayer::MoveRight);
}

void ASlayer::MoveForward(float Scale)
{
	if (!isDead() && !isAttacking()) 
	{
		FRotator Rotation = Controller->GetControlRotation();
		FRotator YawRotation = FRotator(0.0f, Rotation.Yaw, 0.0f);

		AddMovementInput(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X), Scale);
	}
}

void ASlayer::MoveRight(float Scale)
{
	if (!isDead() && !isAttacking())
	{
		FRotator Rotation = Controller->GetControlRotation();
		FRotator YawRotation = FRotator(0.0f, Rotation.Yaw, 0.0f);

		AddMovementInput(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y), Scale);
	}
}