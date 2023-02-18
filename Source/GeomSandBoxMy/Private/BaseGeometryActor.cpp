// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGeometryActor.h"
#include "Engine/Engine.h"

DEFINE_LOG_CATEGORY_STATIC(LogBaseGeometry, All, All)

// Sets default values
ABaseGeometryActor::ABaseGeometryActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	SetRootComponent(BaseMesh);

}

// Called when the game starts or when spawned
void ABaseGeometryActor::BeginPlay()
{
	Super::BeginPlay();

	InitalLocation = GetActorLocation();

	//printTransform();
	//printTypes();
	//printStringTypes();
}

// Called every frame
void ABaseGeometryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	 
	HandleMovement();

}

void ABaseGeometryActor::printTypes()
{
	UE_LOG(LogBaseGeometry, Warning, TEXT("Actor Name %s"), *GetName());

	UE_LOG(LogBaseGeometry, Warning, TEXT("WeaponsNum %d, KillNum %i"), WeaponsNum, KillNum);
	UE_LOG(LogBaseGeometry, Warning, TEXT("Healt %f"), Health);
	UE_LOG(LogBaseGeometry, Warning, TEXT("isDead %d"), isDead);
	UE_LOG(LogBaseGeometry, Warning, TEXT("hasWeapon %d"), static_cast<int>(hasWeapon));
}

void ABaseGeometryActor::printStringTypes()
{
	FString Name = "Jonh Conor";
	UE_LOG(LogBaseGeometry, Display, TEXT("Name: %s"), *Name);

	FString WeaponNumStr = "WeaponNumStr = " + FString::FromInt(WeaponsNum);
	FString HealthSTR = "Health = " + FString::SanitizeFloat(Health);
	FString DEAD = "IsDead = " + FString(isDead ? "true" : "false");

	FString stat = FString::Printf(TEXT(" <<<<<< All Stat \n %s \n %s \n%s  >>>>>>"), *WeaponNumStr, *HealthSTR, *DEAD);

	UE_LOG(LogBaseGeometry, Warning, TEXT("%s"), *stat);


	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, Name);
	GEngine->AddOnScreenDebugMessage(-1, 19.0f, FColor::Red, stat, true, FVector2D(1.5f, 1.5f));
}

void ABaseGeometryActor::printTransform()
{
	FTransform Transform = GetActorTransform();

	FVector Location = Transform.GetLocation();
	FRotator Rotation = Transform.Rotator();
	FVector Scale = Transform.GetScale3D();

	UE_LOG(LogBaseGeometry, Warning, TEXT("Actor Name %s"), *GetName());
	UE_LOG(LogBaseGeometry, Warning, TEXT("Transform %s"), *Transform.ToString());
	UE_LOG(LogBaseGeometry, Warning, TEXT("Location %s"), *Location.ToString());
	UE_LOG(LogBaseGeometry, Warning, TEXT("Rotator %s"), *Rotation.ToString());
	UE_LOG(LogBaseGeometry, Warning, TEXT("Scale %s"), *Scale.ToString());

	UE_LOG(LogBaseGeometry, Error, TEXT("Transform %s"), *Transform.ToHumanReadableString());
}

void ABaseGeometryActor::HandleMovement()
{
	switch (GeometryData.MoveType)
	{
		case EMovementType::Sin:
		{
			float time = GetWorld()->GetTimeSeconds();

			FVector CurrentLocation = GetActorLocation();
			CurrentLocation.Z = InitalLocation.Z + GeometryData.Amplitude * FMath::Sin(GeometryData.Freequency * time);

			SetActorLocation(CurrentLocation);
		}
		break;

		case EMovementType::Static:
			break;
		default:
			break;
	}
}