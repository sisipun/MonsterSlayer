#include "MonsterController.h"

#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"

#include "Monster.h"

void AMonsterController::BeginPlay()
{
	Super::BeginPlay();

	AMonster* Monster = Cast<AMonster>(GetPawn());
	if (Monster)
	{
		APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		if (PlayerPawn) 
		{
			MoveToActor(PlayerPawn);
		}
	}
}