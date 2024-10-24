// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SkeletalMeshComponent.h"
#include <Components/SceneCaptureComponent2D.h>
#include <Engine/TextureRenderTarget2D.h>
#include "CharacterRender.generated.h"

UCLASS()
class ACharacterRender : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACharacterRender();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Rendering")
	void SyncCharacterComponents(USkeletalMeshComponent* SourceMesh);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Rendering")
	USceneCaptureComponent2D* CharacterSceneCapture;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Rendering")
	USkeletalMeshComponent* CharacterMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rendering")
	UTextureRenderTarget2D* RenderTarget;

};
