// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"//newly added
#include "GameFramework/SpringArmComponent.h"//newly added
#include "Camera/CameraComponent.h"//newly added
#include "BasePlayer.generated.h"

UCLASS()
class COINCOLLECTOR_API ABasePlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/*The name you use here will be the name of the component in the editor.
	In this case, the components will display as Mesh, SpringArm and Camera.*/

	/*-VisibleAnywhere will allow each component to be visible within the editor (including Blueprints).
	-BlueprintReadOnly will allow you to get a reference to the component using Blueprint nodes.However,
	it will not allow you to set the component.It is important for components to be read - only because their variables are pointers.
	You do not want to allow users to set this otherwise they could point to a random location in memory.
	Note that BlueprintReadOnly will still allow you to set variables inside of the component, which is the desired behavior.*/
	//-NOTE:Note: For non - pointer variables(int, float, boolean etc.), use EditAnywhereand BlueprintReadWrite instead.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)//BlueprintReadWrite will allow you to set and read MovementForce using Blueprint nodes.
		float MovementForce;

	void MoveUp(float Value);
	void MoveRight(float Value);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float JumpImpulse;

	//BlueprintImplementableEvent will allow Blueprints to implement Jump().
	//If there is no implementation, any calls to Jump() will do nothing.
	//NB:If you want to provide a default implementation in C++, use BlueprintNativeEvent instead !!
	//NB:An override will be an event if there is no return type. If there is a return type, it will be a function
	UFUNCTION(BlueprintImplementableEvent)
		void Jump();
	

	
	
};
