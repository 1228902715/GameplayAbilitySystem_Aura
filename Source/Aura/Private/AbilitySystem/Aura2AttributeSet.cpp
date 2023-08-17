// GuanZhongYeLang Project.


#include "AbilitySystem/Aura2AttributeSet.h"
#include "Net/UnrealNetwork.h"


UAura2AttributeSet::UAura2AttributeSet()
{
	InitHealth(100.f);
	
}

//P23
void UAura2AttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{

	// 复制属性的地方

	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UAura2AttributeSet,Health,COND_None,REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAura2AttributeSet,MaxHealth,COND_None,REPNOTIFY_Always);

	
	DOREPLIFETIME_CONDITION_NOTIFY(UAura2AttributeSet,Mana,COND_None,REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAura2AttributeSet,MaxMana,COND_None,REPNOTIFY_Always);
	
}


void UAura2AttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAura2AttributeSet,Health,OldHealth);  // 负责通知服务器上有一个值，被改变
}
void UAura2AttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAura2AttributeSet,MaxHealth,OldMaxHealth);  // 负责通知服务器上有一个值，被改变
}



void UAura2AttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAura2AttributeSet,Mana,OldMana);  // 负责通知服务器上有一个值，被改变
} 
void UAura2AttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAura2AttributeSet,MaxMana,OldMaxMana);  // 负责通知服务器上有一个值，被改变
}