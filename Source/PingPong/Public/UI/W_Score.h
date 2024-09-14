// FaromStudio Test. Coded by Oliver.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "W_Score.generated.h"

class UTextBlock;

UCLASS()
class PINGPONG_API UW_Score : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* player1_score;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* player2_score;
};
