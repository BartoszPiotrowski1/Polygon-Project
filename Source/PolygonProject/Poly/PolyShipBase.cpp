// Fill out your copyright notice in the Description page of Project Settings.


#include "PolyShipBase.h"
#include "ShipCommonIncludes.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
APolyShipBase::APolyShipBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = ShipMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));

	
	
	PawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingMovement"));

	RotationSpeed = 5;
}

float APolyShipBase::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Health -= DamageAmount;
	return DamageAmount;
}

void APolyShipBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); 

	
	FVector lastInputVector = PawnMovement->GetLastInputVector();
	if(!lastInputVector.IsNearlyZero())
	{
		
		LastDesiredRotation  = FQuat::FindBetween(FVector::ForwardVector, lastInputVector.GetSafeNormal()).Rotator();

	}
	

	FRotator newRotation = FMath::RInterpTo(GetActorRotation(),LastDesiredRotation, DeltaTime, RotationSpeed);

	SetActorRotation(newRotation);	
}

