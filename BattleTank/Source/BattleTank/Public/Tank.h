// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"// Must be first
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"// #include "xxxxx.generated.h" Must be last (xxxxx is the name of the header file itself)


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

private:

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 StartingtHealth = 100;

	UPROPERTY(VisibleAnywhere, Category = "Health")
	int32 CurrentHealth;//Initialized in BeginPlay
public:
	ATank();
	//called by the engine when actor damage is dealt !!
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
	
	//return current health as a percentage of starting health (0-1)
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthPercent() const;

	FTankDelegate OnDeath;
};
