// Fill out your copyright notice in the Description page of Project Settings.

#include "Item/Item.h"
#include "Math/UnrealMathUtility.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"

// Sets default values
AItem::AItem() {
  // Set this actor to call Tick() every frame.  You can turn this off to
  // improve performance if you don't need it.
  PrimaryActorTick.bCanEverTick = true;
  ItemMesh =
      CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Item Mesh Component"));
  RootComponent = ItemMesh;

  EmbersEffect = CreateDefaultSubobject<UNiagaraComponent>(TEXT("Embers"));
  EmbersEffect->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void AItem::BeginPlay() { Super::BeginPlay(); }

// Called every frame
void AItem::Tick(float DeltaTime) {
  Super::Tick(DeltaTime);
  //   float RotationRate = 40.f;
  // RotationRate is now declared and set in Item.h, and can be changed from
  // Blueprint
  AddActorWorldRotation(FRotator(0.f, DeltaTime * RotationRate, 0.f));

  RunningTime += DeltaTime;

  //float SineValue = SineAmplitude * FMath::Sin(RunningTime * SineRate);
  float SineValue = BobbingHeight * SineAmplitude * FMath::Sin(RunningTime * SineRate);

  //   AddActorWorldOffset(FVector(0.f, 0.f, SineValue));

  float PerlinValue = 1.f * FMath::PerlinNoise1D(RunningTime);

  AddActorWorldOffset(FVector(0.f, PerlinValue, SineValue));
}
