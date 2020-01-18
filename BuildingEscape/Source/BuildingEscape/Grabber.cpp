// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "DrawDebugHelpers.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	FindPhysicsHandleComponent();
	SetupInputComponent();

	

}
// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	if (!PhysicsHandle) { return; }// if our pointer is null the leave (return)
	//if the physics handle is attached
	if (PhysicsHandle->GrabbedComponent)
	{
		//move the physics object we are holding
		PhysicsHandle->SetTargetLocation(GetReachLineEnd());
	}
		

}

void UGrabber::Grab()
{
	UE_LOG(LogTemp, Error, TEXT("Grab is Pressed!!"));
	///LINE TRACE and see if we reach any actors with physics body collision channel set
	auto HitResult = GetFirstPhysicsBodyInReach();
	auto ComponentToGrab = HitResult.GetComponent();
	auto ActorHit = HitResult.GetActor();

	if (ActorHit) //same as if(ActorHit!=Nullptr)
	{
		if (!PhysicsHandle) { return; }
		//if we hit something then attach a physics handle
		PhysicsHandle->GrabComponent(ComponentToGrab,
			NAME_None, 
			ComponentToGrab->GetOwner()->GetActorLocation(),
			true);//allow rotation

	}

}
void UGrabber::Release()
{
	UE_LOG(LogTemp, Error, TEXT("Grab is Released!!"));

	if (!PhysicsHandle) { return; }
	///release physics handle
	PhysicsHandle->ReleaseComponent();

}
void UGrabber::FindPhysicsHandleComponent()
{
	///Look for Physics Handle
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();

	if (PhysicsHandle==nullptr)
	{
	UE_LOG(LogTemp, Error, TEXT("%s is missing PhysicsHandle Component"), *GetOwner()->GetName());
	}
	
}
void UGrabber::SetupInputComponent()
{
	///Look for attached input component
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();

	if (InputComponent)//InputComponent is found
	{
		//bind input
		InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		InputComponent->BindAction("Grab", IE_Released, this, &UGrabber::Release);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("%s is missing Input Component"), *GetOwner()->GetName());
	}
}

FHitResult UGrabber::GetFirstPhysicsBodyInReach()
{

	///Draw a red trace in the world to visualize
	//DrawDebugLine(GetWorld(), PlayerViewPointLocation, LineTraceEnd, LineColor, false, 0.f, 0.f, 20.f);

	///Setup Query Parameters
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());

	///Ray-cast (aka: LineTrace) out to reach distance
	FHitResult LineTraceHit;

	GetWorld()->LineTraceSingleByObjectType(
		OUT LineTraceHit,
		GetReachLineStart(),
		GetReachLineEnd(),
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),///Objects we care about to trace
		TraceParameters
	);

	///Hit Results (ex: what did we hit)
	AActor* HitActor = LineTraceHit.GetActor();

	if (HitActor)///If Actor exists
	{
		UE_LOG(LogTemp, Warning, TEXT("LineTraceHit: %s"), *HitActor->GetName());
	}
	return LineTraceHit;
}

FVector UGrabber::GetReachLineEnd() const
{
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation, OUT PlayerViewPointRotation);

	return PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;
}

FVector UGrabber::GetReachLineStart() const
{
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation, OUT PlayerViewPointRotation);

	return PlayerViewPointLocation;
}


