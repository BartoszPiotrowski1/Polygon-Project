// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "../Utilities.h"
#include "PolyShipBase.generated.h"


/*
 * Basic functionallity of player and ai controlled ships
 */
UCLASS()
class POLYGONPROJECT_API APolyShipBase : public APawn
{
	GENERATED_BODY()

protected:
	UPROPERTY(Category = Movement, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowProtectedAccess = "true"))
	class UFloatingPawnMovement* PawnMovement;

	UPROPERTY(Category = Mesh, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowProtectedAccess = "true"))
	class UStaticMeshComponent* ShipMesh;

public:
	APolyShipBase();

	virtual void Tick(float DeltaTime) override;



/////////////// Statistics
	/// Health
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Statistics)
	FAttribute Health;

	UFUNCTION(BlueprintPure, Category = Statistics)
	bool IsDead() const { return Health == Health.Range.Min; }

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) override;

	///
	
	
	//////////////// Movement

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement)
	float RotationSpeed;

private:
	FRotator LastDesiredRotation;	

};
