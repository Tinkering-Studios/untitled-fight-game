// Copyright - Tinkering Studios

#include "BaseCharacter.h"
#include "StatisticsComponent.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	StatsComponent = CreateDefaultSubobject<UStatisticsComponent>(TEXT("StatsComponent"));

	// Can't put this as a static variable because who knows.
	// This engine tries to be C# so badly and refuses to do anything normal/modern because they live in C++99 land.
	// Preventing a static variable from existing is so silly, so now we have to make each class request it on constructor.
	// Thanks Unreal!!!!! Great way to waste memory!!!!!!
	HealthTag = FGameplayTag::RequestGameplayTag(FName("Stats.Health"));
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
	StatsComponent->ModifyCurrentValueOfStatistic(HealthTag, -Damage);
	
	return Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

