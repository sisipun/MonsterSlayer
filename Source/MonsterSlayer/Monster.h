#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Character.h"

#include "BaseCharacter.h"

#include "Monster.generated.h"

UCLASS()
class MONSTERSLAYER_API AMonster : public ABaseCharacter
{
	GENERATED_BODY()

public:
	AMonster();

	virtual void Hit(float Power) override;
};
