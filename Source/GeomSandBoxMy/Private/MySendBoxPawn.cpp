// Fill out your copyright notice in the Description page of Project Settings.


#include "MySendBoxPawn.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogMySandBoxPawn, All, All)	

// Sets default values
AMySendBoxPawn::AMySendBoxPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	SetRootComponent(SceneComponent);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	StaticMeshComponent->SetupAttachment(SceneComponent);
	

	CameraComponent = CreateDefaultSubobject <UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(GetRootComponent());


}

// Called when the game starts or when spawned
void AMySendBoxPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMySendBoxPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!VelocityVector.IsZero())
	{
		const FVector NewLocation = GetActorLocation() + Velocity * DeltaTime * VelocityVector;
		SetActorLocation(NewLocation);
		VelocityVector = FVector::ZeroVector;
	}

}

// Called to bind functionality to input
void AMySendBoxPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (!PlayerInputComponent) return;

	PlayerInputComponent->BindAxis("MoveForward", this, &AMySendBoxPawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMySendBoxPawn::MoveRight);

}

void AMySendBoxPawn::MoveForward(float Amount)
{
	//UE_LOG(LogMySandBoxPawn, Display, TEXT("Move Forward %f"), Amount);
	VelocityVector.X = Amount;
}

void AMySendBoxPawn::MoveRight(float Amount)
{
	// UE_LOG(LogMySandBoxPawn, Display, TEXT("Move Right %f"), Amount);
	VelocityVector.Y = Amount;
}

void AMySendBoxPawn::PossessedBy(AController * NewController)
{
	Super::PossessedBy(NewController);
	if (!NewController) return;

	UE_LOG(LogMySandBoxPawn, Error, TEXT("%s PossessedBy %s"), *GetName(), *NewController->GetName());
}

void AMySendBoxPawn::UnPossessed()
{
	Super::UnPossessed();

	UE_LOG(LogMySandBoxPawn, Error, TEXT("%s UnPossessed"), *GetName());
}