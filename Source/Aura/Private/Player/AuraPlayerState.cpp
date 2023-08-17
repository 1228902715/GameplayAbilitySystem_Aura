// GuanZhongYeLang Project.


#include "Player/AuraPlayerState.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "./AbilitySystem/Aura2AttributeSet.h"




AAuraPlayerState::AAuraPlayerState()
{

	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	// 调用ASC
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

 // 	AbilitySystemComponent = CreateDefaultSubobject<UAura2AttributeSet>("AttributeSet");
	



	
	AttributeSet = CreateDefaultSubobject<UAura2AttributeSet>("AttributeSet");
	


	
	NetUpdateFrequency = 100.f;
	
	
}

UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
	
}
