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
	UFUNCTION(BlueprintCallable, Category = "Attack")
		void BeginAttack();

	UFUNCTION(BlueprintCallable, Category = "Attack")
		void EndAttack();

public:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Body")
		USceneComponent* Body;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Body")
		UCapsuleComponent* Collider;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Body")
		UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
		float Power;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
		float AttackDelay;

public:	
	AWeapon();

	virtual void BeginPlay() override;
};
