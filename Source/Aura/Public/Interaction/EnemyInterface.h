// GuanZhongYeLang Project.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EnemyInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEnemyInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class AURA_API IEnemyInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.


   // 当我们鼠标停止在小怪身上（拿长矛，拿弹弓的）会有不一样的结果

	

	
public:


	virtual void HighlightActor()=0;
	virtual void UnHighlightActor()=0;
	
	
};
