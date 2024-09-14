// FaromStudio Test. Coded by Oliver.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "A_Ball.generated.h"

class USoundCue;
class UProjectileMovementComponent;

UCLASS()
class PINGPONG_API AA_Ball : public AActor
{
	GENERATED_BODY()

public:

	AA_Ball();

	UPROPERTY(EditAnywhere, category = "Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BallSounds")
	USoundCue* HitSound;

	virtual void Tick(float DeltaTime) override;

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "BallMovementComp")
	UProjectileMovementComponent* BallMovementComp;

	virtual void BeginPlay() override;

private:

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION(NetMulticast, Reliable)
	void PlayHitSound();

};
