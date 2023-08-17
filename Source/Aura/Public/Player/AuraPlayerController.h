// GuanZhongYeLang Project.

#pragma once

#include "CoreMinimal.h"
// #include "InputActionValue.h"
#include "GameFramework/PlayerController.h"



#include "AuraPlayerController.generated.h"



class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

class IEnemyInterface; 

/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()  

public:
	AAuraPlayerController();
	virtual void PlayerTick(float DeltaTime) override;  // 每一帧都操作

	

	

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditAnywhere,Category="Input")
	TObjectPtr<UInputMappingContext> AuraContext;

	UPROPERTY(EditAnywhere,Category="Input")
	TObjectPtr<UInputAction> MoveAction;



	void Move(const  FInputActionValue& InputActionValue);
	void CursorTrace();    // 鼠标跟踪  就是鼠标在那个怪身上，这个怪就发红
	IEnemyInterface* LastActor;
	IEnemyInterface* ThisActor;

	

	
	
	
};
