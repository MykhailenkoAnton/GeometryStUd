// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "BaseGeometryActor.generated.h"

UENUM(BlueprintType)
enum class EMovementType : uint8
{
	Sin,
	Static
};

USTRUCT(BlueprintType)
struct FGeometryData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "Movement")
		float Amplitude = 50.0f;

	UPROPERTY(EditAnywhere, Category = "Movement")
		float Freequency = 2.0f;

	UPROPERTY(EditAnywhere, Category = "Movement")
		EMovementType MoveType = EMovementType::Static;
};

UCLASS()
class GEOMSANDBOXMY_API ABaseGeometryActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseGeometryActor();

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* BaseMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Weapon")
	int32 WeaponsNum = 4;

	UPROPERTY(EditDefaultsOnly, Category = "Stat")
	int32 KillNum = 3;

	UPROPERTY(EditInstanceOnly, Category = "Health")
	float Health = 43.3123;

	UPROPERTY(EditAnywhere, Category = "Health")
	bool isDead = false;

	UPROPERTY(VisibleAnywhere, Category = "Weapon")
	bool hasWeapon = true;

	UPROPERTY(EditAnywhere, Category = "GeometryData")
	FGeometryData GeometryData;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void printTypes();
	void printStringTypes();
	void printTransform();

	void HandleMovement();

	FVector InitalLocation;
};
