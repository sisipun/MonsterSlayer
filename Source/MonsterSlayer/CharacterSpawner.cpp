#include "CharacterSpawner.h"
#include "Kismet/KismetMathLibrary.h"

ACharacterSpawner::ACharacterSpawner()
{
	PrimaryActorTick.bCanEverTick = true;

	
}

void ACharacterSpawner::BeginPlay()
{
	Super::BeginPlay();
	Spawn();
}

void ACharacterSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Spawn();
}

void ACharacterSpawner::Spawn() 
{
	for (int i = 0; i < Characters.Num(); i++) {
		ABaseCharacter* Character = Characters[i];
		if (!IsValid(Character))
		{
			Characters.RemoveAt(i);
			i--;
		}
	}

	for (int i = Characters.Num(); i < MaxCharactersCount; i++)
	{
		FVector CharacterPosition = UKismetMathLibrary::RandomPointInBoundingBox(GetActorLocation(), SpawnArea->GetScaledBoxExtent());
		FTransform CharacterTransform(CharacterPosition);
		FActorSpawnParameters SpawnParams = FActorSpawnParameters();
		ABaseCharacter* Character = Cast<ABaseCharacter>(GetWorld()->SpawnActor(CharacterType, &CharacterTransform, SpawnParams));
		Character->SpawnDefaultController();
		Characters.Add(Character);
	}
}