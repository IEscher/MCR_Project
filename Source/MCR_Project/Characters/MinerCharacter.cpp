// Fill out your copyright notice in the Description page of Project Settings.


#include "MinerCharacter.h"

#include "AIController.h"
#include "MCR_Project/MineGameMode.h"

// Sets default values
AMinerCharacter::AMinerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Handler = NewObject<UMinerHandler>();
	Handler = CreateDefaultSubobject<UMinerHandler>(TEXT("Haandler"));
}

// Called when the game starts or when spawned
void AMinerCharacter::BeginPlay()
{
	Super::BeginPlay();
	EquipTool();

	InstantiateCOR();
	// TObjectPtr<ATool> siejfn = GetWorld()->SpawnActor<ToolComponent->StaticClass()>();

	// HandleBlock();
	
	// if (Handler && bIsFirstOfChain)
	// {
	// 	AMineGameMode* GameMode = Cast<AMineGameMode>(GetWorld()->GetAuthGameMode());
	// 	if (GameMode)
	// 	{
	// 		TObjectPtr<UMiningRequest> Request = GameMode->FckOffGiveMeAMiningRequest(GetActorLocation());
	// 		// Give the Request
	// 		if (!Request || !Request->GetBlock())
	// 		{
	// 			UE_LOG(LogTemp, Warning, TEXT("Miner Character: GM gave me a shitty request"));
	// 			return;
	// 		}
	// 		Handler->UMinerHandler::Handle(Request);
	// 	}
	// }
}

// void AMinerCharacter::GoToBlock(UMiningRequest* Request)
// {
// 	if (!Request) return;
// 	
// 	AMineGameMode* GameMode = Cast<AMineGameMode>(GetWorld()->GetAuthGameMode());
// 	if (GameMode)
// 	{
// 		GoToBlockFromRequest(Request);
// 	}
// }

void AMinerCharacter::ArrivedToPlace(UMiningRequest* Request, AVisitablePlace* Place, bool bIsSuccessful)
{
	Super::ArrivedToPlace(Request, Place, bIsSuccessful);
	UE_LOG(LogTemp, Warning, TEXT("AMinerCharacter arrived to place"));

	if(!Request)
	{
		UE_LOG(LogTemp, Warning, TEXT("AMinerCharacter: Request disapeard"));
		AMineGameMode* GameMode = Cast<AMineGameMode>(GetWorld()->GetAuthGameMode());
		if (GameMode)
		{
			GameMode->GiveNextBlock();
		}
		return;
	}
	if(!Place || !bIsSuccessful) // If not able to reach the place
	{
		Handler->ForwardRequest(Request);
		return;
	}

	ABlock* Block = Cast<ABlock>(Place);
	ATool* Tool = GetToolActor();
	if (!Block || !Tool) return;

	if(Block->bCouldMine(*Tool))
	{
		Block->Mine(*Tool);
		GoBakToStart();
	}
	else // If not able to mine the block
	{
		Handler->ForwardRequest(Request);
	}

	// TODO Return to OG position
}

ATool* AMinerCharacter::GetToolActor_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("AMinerCharacter: GetToolActor, no implementation found"));
	return nullptr;
}

TObjectPtr<UMinerHandler> AMinerCharacter::GetHandler()
{
	return Handler;
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

void AMinerCharacter::InstantiateCOR()
{
	if (!Handler)
	{
		UE_LOG(LogTemp, Warning, TEXT("AMinerCharacter: No handler found"));
		return;
	}

	if (!Next_HandlerCharacter) return; // End of chain
	if (!Next_HandlerCharacter->GetHandler())
	{
		UE_LOG(LogTemp, Warning, TEXT("AMinerCharacter: Next_HandlerCharacter has no Handler"));
		return;
	}
	Handler->SetNext(Next_HandlerCharacter->GetHandler());
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
