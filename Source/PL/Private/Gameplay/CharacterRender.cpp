// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/CharacterRender.h"

// Sets default values
ACharacterRender::ACharacterRender()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    CharacterSceneCapture = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("CharacterSceneCapture"));
    RootComponent = CharacterSceneCapture;

    CharacterMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh"));
    CharacterMesh->SetupAttachment(RootComponent);

    static ConstructorHelpers::FObjectFinder<UTextureRenderTarget2D> RenderTargetAsset(TEXT("/Game/Play/Game/RenderTarget2D"));
    if (RenderTargetAsset.Succeeded())
    {
        RenderTarget = RenderTargetAsset.Object;
        CharacterSceneCapture->TextureTarget = RenderTarget;
    }

}

// Called when the game starts or when spawned
void ACharacterRender::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharacterRender::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACharacterRender::SyncCharacterComponents(USkeletalMeshComponent* SourceMesh)
{
    if (SourceMesh && CharacterMesh)
    {
        CharacterMesh->SetSkeletalMesh(SourceMesh->SkeletalMesh);
        CharacterMesh->SetAnimInstanceClass(SourceMesh->GetAnimClass());
    }
}

