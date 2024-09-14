// FaromStudio Test. Coded by Oliver.

#include "Player/PS_Player.h"
#include "Main/HUD_PingPong.h"
#include "Kismet/GameplayStatics.h"
#include "UI/W_Score.h"
#include "Components/TextBlock.h"

//*******************************************************************************************************************************************************
void APS_Player::UpdateScore_Server_Implementation(const int& Score1, const int& Score2)
{
	UpdateScore_Client(Score1, Score2);
	if (PlayerId % 2)
	{
		SetScore(Score2, Score1);
	}
	else
	{
		SetScore(Score1, Score2);
	}
}
//*******************************************************************************************************************************************************
void APS_Player::UpdateScore_Client_Implementation(const int& Score1, const int& Score2)
{
	if (PlayerId % 2)
	{
		SetScore(Score1, Score2);
	}
	else
	{
		SetScore(Score2, Score1);
	}
}
//*******************************************************************************************************************************************************
void APS_Player::SetScore(const int& Score1, const int& Score2)
{
	AHUD_PingPong* HUD = Cast<AHUD_PingPong>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
	if (HUD)
	{
		HUD->ScoreWidgetRef->player1_score->SetText(FText::AsNumber(Score1));
		HUD->ScoreWidgetRef->player2_score->SetText(FText::AsNumber(Score2));
	}
}
//*******************************************************************************************************************************************************