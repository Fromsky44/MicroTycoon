// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MainPlayerPawn.generated.h"

UCLASS()
class MICROTYCOON_API AMainPlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMainPlayerPawn();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default")
	class USceneComponent* SceneComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default")
	class UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	class UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Controller")
	class APlayerController* MainPlayerController;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources")
	int64 CurrentCoins;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources")
	bool bCanMove;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FVector2D GetScreenEdgeMovement();
	void MoveUp(float AxisValue);
	void MoveRight(float AxisValue);

	UFUNCTION(BlueprintCallable) FORCEINLINE
	int64 GetCurrentCoins() { return CurrentCoins; }
	UFUNCTION(BlueprintCallable) FORCEINLINE
	int64 SetCurrentCoins(int64 Coins) { CurrentCoins = Coins; return CurrentCoins; }
	UFUNCTION(BlueprintCallable) FORCEINLINE
	bool SetCanMove(bool bCanCurrentlyMove) { bCanMove = bCanCurrentlyMove; return bCanMove; }

};
