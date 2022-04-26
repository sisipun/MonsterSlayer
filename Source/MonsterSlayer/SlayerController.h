#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SlayerController.generated.h"

UCLASS()
class MONSTERSLAYER_API ASlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void SetupInputComponent() override;

private:
	ASlayerController();

	void MoveForward(float Scale);

	void MoveRight(float Scale);
};
