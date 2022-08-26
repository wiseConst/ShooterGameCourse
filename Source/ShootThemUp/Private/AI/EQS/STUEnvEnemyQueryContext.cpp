// Shoot Them Up Game. All Rights Reserved.


#include "AI/EQS/STUEnvEnemyQueryContext.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_Actor.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

void USTUEnvEnemyQueryContext::ProvideContext(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const
{
	const auto QueryOwner = Cast<AActor>(QueryInstance.Owner.Get());

	const auto Blackboard = UAIBlueprintHelperLibrary::GetBlackboard(QueryOwner);
	if (!Blackboard) return;
	const auto ContextActor = Cast<AActor>(Blackboard->GetValueAsObject(EnemyActorKeyName));
	UEnvQueryItemType_Actor::SetContextHelper(ContextData, ContextActor);
}