// GuanZhongYeLang Project.


#include "Character/AuraEnemy.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "./AbilitySystem/Aura2AttributeSet.h"
#include "Aura/Aura.h"


AAuraEnemy::AAuraEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility,ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UAura2AttributeSet>("AttributeSet");


	
}

void AAuraEnemy::HighlightActor()
{
	// bHightlighted = true;

	GetMesh()->SetRenderCustomDepth(true);

	// 在Aura.h 文件夹中，利用宏定于了 CUSTOM_DEPTH_RED 250 这个
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	

	
}

void AAuraEnemy::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
//	bHightlighted = false;
	Weapon->SetRenderCustomDepth(false);
}

void AAuraEnemy::BeginPlay()
{
	Super::BeginPlay();

	//check(AbilitySystemComponent);
	AbilitySystemComponent->InitAbilityActorInfo(this,this);
	

	


	
}
