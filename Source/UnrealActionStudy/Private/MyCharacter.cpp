// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "AbilitySystemComponent.h"
#include "PlayerAttributeSet.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>
		(TEXT("AbilitySystemComponent"));
	m_AbilitySystemComponent->SetIsReplicated(true);
	m_AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	m_Attributes = CreateDefaultSubobject<UPlayerAttributeSet>("Attributes");

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UAbilitySystemComponent* AMyCharacter::GetAbilitySystemComponent() const
{
	return m_AbilitySystemComponent;
}

void AMyCharacter::PossessedBy(AController* newContoroller)
{
	Super::PossessedBy(newContoroller);

	if (m_AbilitySystemComponent)
	{
		m_AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}

	InitializeAttributes();
	GiveDefaultAbilities();
}

void AMyCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	if (m_AbilitySystemComponent)
	{
		m_AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}

	InitializeAttributes();
}
 
void AMyCharacter::InitializeAttributes()
{
	if (m_AbilitySystemComponent)
	{
		FGameplayEffectContextHandle EffectContext = m_AbilitySystemComponent->MakeEffectContext();
		EffectContext.AddSourceObject(this);
		FGameplayEffectSpecHandle SpecHandle = m_AbilitySystemComponent->MakeOutgoingSpec(m_DefaultAttributeEffect, 1, EffectContext);

		if (SpecHandle.IsValid())
			FActiveGameplayEffectHandle GEHandle = m_AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
	}
}

void AMyCharacter::GiveDefaultAbilities()
{
	if (HasAuthority() && m_AbilitySystemComponent)
	{
		for (TSubclassOf<UGameplayAbility>& StartupAbility : m_DefaultAbilites)
		{
			m_AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(StartupAbility.GetDefaultObject(), 1, 0));
		}
	}
}


