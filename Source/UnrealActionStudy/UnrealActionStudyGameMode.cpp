// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealActionStudyGameMode.h"
#include "UnrealActionStudyCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUnrealActionStudyGameMode::AUnrealActionStudyGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
