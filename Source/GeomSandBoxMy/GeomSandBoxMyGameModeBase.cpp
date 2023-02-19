// Copyright Epic Games, Inc. All Rights Reserved.


#include "GeomSandBoxMyGameModeBase.h"
#include "MySendBoxPawn.h"
#include "SandBoxPlayerController.h"

AGeomSandBoxMyGameModeBase::AGeomSandBoxMyGameModeBase()
{
	DefaultPawnClass = AMySendBoxPawn::StaticClass();
	PlayerControllerClass = ASandBoxPlayerController::StaticClass();
}