// Copyright - Tinkering Studios

#include "BaseCharacter.h"

#include "ActionManager.h"
#include "MainGameMode.h"
#include "NativeGameplayTags.h"
#include "SkeletalMeshComponentBudgeted.h"
#include "StatisticsComponent.h"
#include "TimeDilationManager.h"

UE_DEFINE_GAMEPLAY_TAG(TAG_Stats_Health, "Stats.Health")

// Sets default values
ABaseCharacter::ABaseCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer.SetDefaultSubobjectClass<USkeletalMeshComponentBudgeted>(ACharacter::MeshComponentName))
{
	PrimaryActorTick.bCanEverTick = false;

	StatsComponent = CreateDefaultSubobject<UStatisticsComponent>(TEXT("StatsComponent"));

	ActionsManager = CreateDefaultSubobject<UActionManager>(TEXT("ActionsManager"));
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

float ABaseCharacter::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator,
	AActor* DamageCauser)
{
	// Damage!
	StatsComponent->ModifyCurrentValueOfStatistic(TAG_Stats_Health, -Damage);

	AMainGameMode* GameMode = Cast<AMainGameMode>(GetWorld()->GetAuthGameMode());

	bool IsDeathHit = StatsComponent->GetStatInfoByTag(TAG_Stats_Health).currentValue == 0;

	// Slow down time for a bit. We do it longer if health is zero.
	GameMode->GetTimeDilationManager()->SetTime(0.3, IsDeathHit ? .1 : .025);

	APlayerCameraManager::PlayWorldCameraShake(GetWorld(), IsDeathHit ? BigHitScreenShake : HitScreenShake, GetActorLocation(), 0, 500, 1, false);
	
	return Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

