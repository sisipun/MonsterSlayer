#include "Weapon.h"

#include "Engine/EngineTypes.h"

AWeapon::AWeapon()
{
	PrimaryActorTick.bCanEverTick = false;

	Body = CreateDefaultSubobject<USceneComponent>(TEXT("Body"));
	Body->SetupAttachment(RootComponent);

	Collider = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collider"));
	Collider->SetupAttachment(Body);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Body);

	Mesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
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