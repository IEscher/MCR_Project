
#include "Tool.h"

// Sets default values for this component's properties
ATool::ATool()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryActorTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void ATool::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void ATool::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
