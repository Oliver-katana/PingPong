// FaromStudio Test. Coded by Oliver.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "P_Player.generated.h"

class UPMComp;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class PINGPONG_API AP_Player : public APawn
{
	GENERATED_BODY()

public:

	AP_Player();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	UPMComp* PawnMovementComp;

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent);

	UFUNCTION(BlueprintCallable)
	void MoveRight(const float& Value);

	UFUNCTION(Server, Reliable)
	void MoveRight_Server(const float& Value);

	UFUNCTION()
	void Turn(const FInputActionValue& Value);

protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "StaticMesh")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Camera")
	USpringArmComponent* SpringArm;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* CameraComp;

private:

	float Yaw = 0;

};
