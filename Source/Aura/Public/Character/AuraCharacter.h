// GuanZhongYeLang Project.

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "AuraCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase    // 继承我们 AuraCharacterBase(基础的Character类，主角和Ai都继承自此基础类)
{
	GENERATED_BODY()
public:
	AAuraCharacter();

	virtual  void PossessedBy(AController* NewController) override;
	virtual  void OnRep_PlayerState() override;

private:
	void InitAbilityActorInfo();
	
	
};
