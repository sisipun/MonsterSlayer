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
	/** Event when weapon begins attack. */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, meta = (DisplayName = "BeginAttack"))
		void BeginAttack();

	/** Event when weapon ends attack. */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, meta = (DisplayName = "EndAttack"))
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

	UPROPERTY(EditAnywhere, BLueprintReadOnly, Category = "Stats")
		float AttackDelay;

public:	
	AWeapon();

};
