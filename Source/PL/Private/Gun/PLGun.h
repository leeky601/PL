// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PLGun.generated.h"

UCLASS()
class APLGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APLGun();

	UFUNCTION(BlueprintCallable)
	void FireBulletCPP(UClass*BulletClass, FTransform Transform);

	void RegisterNextFireCPP(float Duration);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float BulletSpeedCPP;

};
