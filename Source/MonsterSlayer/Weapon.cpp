#include "Weapon.h"

#include "Engine/EngineTypes.h"

AWeapon::AWeapon()
{
	PrimaryActorTick.bCanEverTick = false;

	Body = CreateDefaultSubobject<USceneComponent>(TEXT("Body"));
	Body->SetupAttachment(RootComponent);

	Collider = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collider"));
	Collider->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
	Collider->SetupAttachment(Body);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	Mesh->SetupAttachment(Body);
}

void AWeapon::BeginPlay()
{
	Collider->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AWeapon::BeginAttack()
{
	Collider->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
}

void AWeapon::EndAttack()
{
	Collider->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}