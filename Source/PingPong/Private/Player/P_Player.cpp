// FaromStudio Test. Coded by Oliver.

#include "Player/P_Player.h"
#include "Player/PMComp.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Net/UnrealNetwork.h"
#include "InputActionValue.h"

//*******************************************************************************************************************************************************
AP_Player::AP_Player()
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
	SetReplicateMovement(true);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Platform"));
	RootComponent = StaticMeshComp;

	StaticMeshComp->SetCollisionProfileName(TEXT("Pawn"));
	StaticMeshComp->SetGenerateOverlapEvents(false);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(StaticMeshComp);
	SpringArm->SetRelativeLocation(FVector(0.0f, 0.0f, 400.0f));
	SpringArm->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));
	SpringArm->TargetArmLength = 1000.0f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 3.0f;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComp->SetupAttachment(SpringArm);

	PawnMovementComp = CreateDefaultSubobject<UPMComp>(TEXT("PawnMovementComponent"));
	PawnMovementComp->UpdatedComponent = RootComponent;
	PawnMovementComp->SetIsReplicated(true);
}
//*******************************************************************************************************************************************************
void AP_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
//*******************************************************************************************************************************************************
void AP_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
//*******************************************************************************************************************************************************
void AP_Player::MoveRight(const float& Value)
{
	if (Controller)
	{
		AddMovementInput(GetActorRightVector(), Value);
	}

	if (!HasAuthority())
	{
		MoveRight_Server(Value);
	}
}
//*******************************************************************************************************************************************************
void AP_Player::MoveRight_Server_Implementation(const float& Value)
{
	MoveRight(Value);
}
//*******************************************************************************************************************************************************
void AP_Player::Turn(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();
	Yaw += MovementVector.Y;
	SpringArm->SetRelativeRotation(FRotator(-45.0f, Yaw, 0.0f));
}
//*******************************************************************************************************************************************************
void AP_Player::BeginPlay()
{
	Super::BeginPlay();
}
//*******************************************************************************************************************************************************