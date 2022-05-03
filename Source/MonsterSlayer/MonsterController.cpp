#include "MonsterController.h"

#include "BaseCharacter.h"

AMonsterController::AMonsterController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMonsterController::OnPossess(APawn* PossessedPawn)
{
	Super::OnPossess(PossessedPawn);

	ABaseCharacter* BaseCharacter = Cast<ABaseCharacter>(PossessedPawn);
	if (BaseCharacter)
	{
		SetGenericTeamId(BaseCharacter->GetGenericTeamId());
	}
}