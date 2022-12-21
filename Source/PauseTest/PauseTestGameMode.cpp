// Copyright Epic Games, Inc. All Rights Reserved.

#include "PauseTestGameMode.h"
#include "PauseTestCharacter.h"
#include "UObject/ConstructorHelpers.h"

APauseTestGameMode::APauseTestGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
