// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Grabber.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRYPTRAIDER_API UGrabber : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	float	MaxGrabDistance = 400;

	UPROPERTY(EditAnywhere)
	float	GrabRadius = 100;

	UPROPERTY(EditAnywhere)
	float	HoldDistance = 200;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPhysicsHandleComponent* GetPhysicsHandle() const;

	UFUNCTION(BlueprintCallable)
	void	Grab();
	UFUNCTION(BlueprintCallable)
	void	Release();

	bool	GetGrabbableInReach(FHitResult& OutHitResult) const;
};
