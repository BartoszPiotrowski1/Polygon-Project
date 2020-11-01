// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PolyShipBase.h"
#include "PolyShipPlayer.generated.h"

/**
 * 
 */
UCLASS()
class POLYGONPROJECT_API APolyShipPlayer : public APolyShipBase
{
	GENERATED_BODY()

protected:

	UPROPERTY(Category = Camera, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowProtectedAccess = "true"))
	class USpringArmComponent* SpringArm;

	UPROPERTY(Category = Camera, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowProtectedAccess = "true"))
	class UCameraComponent* Camera;
	
public:
	APolyShipPlayer();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	
	
//////////////// Movement
	
	/// Input listeners
	void MoveUpInput(float Val);
	void MoveRightInput(float Val);
};
