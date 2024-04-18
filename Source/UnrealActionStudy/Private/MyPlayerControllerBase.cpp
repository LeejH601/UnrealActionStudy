// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerControllerBase.h"
#include "MyCharacter.h"
#include "AbilitySystemComponent.h"

void AMyPlayerControllerBase::AcknowledgePossession(APawn* P)
{
    Super::AcknowledgePossession(P);
    AMyCharacter* CharacterBase = Cast<AMyCharacter>(P);

    if (CharacterBase)
    {
        CharacterBase->GetAbilitySystemComponent()->InitAbilityActorInfo(CharacterBase, CharacterBase);
    }
}
