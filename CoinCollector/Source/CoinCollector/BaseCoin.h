// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "BaseCoin.generated.h"

UCLASS()
class COINCOLLECTOR_API ABaseCoin : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseCoin();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FTimerHandle DeathTimerHandle;

	void DeathTimerComplete();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* CoinMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RotationRate;

	UFUNCTION(BlueprintCallable)//To call a C++ function from Blueprints
	void PlayCustomDeath();

	// BlueprintNativeEvent property is used to tell the Blueprint that a given function is optional to create within the Blueprint editor
	UFUNCTION(BlueprintNativeEvent)
	void OnOverlap(AActor* OverlappedActor, AActor* OtherActor);//OverlappedActor will be the coin and OtherActor will be the other actor


	


};
