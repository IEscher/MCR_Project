
#include "ControllableCharacter.h"

bool AControllableCharacter::IsFirstOfChain()
{
	return bIsFirstOfChain;
}

void AControllableCharacter::ArrivedToPlace(UMiningRequest* Request, AVisitablePlace* Place, bool bIsSuccessful)
{
	// For linking purposes
}

// Sets default values
AControllableCharacter::AControllableCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AControllableCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AControllableCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AControllableCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}