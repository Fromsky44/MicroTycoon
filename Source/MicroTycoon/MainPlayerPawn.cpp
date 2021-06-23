// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayerPawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
AMainPlayerPawn::AMainPlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	SceneComponent->SetupAttachment(GetRootComponent());
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComponent->SetupAttachment(SceneComponent);

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(StaticMeshComponent);
	CameraBoom->TargetArmLength = 1000.f;
	CameraBoom->bUsePawnControlRotation = true;
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom);
	FollowCamera->bUsePawnControlRotation = false;
}

// Called when the game starts or when spawned
void AMainPlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
	MainPlayerController = Cast<APlayerController>(GetController());
}

// Called every frame
void AMainPlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainPlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MouseX", this, &AMainPlayerPawn::MoveUp);
	PlayerInputComponent->BindAxis("MouseY", this, &AMainPlayerPawn::MoveRight);

}

FVector2D AMainPlayerPawn::GetScreenEdgeMovement()
{
	int32 ViewportSizeX;
	int32 ViewportSizeY;
	MainPlayerController->GetViewportSize(ViewportSizeX, ViewportSizeY);
	float MousePositionX;
	float MousePositionY;
	MainPlayerController->GetMousePosition(MousePositionX, MousePositionY);
	float DeltaXSpeed;
	float DeltaYSpeed;

	if (MousePositionX / ViewportSizeX >= 0.95)
	{
		DeltaXSpeed = 5.f;
	}
	else if (MousePositionX / ViewportSizeX <= 0.05)
	{
		DeltaXSpeed = -5.f;
	}
	else
	{
		DeltaXSpeed = 0.f;
	}

	if (MousePositionY / ViewportSizeY >= 0.95)
	{
		DeltaYSpeed = -5.f;
	}
	else if (MousePositionY / ViewportSizeY <= 0.05)
	{
		DeltaYSpeed = 5.f;
	}
	else
	{
		DeltaYSpeed = 0.f;
	}
	return FVector2D(DeltaXSpeed, DeltaYSpeed);
}

void AMainPlayerPawn::MoveUp(float AxisValue)
{
	AddActorWorldOffset(FVector(GetScreenEdgeMovement().Y, 0.f, 0.f));
}

void AMainPlayerPawn::MoveRight(float AxisValue)
{
	AddActorWorldOffset(FVector(0.f, GetScreenEdgeMovement().X, 0.f));
}