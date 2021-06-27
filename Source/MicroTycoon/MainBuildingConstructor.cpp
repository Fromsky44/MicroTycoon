// Fill out your copyright notice in the Description page of Project Settings.


#include "MainBuildingConstructor.h"
#include "Kismet/GameplayStatics.h"
#include "MainPlayerPawn.h"

// Sets default values
AMainBuildingConstructor::AMainBuildingConstructor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CoinsCost = 0;
	ProductionLimit = 0;
	CurrentLimit = 0;
	ConstructionTime = 5.f;
	ProductionCost = 0;
	ProductionTime = 2.f;
}

// Called when the game starts or when spawned
void AMainBuildingConstructor::BeginPlay()
{
	Super::BeginPlay();

	MainPawn = Cast<AMainPlayerPawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
}

// Called every frame
void AMainBuildingConstructor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

