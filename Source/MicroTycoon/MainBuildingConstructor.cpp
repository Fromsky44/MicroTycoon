// Fill out your copyright notice in the Description page of Project Settings.


#include "MainBuildingConstructor.h"

// Sets default values
AMainBuildingConstructor::AMainBuildingConstructor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CoinsCost = 0;
	ProductionLimit = 0;
	CurrentLimit = 0;
	ConstructionTime = 5.f;
}

// Called when the game starts or when spawned
void AMainBuildingConstructor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainBuildingConstructor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

