// FaromStudio Test. Coded by Oliver.

#include "Ball/A_Ball.h"
#include "Sound/SoundCue.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/ProjectileMovementComponent.h"

//*******************************************************************************************************************************************************
AA_Ball::AA_Ball()
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
	SetReplicateMovement(true);


	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	RootComponent = StaticMeshComp;


	StaticMeshComp->SetNotifyRigidBodyCollision(true);
	StaticMeshComp->SetCollisionProfileName(TEXT("BlockAll"));
	StaticMeshComp->OnComponentHit.AddDynamic(this, &AA_Ball::OnHit);
	StaticMeshComp->CanCharacterStepUpOn = ECB_No;
	StaticMeshComp->CastShadow = false;
	StaticMeshComp->SetUseCCD(true);

	BallMovementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("BallMovementComponent"));
	BallMovementComp->UpdatedComponent = StaticMeshComp;
	BallMovementComp->InitialSpeed = 1000;
	BallMovementComp->MaxSpeed = 1000;
	BallMovementComp->bRotationFollowsVelocity = true;
	BallMovementComp->ProjectileGravityScale = 0.0f;
	BallMovementComp->bShouldBounce = true;
	BallMovementComp->Bounciness = 1.0f;
	BallMovementComp->Friction = 0.0f;
}
//*******************************************************************************************************************************************************
void AA_Ball::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
//*******************************************************************************************************************************************************
void AA_Ball::BeginPlay()
{
	Super::BeginPlay();
}
//*******************************************************************************************************************************************************
void AA_Ball::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	FVector ReflectionVector =GetActorForwardVector().MirrorByVector(Hit.ImpactNormal);
	SetActorRotation(ReflectionVector.Rotation());

	if (GetLocalRole() == ROLE_Authority)
	{
		PlayHitSound();
	}
}
//*******************************************************************************************************************************************************
void AA_Ball::PlayHitSound_Implementation()
{
	if (HitSound)
	{
		UGameplayStatics::PlaySound2D(this, HitSound);
	}
}
//*******************************************************************************************************************************************************