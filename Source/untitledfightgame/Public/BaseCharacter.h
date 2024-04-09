// Copyright - Tinkering Studios

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS()
class UNTITLEDFIGHTGAME_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual float TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

#pragma region Components

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Stats, meta = (AllowPrivateAccess = "true"))
	class UStatisticsComponent* StatsComponent;

#pragma endregion

public:

	FORCEINLINE class UStatisticsComponent* GetStatisticsComponent() const { return StatsComponent; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Screen Shake");
	TSubclassOf<class UCameraShakeBase> HitScreenShake;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Screen Shake");
	TSubclassOf<class UCameraShakeBase> BigHitScreenShake;
    
private:

	FGameplayTag HealthTag;

};
