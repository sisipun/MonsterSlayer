// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Components/SceneComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"

#include "BasePickable.generated.h"

UCLASS()
class MONSTERSLAYER_API ABasePickable : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Body")
		USceneComponent* Body;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Body")
		USphereComponent* Collider;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Body")
		UStaticMeshComponent* Mesh;

public:	
	ABasePickable();

};
