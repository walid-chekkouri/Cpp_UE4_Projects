// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Kismet/GameplayStatics.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

//Enum For Aiming State
UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked,
	OutOfAmmo
};

//make sure the type exists
class UTankBarrel;//Holds Barrel's Properties & Elevate Method
class UTankTurret;
class AProjectile;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel* Barrel, UTankTurret* Turret); 

	void AimAt(FVector HitLocation);
	EFiringState GetFiringState() const;

	UFUNCTION(BlueprintCallable, Category = "Firing")
	int32 GetRoundsLeft() const;

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

protected:
	UPROPERTY(BlueprintReadOnly, Category="State")
	EFiringState FiringState = EFiringState::Reloading;

private:	
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void MoveBarrelTowards(FVector AimDirection);
	bool IsBarrelMoving();

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;//This way we specify the type of Class
		//Alternative is: UClass* ProjectileBlueprint; //but without a type filter.

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float LaunchSpeed = 100000; //Sensible starting value of 1000 m/s

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float ReloadTimeInSeconds = 3;//!!EditDefaultOnly: the value can be changed inside the blueprint only not the instanced objects in the world.

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		int32 RoundsLeft = 3;
	
	double LastFireTime = 0;
	FVector AimDirection;

	

};
