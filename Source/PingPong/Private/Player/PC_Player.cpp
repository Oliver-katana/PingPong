// FaromStudio Test. Coded by Oliver.

#include "Player/PC_Player.h"
#include "Player/P_Player.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

//*******************************************************************************************************************************************************
void APC_Player::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(Super::InputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APC_Player::MoveRight);
		EnhancedInputComponent->BindAction(TurnAction, ETriggerEvent::Triggered, this, &APC_Player::Turn);
		EnhancedInputComponent->BindAction(QuitAction, ETriggerEvent::Started, this, &APC_Player::Quit);
	}
}
//*******************************************************************************************************************************************************
void APC_Player::BeginPlay()
{
	Super::BeginPlay();

	if (!MyPawn)
	{
		MyPawn = Cast<AP_Player>(GetPawn());
	}

	if (HasAuthority())
	{
		Possess(MyPawn);
	}

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}
}
//*******************************************************************************************************************************************************
void APC_Player::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
}
//*******************************************************************************************************************************************************
void APC_Player::MoveRight(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();
	if (MyPawn)
	{
		MyPawn->MoveRight(MovementVector.Y);
	}
}
//*******************************************************************************************************************************************************
void APC_Player::Turn(const FInputActionValue& Value)
{
	if (MyPawn)
	{
		MyPawn->Turn(Value);
	}
}
//*******************************************************************************************************************************************************
void APC_Player::Quit(const FInputActionValue& Value)
{
	ConsoleCommand("quit");
}
//*******************************************************************************************************************************************************