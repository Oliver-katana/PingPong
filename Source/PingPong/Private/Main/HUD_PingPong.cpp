// FaromStudio Test. Coded by Oliver.

#include "Main/HUD_PingPong.h"
#include "UI/W_Score.h"

//*******************************************************************************************************************************************************
void AHUD_PingPong::BeginPlay()
{
	Super::BeginPlay();
	if (ScoreWidget)
	{
		ScoreWidgetRef = Cast<UW_Score>(CreateWidget(GetWorld(), ScoreWidget));
		if (ScoreWidgetRef)
		{
			ScoreWidgetRef->AddToViewport();
		}
	}
}
//*******************************************************************************************************************************************************