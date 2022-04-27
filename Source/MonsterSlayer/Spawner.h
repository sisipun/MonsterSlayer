// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Spawner.generated.h"

UCLASS()
class MONSTERSLAYER_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Body")
		UBoxComponent* Area;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawn")
		int MaxCount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawn")
		TSubclassOf<AActor> Type;

public:
	ASpawner();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	void Spawn();

private:
	TArray<AActor*> SpawnedActors;
};
