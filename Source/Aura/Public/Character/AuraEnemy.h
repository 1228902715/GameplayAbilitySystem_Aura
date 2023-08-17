// GuanZhongYeLang Project.

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public  IEnemyInterface    //// 继承我们 AuraCharacterBase(基础的Character类，主角和Ai都继承自此基础类)
{
	GENERATED_BODY()

public:

	AAuraEnemy();

	




	
	// Enemy Interface
	virtual void HighlightActor()override;
	virtual void UnHighlightActor()override;
	// end Enemy Interface

protected:
	virtual void BeginPlay() override;
	


	
	// 测试鼠标凸显怪物的高亮用
	// UPROPERTY(BlueprintReadOnly)
	// bool bHightlighted = false;

	
	
};
