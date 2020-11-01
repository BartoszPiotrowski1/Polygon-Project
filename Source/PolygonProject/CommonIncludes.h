#pragma once

// ----------------------------------------------------------------------------------------------------------------
// This header is included by all headers in the project so it's a good place to declare common includes
// We include EngineMinimal and the subset of engine headers used by most of our classes
// We don't want to include "Engine.h" as that pulls in too many classes we don't need and slows compile time
// ----------------------------------------------------------------------------------------------------------------


#include "CoreMinimal.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/World.h"

POLYGONPROJECT_API DECLARE_LOG_CATEGORY_EXTERN(LogPoly, Log, All);





