// FaromStudio Test. Coded by Oliver.

#include "Main/GSB_PingPong.h"
#include "Player/PS_Player.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"


//*******************************************************************************************************************************************************
void AGSB_PingPong::GetLifetimeReplicatedProps(TArray<FLifetimeProperty, FDefaultAllocator>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AGSB_PingPong, Player1Score);
	DOREPLIFETIME(AGSB_PingPong, Player2Score);
}
//*******************************************************************************************************************************************************
void AGSB_PingPong::PlayerScoreChanged()
{
	APS_Player* PlayerState = Cast<APS_Player>(UGameplayStatics::GetPlayerController(this, 0)->PlayerState);
	if (PlayerState)
	{
		PlayerState->UpdateScore_Server(Player1Score, Player2Score);
	}
}
//*******************************************************************************************************************************************************