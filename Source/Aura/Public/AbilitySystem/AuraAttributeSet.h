// Copyright S.R.Hamilton.Art

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "AuraAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

USTRUCT(blueprintType)
struct FEffectProperties
{
	GENERATED_BODY()
	FEffectProperties(){}
	// FEffectProperties(UAbilitySystemComponent* SourceASC, AActor* SourceAvatarActor, AController* SourceController, ACharacter* SourceCharacter, FGameplayEffectContextHandle* SourceEffectContextHandle,
	// UAbilitySystemComponent* TargetASC, AActor* TargetAvatarActor, AController* TargetController, ACharacter* TargetCharacter, FGameplayEffectContextHandle* TargetEffectContextHandle	)
	// : SourceAbilitySystemComponent(SourceASC), SourceAvatarActor(SourceAvatarActor),SourceController(SourceController), SourceCharacter(SourceCharacter), SourceEffectContextHandle(*SourceEffectContextHandle),
	// TargetAbilitySystemComponent(TargetASC), TargetAvatarActor(TargetAvatarActor),TargetCharacter(TargetCharacter),TargetEffectContextHandle(*TargetEffectContextHandle){}

	UPROPERTY(Editanywhere, BlueprintReadWrite)
	FGameplayEffectContextHandle EffectContextHandle;

	//Source
	UPROPERTY(Editanywhere, BlueprintReadWrite)
	TObjectPtr<UAbilitySystemComponent> SourceASC = nullptr;

	UPROPERTY(Editanywhere, BlueprintReadWrite)
	TObjectPtr<AActor> SourceAvatarActor = nullptr;

	UPROPERTY(Editanywhere, BlueprintReadWrite)
	TObjectPtr<AController> SourceController = nullptr;

	UPROPERTY(Editanywhere, BlueprintReadWrite)
	TObjectPtr<ACharacter> SourceCharacter = nullptr;
	
	//Target
	UPROPERTY(Editanywhere, BlueprintReadWrite)
	TObjectPtr<UAbilitySystemComponent> TargetASC = nullptr;

	UPROPERTY(Editanywhere, BlueprintReadWrite)
	TObjectPtr<AActor> TargetAvatarActor = nullptr;

	UPROPERTY(Editanywhere, BlueprintReadWrite)
	TObjectPtr<AController> TargetController = nullptr;

	UPROPERTY(Editanywhere, BlueprintReadWrite)
	TObjectPtr<ACharacter> TargetCharacter = nullptr;




};

/**
 * 
 */
UCLASS()
class AURA_API UAuraAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UAuraAttributeSet();
	
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	//Health
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Vital Attributes")
	FGameplayAttributeData Health;
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Vital Attributes")
	FGameplayAttributeData MaxHealth;
	
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Health);
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxHealth);
	//UFUNCTION()
	//void OnRep_Health(const FGameplayAttributeData& OldHealth) const;
	//End Health

	//Mana
	UPROPERTY(BlueprintReadOnly,ReplicatedUsing = OnRep_Mana, Category = "Vital Attributes")
	FGameplayAttributeData Mana;
	UPROPERTY(BlueprintReadOnly,ReplicatedUsing = OnRep_MaxMana, Category = "Vital Attributes")
	FGameplayAttributeData MaxMana;
	
	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;
	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet,Mana);
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet,MaxMana);
	//End Mana

private:

	void SetEffectProperties(const FGameplayEffectModCallbackData& Data,FEffectProperties& Props) const;
};
