// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SpaceShip.generated.h"

UCLASS()
class POLYGONPROJECT_API ASpaceShip : public APawn
{
	GENERATED_BODY()

	/** StaticMesh component that will be the visuals for our flying pawn */
	UPROPERTY(Category = Mesh, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* ShipMesh;

	UPROPERTY(Category = Camera, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* SpringArm;

	UPROPERTY(Category = Camera, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* Camera;

	UPROPERTY(Category = Movement, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UFloatingPawnMovement* Movement;

	UPROPERTY(Category = Movement, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	float TurnSpeed;
	
	UPROPERTY(Category = Movement, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	float TurnInterpSpeed = 2.0f;

public:
	ASpaceShip();

	
		
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	virtual void BeginPlay() override;



	void MoveUpInput(float Val);

	void MouseXInput(float Val);
	void MouseYInput(float Val);


	FRotator CurrentRotationSpeed;
};
