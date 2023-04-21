#pragma once

#include "CoreMinimal.h"
#include "Agent.h"
#include "Engine/GameEngine.h"
#include "FlockingManager.generated.h"

UCLASS()
class FLOCKING_API UFlockingManager : public UObject
{

public:
	GENERATED_BODY()

		void Init(UWorld* world, UStaticMeshComponent* mesh);
	void Flock();
	FVector Rule1(AAgent* b);
	FVector Rule2(AAgent* b);
	FVector Rule3(AAgent* b);
	void Goal(AAgent* b);

private:
	UWorld* World;
	bool initialized;
	bool use_goal = true;
	TArray<class AAgent*> Agents;
};