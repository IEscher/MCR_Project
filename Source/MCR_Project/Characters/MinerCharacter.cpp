// Fill out your copyright notice in the Description page of Project Settings.


#include "MinerCharacter.h"

// Sets default values
AMinerCharacter::AMinerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMinerCharacter::BeginPlay()
{
	Super::BeginPlay();
	EquipTool();
}

// Called every frame
void AMinerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMinerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMinerCharacter::SetTool(TSubclassOf<ATool> Tool)
{
	UnEquipTool();
	ToolComponent = Tool;
	EquipTool();
}

TSubclassOf<ATool> AMinerCharacter::GetTool() const
{
	return ToolComponent;
}

