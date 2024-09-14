// FaromStudio Test. Coded by Oliver.

#include "Gate/A_Gate.h"
#include "Components/BoxComponent.h"
#include "Sound/SoundCue.h"
#include "Kismet/GameplayStatics.h"
#include "Main/GSB_PingPong.h"
#include "Main/GMB_PingPong.h"

//*******************************************************************************************************************************************************
AA_Gate::AA_Gate()
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollisionComponent"));
	RootComponent = BoxComponent;
	BoxComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	BoxComponent->SetGenerateOverlapEvents(true);
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AA_Gate::OnOverlapBegin);
}
//*******************************************************************************************************************************************************
void AA_Gate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
//*******************************************************************************************************************************************************
void AA_Gate::BeginPlay()
{
	Super::BeginPlay();
}
//*******************************************************************************************************************************************************
void AA_Gate::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AGSB_PingPong* GameStateBase = Cast<AGSB_PingPong>(UGameplayStatics::GetGameState(GetWorld()));
	AGMB_PingPong* GameModeBase = Cast<AGMB_PingPong>(UGameplayStatics::GetGameMode(GetWorld()));

	if (GameStateBase && GameModeBase)
	{
		PlayGoalSound();
		if (ActorHasTag(TEXT("Gate1")))
		{
			++GameStateBase->Player1Score;
		}
		else
		{
			++GameStateBase->Player2Score;
		}
		OtherActor->Destroy();
		GameModeBase->SpawnBall();
	}
}
//*******************************************************************************************************************************************************
void AA_Gate::PlayGoalSound_Implementation()
{
	if (GoalSound)
	{
		UGameplayStatics::PlaySound2D(this, GoalSound);
	}
}
//*******************************************************************************************************************************************************