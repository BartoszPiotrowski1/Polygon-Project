// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PolyShipBase.h"
#include "PolyShipEnemy.generated.h"

/**
 * 
 */
UCLASS()
class POLYGONPROJECT_API APolyShipEnemy : public APolyShipBase
{
	GENERATED_BODY()

public:
	APolyShipEnemy();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= AI)
	FRangedFloat RandomRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= AI)
	float CloseDistance = 100;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	void MoveTo(FVector WorldPosition);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= AI)
	class AActor* ActorToFollow;
	
	//TODO walk in random radius
	
	
	//TODO move towards actor passed as a property

private:
	FVector DesiredMovementPosition;
};
