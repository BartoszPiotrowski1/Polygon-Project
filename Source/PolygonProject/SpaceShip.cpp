// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceShip.h"
#include "CommonIncludes.h"

#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/FloatingPawnMovement.h"

// Sets default values
ASpaceShip::ASpaceShip()
{
	PrimaryActorTick.bCanEverTick = true;
	
	// Structure to hold one-time initialization
	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinderOptional<UStaticMesh> Mesh;
		FConstructorStatics()
            : Mesh(TEXT("/Game/Flying/Meshes/UFO.UFO"))
		{
		}
	};
	static FConstructorStatics ConstructorStatics;

	// Create static mesh component
	ShipMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	ShipMesh->SetStaticMesh(ConstructorStatics.Mesh.Get());
	RootComponent = ShipMesh;

	// Create a spring arm component
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm0"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 260.0f;	
	SpringArm->SocketOffset = FVector(0.f,0.f,120.f);
	SpringArm->bEnableCameraLag = false;
	SpringArm->CameraLagSpeed = 15.f;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera0"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);	// Attach the camera
	Camera->bUsePawnControlRotation = false; // Don't rotate camera with controller

	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingMovement"));
	
}

// Called when the game starts or when spawned
void ASpaceShip::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASpaceShip::MoveUpInput(float Val)
{
	Movement->AddInputVector(GetActorForwardVector() * Val);	
 
	//if(GEngine)
	//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("Some debug message!"));    
}

void ASpaceShip::MouseXInput(float Val)
{
	FRotator targetRotationSpeed;
	
	// Target yaw speed is based on input
	float TargetYawSpeed = (Val * TurnSpeed);

	// Smoothly interpolate to target yaw speed
	CurrentRotationSpeed.Yaw = FMath::FInterpTo(CurrentRotationSpeed.Yaw, TargetYawSpeed, GetWorld()->GetDeltaSeconds(), 2.f);

	// Is there any left/right input?
	const bool bIsTurning = FMath::Abs(Val) > 0.2f;

	// If turning, yaw value is used to influence roll
	// If not turning, roll to reverse current roll value.
	float TargetRollSpeed = bIsTurning ? (CurrentRotationSpeed.Yaw * 0.5f) : (GetActorRotation().Roll * -2.f);

	// Smoothly interpolate roll speed
	CurrentRotationSpeed.Roll = FMath::FInterpTo(CurrentRotationSpeed.Roll, TargetRollSpeed, GetWorld()->GetDeltaSeconds(), TurnInterpSpeed);
}

void ASpaceShip::MouseYInput(float Val)
{
	
	// Target pitch speed is based in input
	float TargetPitchSpeed = (Val * TurnSpeed );

	// When steering, we decrease pitch slightly
	TargetPitchSpeed += (FMath::Abs(CurrentRotationSpeed.Yaw) * 0.2f);

	// Smoothly interpolate to target pitch speed
	CurrentRotationSpeed.Pitch = FMath::FInterpTo(CurrentRotationSpeed.Pitch, TargetPitchSpeed, GetWorld()->GetDeltaSeconds(), TurnInterpSpeed);
}

// Called every frame
void ASpaceShip::Tick(float DeltaTime)
{
	Movement->AddInputVector(FVector::DownVector*0.25f);

	// Calculate change in rotation this frame
	FRotator DeltaRotation = CurrentRotationSpeed * DeltaTime;

	// Rotate plane
	AddActorLocalRotation(DeltaRotation);
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASpaceShip::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	
	PlayerInputComponent->BindAxis("MoveUp", this, &ASpaceShip::MoveUpInput);
	PlayerInputComponent->BindAxis("MouseX", this, &ASpaceShip::MouseXInput);
	PlayerInputComponent->BindAxis("MouseY", this, &ASpaceShip::MouseYInput);
	//if(GEngine)
	//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));    
}

