// Copyright Epic Games, Inc. All Rights Reserved.

#include "MPTestGameMode.h"
#include "MPTestCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMPTestGameMode::AMPTestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
