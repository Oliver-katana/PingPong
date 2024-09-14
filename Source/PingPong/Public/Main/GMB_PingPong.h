// FaromStudio Test. Coded by Oliver.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GMB_PingPong.generated.h"

class AA_Ball;

UCLASS()
class PINGPONG_API AGMB_PingPong : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AGMB_PingPong();

	UFUNCTION(BlueprintCallable)
	void SpawnBall();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Ball")
	TSubclassOf<AA_Ball> MyBall;

};
