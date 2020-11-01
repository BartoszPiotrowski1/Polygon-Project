// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FSMState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FActionDelegate);
DECLARE_DYNAMIC_DELEGATE(FBoolActionDelegate);


/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class POLYGONPROJECT_API UFSMState : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnEnter();

	UFUNCTION(BlueprintImplementableEvent)
	void OnEnd();
	
	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdate();
	
	UFUNCTION(BlueprintImplementableEvent)
	float GetUtility();

	UFUNCTION(BlueprintImplementableEvent)
	UFSMState* GetNextState();

	UFUNCTION(BlueprintImplementableEvent)
	bool ShallReturn();

	UFUNCTION(BlueprintImplementableEvent)
	bool CanEnter();

	UFUNCTION(BlueprintImplementableEvent)
	bool CanTransitionToSelf();
	
};
