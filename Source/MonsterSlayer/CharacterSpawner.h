#pragma once

#include "CoreMinimal.h"

#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"

#include "BaseCharacter.h"

#include "CharacterSpawner.generated.h"

UCLASS()
class MONSTERSLAYER_API ACharacterSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	ACharacterSpawner();

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Body")
		UBoxComponent* SpawnArea;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawn")
		int MaxCharactersCount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawn")
		TSubclassOf<ABaseCharacter> CharacterType;

public:	
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	void Spawn();

private:
	TArray<ABaseCharacter*> Characters;
};
