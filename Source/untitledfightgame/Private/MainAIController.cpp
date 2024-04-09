// Copyright - Tinkering Studios


#include "MainAIController.h"

ETeamAttitude::Type AMainAIController::GetTeamAttitudeTowards(const AActor& Other) const
{
	const APawn* OtherPawn = Cast<APawn>(&Other);

	// Make sure pawn is valid.
	if(!OtherPawn)
	{
		return ETeamAttitude::Neutral;
	}
	
	const IGenericTeamAgentInterface* TeamAgent = Cast<IGenericTeamAgentInterface>(OtherPawn->GetController());

	// Make sure team agent is valid.
	if(!TeamAgent)
	{
		return ETeamAttitude::Hostile;
	}

	return (TeamAgent->GetGenericTeamId() == TeamId) ? ETeamAttitude::Friendly : ETeamAttitude::Hostile;
}
