// FaromStudio Test. Coded by Oliver.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "A_Gate.generated.h"

class USoundCue;
class UBoxComponent;

UCLASS()
class PINGPONG_API AA_Gate : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AA_Gate();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BallSounds")
	USoundCue* GoalSound;

	virtual void Tick(float DeltaTime) override;

protected:
	
	virtual void BeginPlay() override;

	UFUNCTION(NetMulticast, Reliable)
	void PlayGoalSound();

private:

	UPROPERTY(EditAnywhere, Category = "BoxCollision")
	UBoxComponent* BoxComponent;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};