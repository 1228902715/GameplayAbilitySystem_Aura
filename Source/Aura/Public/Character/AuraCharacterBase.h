// GuanZhongYeLang Project.

#pragma once

#include "CoreMinimal.h"
// #include "AbilitySystem/AuraAbilitySystemComponent.h"
#include"AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "AuraCharacterBase.generated.h"


class UAbilitySystemComponent;
class UAttributeSet;

// UCLASS(Abstract)   这个宏可以防止被拖入关卡



// 基础的Character 防止被拖入关卡，会删一些东西
UCLASS(Abstract)




class AURA_API AAuraCharacterBase : public ACharacter,public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AAuraCharacterBase();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UAttributeSet* GetAttributeSet()const { return AttributeSet;}
	

protected:
	virtual void BeginPlay() override;

	// 需要所有的都需要一件武器，并且需要搞一个插槽，绑定在上面的

	UPROPERTY(EditAnywhere,Category="Combat")
	TObjectPtr<USkeletalMeshComponent>Weapon;

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
	


	







	
	// 被删除的，但不知道是啥意思
// public:	
// 	// Called every frame
// 	virtual void Tick(float DeltaTime) override;
//
// 	// Called to bind functionality to input
// 	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
