// Fill out your copyright notice in the Description page of Project Settings.


#include "PolyShipPlayer.h"
#include "ShipCommonIncludes.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

APolyShipPlayer::APolyShipPlayer()
{
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm0"));
    SpringArm->SetupAttachment(RootComponent);
    SpringArm->TargetArmLength = 260.0f;
    SpringArm->SocketOffset = FVector(0.f,0.f,120.f);
    SpringArm->bEnableCameraLag = false;
    SpringArm->CameraLagSpeed = 15.f;

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera0"));
    Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);	// Attach the camera
    Camera->bUsePawnControlRotation = false; // Don't rotate camera with controller
}

void APolyShipPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveUp", this, &APolyShipPlayer::MoveUpInput);
    PlayerInputComponent->BindAxis("MoveRight", this, &APolyShipPlayer::MoveRightInput);
}

void APolyShipPlayer::MoveUpInput(float Val)
{
	PawnMovement->AddInputVector(FVector::ForwardVector * Val);
}

void APolyShipPlayer::MoveRightInput(float Val)
{
    PawnMovement->AddInputVector(FVector::RightVector * Val);
}
