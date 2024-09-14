// FaromStudio Test. Coded by Oliver.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PawnMovementComponent.h"
#include "PMComp.generated.h"

UCLASS()
class PINGPONG_API UPMComp : public UPawnMovementComponent
{
	GENERATED_BODY()
	
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
