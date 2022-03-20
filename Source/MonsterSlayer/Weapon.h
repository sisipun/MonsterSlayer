#pragma once

#include "CoreMinimal.h"

#include "Components/SceneComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"

#include "Weapon.generated.h"

UCLASS()
class MONSTERSLAYER_API AWeapon : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Body")
		USceneComponent* Body;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Body")
		UCapsuleComponent* Collider;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Body")
		UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
		float Power;

public:	
	AWeapon();

};
