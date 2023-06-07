// Fill out your copyright notice in the Description page of Project Settings.


#include "VisitablePlace.h"

AVisitablePlace::AVisitablePlace()
{
	GetStaticMeshComponent()->SetCollisionProfileName("NoCollision");
}

void AVisitablePlace::BeginPlay()
{
	Super::BeginPlay();
}

void AVisitablePlace::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
