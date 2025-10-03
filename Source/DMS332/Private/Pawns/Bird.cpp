// Fill out your copyright notice in the Description page of Project Settings.

#include "Pawns/Bird.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
ABird::ABird() {
  // Set this pawn to call Tick() every frame.  You can turn this off to improve
  // performance if you don't need it.
  PrimaryActorTick.bCanEverTick = true;
  // this creates the Capsule based on UCapsuleComponent template
  Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
  // and sets it as the root component
  SetRootComponent(Capsule);
  // again, take the pointer from Bird.h and create the skeletal mesh
  BirdMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BirdMesh"));
  // attach it to the Root Component so they all move together
  BirdMesh->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void ABird::BeginPlay() { Super::BeginPlay(); }

// Called every frame
void ABird::Tick(float DeltaTime) { Super::Tick(DeltaTime); }

// Called to bind functionality to input
void ABird::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent) {
  Super::SetupPlayerInputComponent(PlayerInputComponent);
}
