// Copyright S.R.Hamilton.Art


#include "AbilitySystem/AuraAbilitySystemComponentBase.h"

void UAuraAbilitySystemComponentBase::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this,&UAuraAbilitySystemComponentBase::EffectApplied);
}

void UAuraAbilitySystemComponentBase::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
                                                    const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);
	for (const FGameplayTag& Tag : TagContainer)
	{
		//TODO: Broadcast the tage to the widget controller

		const FString TagString = FString::Printf(TEXT("GE Tag: %s"), *Tag.ToString());
		GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Red, TagString);
	}
	
}

