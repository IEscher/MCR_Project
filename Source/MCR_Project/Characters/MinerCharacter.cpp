// Fill out your copyright notice in the Description page of Project Settings.


#include "MinerCharacter.h"

#include "AIController.h"
#include "MCR_Project/MineGameMode.h"

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
	GoToBlock();
}

void AMinerCharacter::GoToBlock()
{
	AMineGameMode* GameMode = Cast<AMineGameMode>(GetWorld()->GetAuthGameMode());
	if (GameMode)
	{
		ABlock* Block = GameMode->FindClosestBlock(GetActorLocation());
		GoToActor(Block);
	}
}

void AMinerCharacter::ArrivedToPlace(AVisitablePlace* Place)
{
	Super::ArrivedToPlace(Place);
	UE_LOG(LogTemp, Warning, TEXT("AMinerCharacter arrived to place"));

	ABlock* Block = Cast<ABlock>(Place);
	ATool* Tool = GetToolActor();
	if (Block && Tool)
	{
		Block->Mine(*Tool);
	}

	GoToBlock();

	// ATool* ToolActor = GetToolActor();
	// if (ToolActor)
	// {
	// 	UE_LOG(LogTemp, Log, TEXT("ToolActor found: %s"), *ToolActor->GetName());
	// }
}

ATool* AMinerCharacter::GetToolActor_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("AMinerCharacter: GetToolActor, no implementation found"));
	return nullptr;
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
