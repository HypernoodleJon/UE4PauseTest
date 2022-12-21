// Fill out your copyright notice in the Description page of Project Settings.


#include "FocusReporterSubsystem.h"
#include "Framework/Application/SlateApplication.h"

void UFocusReporterSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	FSlateApplication::Get().OnApplicationActivationStateChanged().AddUObject(this, &UFocusReporterSubsystem::OnWindowFocusChanged);
}

void UFocusReporterSubsystem::OnWindowFocusChanged(bool bIsFocused)
{
	OnAppFocusChanged.Broadcast(bIsFocused);
}
