#include "Spawner.h"

#include "GameFramework/Character.h"
#include "Kismet/KismetMathLibrary.h"

ASpawner::ASpawner()
{
	PrimaryActorTick.bCanEverTick = true;

	Area = CreateDefaultSubobject<UBoxComponent>(TEXT("Area"));
}

void ASpawner::BeginPlay()
{
	Super::BeginPlay();

}

void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (int i = 0; i < SpawnedActors.Num(); i++) {
		AActor* Actor = SpawnedActors[i];
		if (!IsValid(Actor))
		{
			SpawnedActors.RemoveAt(i);
			i--;
		}
	}

	for (int i = SpawnedActors.Num(); i < MaxCount; i++)
	{
		Spawn();
	}
}

void ASpawner::Spawn()
{
	FVector SpawnPosition = UKismetMathLibrary::RandomPointInBoundingBox(GetActorLocation(), Area->GetScaledBoxExtent());
	FTransform SpawnTransform(SpawnPosition);
	FActorSpawnParameters SpawnParams = FActorSpawnParameters();
	AActor* Actor = Cast<AActor>(GetWorld()->SpawnActor(Type, &SpawnTransform, SpawnParams));
	ACharacter* Character = Cast<ACharacter>(Actor);
	if (Character)
	{
		Character->SpawnDefaultController();
	}
	SpawnedActors.Add(Actor);
}

