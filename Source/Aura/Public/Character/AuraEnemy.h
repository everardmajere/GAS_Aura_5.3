// Copyright S.R.Hamilton.Art

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacter.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacter, public IEnemyInterface

{
	GENERATED_BODY()

public:
	AAuraEnemy();

	//Enemy Interface
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	//End Enemy Interface

	
protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;
	
};
