// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "FocusReporterSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class PAUSETEST_API UFocusReporterSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAppFocusChanged, bool, bAppInFocus);
	
	UPROPERTY(BlueprintAssignable, Category = "App Focus")
		FOnAppFocusChanged OnAppFocusChanged;

protected:
	void OnWindowFocusChanged(bool bIsFocused);
};
