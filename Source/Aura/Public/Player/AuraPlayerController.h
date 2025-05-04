// Copyright S.R.Hamilton.Art

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "gameframework/Pawn.h"
#include "AuraPlayerController.generated.h"



class UInputMappingContext;
class UInputAction;
/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()

	protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	
	public:
	AAuraPlayerController();

private:
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> AuraContext;
	
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	void Move(const struct FInputActionValue& InputActionValue);
};
