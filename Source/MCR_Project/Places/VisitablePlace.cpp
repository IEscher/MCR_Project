
#include "VisitablePlace.h"

void AVisitablePlace::BeginPlay()
{
	Super::BeginPlay();
}

void AVisitablePlace::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

AVisitablePlace::AVisitablePlace()
{
	GetStaticMeshComponent()->SetCollisionProfileName("NoCollision");
}
