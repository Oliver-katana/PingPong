// FaromStudio Test. Coded by Oliver.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PC_Player.generated.h"

class AP_Player;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class PINGPONG_API APC_Player : public APlayerController
{
	GENERATED_BODY()
	
public:

	virtual void SetupInputComponent() override;

protected:

	virtual void BeginPlay();

	virtual void OnPossess(APawn* InPawn) override;

	void MoveRight(const FInputActionValue& Value);

	void Turn(const FInputActionValue& Value);
	
	void Quit(const FInputActionValue& Value);

private:

	UPROPERTY()
	AP_Player* MyPawn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* TurnAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* QuitAction;

};
