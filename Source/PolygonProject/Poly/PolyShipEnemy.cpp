// Fill out your copyright notice in the Description page of Project Settings.


#include "PolyShipEnemy.h"

#include "GameFramework/FloatingPawnMovement.h"
#include "Kismet/GameplayStatics.h"

APolyShipEnemy::APolyShipEnemy()
{
    // Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

void APolyShipEnemy::BeginPlay()
{
    Super::BeginPlay();
    FTimerHandle handle;
    GetWorldTimerManager().SetTimer(handle, [this]()
    {
        /*if(GEngine)
        {
            //FString string = FString::SanitizeFloat(inputAngle);
            GEngine->AddOnScreenDebugMessage(-1,1, FColor::Orange, "Init" );
        }*/
        
        MoveTo(GetActorLocation() + FVector(FMath::RandPointInCircle(RandomRadius.Rand()),0) );
        
    }, 2.75, true, 0.25);
    
    MoveTo(GetActorLocation() + FVector::ForwardVector * 2000);
}

void APolyShipEnemy::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    FVector ToDestination = DesiredMovementPosition - GetActorLocation();
    ToDestination.Z = 0;

    if(ToDestination.SizeSquared() > CloseDistance * CloseDistance)
        PawnMovement->AddInputVector( ToDestination.GetSafeNormal());

    NewObject<AActor>(GetWorld());
    		
    /*if(GEngine)
    {
        //FString string = FString::SanitizeFloat(inputAngle);
        GEngine->AddOnScreenDebugMessage(-1,1, FColor::Orange, ToDestination.ToString() );
    }*/
}

void APolyShipEnemy::MoveTo(FVector WorldPosition)
{
    DesiredMovementPosition = WorldPosition;
}
