#include "Slayer.h"

#include "Components/InputComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"

FName ASlayer::WEAPON_SOCKET_NAME = TEXT("hand_weapon");

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

void ASlayer::BeginPlay()
{
	Super::BeginPlay();
	Mana = MaxMana;

	if (Weapons.Num() > 0) {
		ChangeWeapon(0);
	}
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
	FRotator Rotation = Controller->GetControlRotation();
	FRotator YawRotation = FRotator(0.0f, Rotation.Yaw, 0.0f);

	AddMovementInput(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X), Scale);
}

void ASlayer::MoveRight(float Scale)
{
	FRotator Rotation = Controller->GetControlRotation();
	FRotator YawRotation = FRotator(0.0f, Rotation.Yaw, 0.0f);

	AddMovementInput(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y), Scale);
}

void ASlayer::ChangeWeapon(int index)
{
	if (CurrentWeapon)
	{
		CurrentWeapon->Destroy();
	}

	FTransform SocketTransform = GetMesh()->GetSocketTransform(ASlayer::WEAPON_SOCKET_NAME);
	FActorSpawnParameters SpawnParams = FActorSpawnParameters();
	SpawnParams.Instigator = this;
	AActor* Weapon = GetWorld()->SpawnActor(Weapons[index], &SocketTransform, SpawnParams);
	CurrentWeapon = Cast<AWeapon>(Weapon);
	CurrentWeapon->AttachToComponent(
		GetMesh(),
		FAttachmentTransformRules(
			EAttachmentRule::SnapToTarget,
			EAttachmentRule::SnapToTarget,
			EAttachmentRule::KeepWorld,
			true
		),
		ASlayer::WEAPON_SOCKET_NAME
	);
}