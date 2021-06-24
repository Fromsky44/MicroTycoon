// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MainBuildingConstructor.generated.h"

UCLASS()
class MICROTYCOON_API AMainBuildingConstructor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMainBuildingConstructor();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	int64 CoinsCost;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	int64 ProductionLimit;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Default")
	int64 CurrentLimit;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	FORCEINLINE int64 GetCoinsCost() { return CoinsCost; }
	FORCEINLINE int64 GetProductionLimit() { return ProductionLimit; }
	FORCEINLINE int64 GetCurrentLimit() { return CurrentLimit; }
	FORCEINLINE void SetCurrentLimit(int64 Limit) { CurrentLimit = Limit; }
};
