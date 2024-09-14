// FaromStudio Test. Coded by Oliver.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "GSB_PingPong.generated.h"

UCLASS()
class PINGPONG_API AGSB_PingPong : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(ReplicatedUsing = PlayerScoreChanged, BlueprintReadOnly)
	int32 Player1Score;

	UPROPERTY(ReplicatedUsing = PlayerScoreChanged, BlueprintReadOnly)
	int32 Player2Score;

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty, FDefaultAllocator>& OutLifetimeProps) const;

	UFUNCTION()
	void PlayerScoreChanged();
};
