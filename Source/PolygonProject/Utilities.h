#pragma once

#include "CoreMinimal.h"
#include "Utilities.generated.h"

USTRUCT(BlueprintType)
struct FRangedFloat
{
    GENERATED_BODY()
    explicit FRangedFloat(float Min, float Max) : Min(Min), Max(Max) {}
    explicit FRangedFloat(float Max = 1.0f) : Min(0), Max(Max) {}
    
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Min;
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Max;

    bool IsInRange(float x) const;
    float Clamp(float x) const;
    float Rand() const;
};

USTRUCT(BlueprintType)
struct FAttribute 
{
    GENERATED_BODY()
    FAttribute(float Max = 100.0f) : Current(Max), Range(Max) {}
    FAttribute(float Current, float Max) : Current(Current), Range(Max) {}
    FAttribute(float Current, float Min, float Max) : Current(Current), Range(Min, Max)  {}
    FAttribute(float Current, const FRangedFloat& Range) : Current(Current), Range(Range) {}

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Current;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FRangedFloat Range;


    FORCEINLINE operator float () const       { return Current; } 
    FORCEINLINE void operator=(float val)     { Current = val; } 
    FORCEINLINE void operator+=(float change) { Current = Range.Clamp(Current + change); }
    FORCEINLINE void operator-=(float change) { Current = Range.Clamp(Current - change); }
    FORCEINLINE void operator/=(float change) { Current = Range.Clamp(Current / change); }
    FORCEINLINE void operator*=(float change) { Current = Range.Clamp(Current * change); }
};