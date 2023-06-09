// Fill out your copyright notice in the Description page of Project Settings.


#include "ControllableCharacter.h"

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

void AControllableCharacter::ArrivedToPlace(AVisitablePlace* Place)
{
	// UE_LOG(LogTemp, Warning, TEXT("ControllableCharacter arrived to place"));
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

