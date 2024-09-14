// FaromStudio Test. Coded by Oliver.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "HUD_PingPong.generated.h"

class UW_Score;

UCLASS()
class PINGPONG_API AHUD_PingPong : public AHUD
{
	GENERATED_BODY()
	
public:

	virtual void BeginPlay()override;

	UPROPERTY(EditDefaultsOnly, Category = "Widget")
	TSubclassOf<UW_Score> ScoreWidget;

	UPROPERTY(BlueprintReadOnly)
	UW_Score* ScoreWidgetRef = nullptr;
};
