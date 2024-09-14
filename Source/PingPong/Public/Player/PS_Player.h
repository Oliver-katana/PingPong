// FaromStudio Test. Coded by Oliver.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "PS_Player.generated.h"

UCLASS()
class PINGPONG_API APS_Player : public APlayerState
{
	GENERATED_BODY()
	
public:
	UFUNCTION(Server, Reliable, BlueprintCallable)
	void UpdateScore_Server(const int& Score1, const int& Score2);

	UFUNCTION(Client, Reliable, BlueprintCallable)
	void UpdateScore_Client(const int& Score1, const int& Score2);

	UFUNCTION(BlueprintCallable)
	void SetScore(const int& Score1, const int& Score2);
};
