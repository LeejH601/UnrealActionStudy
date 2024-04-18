// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class UNREALACTIONSTUDY_API AMyPlayerControllerBase : public APlayerController
{
	GENERATED_BODY()
	
public:
	void AcknowledgePossession(APawn* P);
};
