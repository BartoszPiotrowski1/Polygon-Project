// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FSMState.h"
#include "FiniteStateMachine.generated.h"

class UFSMState;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class POLYGONPROJECT_API UFiniteStateMachine : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFiniteStateMachine();
	
private:
	
	TArray<UFSMState*> States;
	
	UFSMState* CurrentState;
};
