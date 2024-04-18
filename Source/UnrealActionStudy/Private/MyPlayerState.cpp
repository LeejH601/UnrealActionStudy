// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerState.h"
#include "AbilitySystemComponent.h"

AMyPlayerState::AMyPlayerState()
{
	m_AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>
		(TEXT("AbilitySystemComponent"));
	m_AbilitySystemComponent->SetIsReplicated(true);
	m_AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	
}

UAbilitySystemComponent* AMyPlayerState::GetAbilitySystemComponent() const
{
	return m_AbilitySystemComponent;
}
