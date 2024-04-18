// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AbilitySystemInterface.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerAttributeSet.h"
#include "MyCharacter.generated.h"

UCLASS()
class UNREALACTIONSTUDY_API AMyCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual void PossessedBy(AController* newContoroller) override;
	virtual void OnRep_PlayerState() override;
	virtual void InitializeAttributes();
	virtual void GiveDefaultAbilities();

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities")
		UAbilitySystemComponent* m_AbilitySystemComponent;

	UPROPERTY()
		UPlayerAttributeSet* m_Attributes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
		float MaxHealth = 100;

public:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Abilities")
		TSubclassOf<class UGameplayEffect> m_DefaultAttributeEffect;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Abilities")
		TArray<TSubclassOf<class UGameplayAbility>> m_DefaultAbilites;
};
