// Copyright Epic Games, Inc. All Rights Reserved.

#include "PolygonProjectGameMode.h"
#include "PolygonProjectPawn.h"

APolygonProjectGameMode::APolygonProjectGameMode()
{
	// set default pawn class to our flying pawn
	DefaultPawnClass = APolygonProjectPawn::StaticClass();
}
