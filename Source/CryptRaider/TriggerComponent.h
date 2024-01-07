// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Mover.h"
#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "TriggerComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRYPTRAIDER_API UTriggerComponent : public UBoxComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	FName	UnlockTag;
	UMover*	Mover;

protected:
	virtual void	BeginPlay() override;

public:
	UTriggerComponent();
	virtual void	TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	AActor*			GetAcceptableActor() const;
	UFUNCTION(BlueprintCallable)
	void			SetMover(UMover* NewMover);
};
