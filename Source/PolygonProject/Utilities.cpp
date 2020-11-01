#include "Utilities.h"

#include "CommonIncludes.h"

bool FRangedFloat::IsInRange(float x) const
{
    return FMath::IsWithin(x, Min, Max);
}

float FRangedFloat::Clamp(float x) const
{
    return FMath::Clamp(x, Min, Max);
}

float FRangedFloat::Rand() const
{
    return FMath::RandRange(Min, Max);
}
