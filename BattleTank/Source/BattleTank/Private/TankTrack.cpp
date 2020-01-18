// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UTankTrack::BeginPlay()
{
	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);

}

void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	DriveTrack();
	ApplySideWaysForce();

	//reset throttle
	CurrentThrottle = 0;
}

void UTankTrack::ApplySideWaysForce()
{
	// Calculate the slippage speed
	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	//Work-out the required acceleration this frame to correct
	auto DeltaTime = GetWorld()->GetDeltaSeconds();
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector(); //- means the opposite side of where we are slipping
																				 //Calculate and apply sideways for (F = m a)
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2;//divide by 2 because there are 2 tracks
	TankRoot->AddForce(CorrectionForce);
}

void UTankTrack::SetThrottle(float Throttle)
{
	CurrentThrottle = FMath::Clamp<float>(CurrentThrottle + Throttle,-1,1);
}

void UTankTrack::DriveTrack()
{
	//Clamp actual throttle value
	auto ForceApplied = GetForwardVector() * CurrentThrottle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	UPrimitiveComponent* TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
