// Fill out your copyright notice in the Description page of Project Settings.


#include "SandBoxPlayerController.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "MySendBoxPawn.h"

DEFINE_LOG_CATEGORY_STATIC(LogSandBoxPlayerContoller, All, All)

void ASandBoxPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	if (InputComponent)
	{
		InputComponent->BindAction("ChangePawn", IE_Pressed, this, &ASandBoxPlayerController::ChangePawn);
	}
}

void ASandBoxPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMySendBoxPawn::StaticClass(), Pawns);
}

void ASandBoxPlayerController::ChangePawn()
{
	if (Pawns.Num() <= 1) return;

	AMySendBoxPawn* CurrentPawn = Cast< AMySendBoxPawn > (Pawns[CurrentPawnIndex]);
	CurrentPawnIndex = (CurrentPawnIndex + 1) % Pawns.Num();

	if (!CurrentPawn) return;

	UE_LOG(LogSandBoxPlayerContoller, Error, TEXT("Change Pawn"));
	Possess(CurrentPawn);
}
