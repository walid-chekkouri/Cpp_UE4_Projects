// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

//Information Comment:
/**
 * TankTrack is used to set maximum driving force,
 and to apply forces to the tank.
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	

public:
	//Sets a throttle between -1 & +1
	UFUNCTION(BlueprintCallable, Category = Input)
		void SetThrottle(float Throttle);


	//Max force per track, in Newtons
		UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 4000000 * 10;// mass * acceleration (1g) g is real life is about 9.8 m/s2, but we'll take it as 10.

		float CurrentThrottle = 0;

private:
	UTankTrack();
	virtual void BeginPlay() override;

	void ApplySideWaysForce();
	void DriveTrack();

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
