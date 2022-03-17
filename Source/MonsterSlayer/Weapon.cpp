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

