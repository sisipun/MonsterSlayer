#include "Monster.h"

#include "MonsterController.h"

AMonster::AMonster()
{
	PrimaryActorTick.bCanEverTick = false;

	AIControllerClass = AMonsterController::StaticClass();
}

void AMonster::Hit(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	Super::Hit(DamagedActor, Damage, DamageType, InstigatedBy, DamageCauser);
	if (Health <= 0)
	{
		Destroy();
	}
}