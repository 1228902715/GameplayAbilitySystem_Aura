// GuanZhongYeLang Project.


#include "Player/AuraPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include"EnhancedInputComponent.h"
#include "Interaction/EnemyInterface.h"


AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;
	

	
}

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
	
	Super::PlayerTick(DeltaTime);


	// 每帧调用CursorTrace 查看鼠标是否在怪身上
	CursorTrace();
	
}

void AAuraPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility,false,CursorHit);
	if(!CursorHit.bBlockingHit)return;  // 如果鼠标没有命中，就直接返回 啥也不干

	LastActor = ThisActor;
	ThisActor = Cast<IEnemyInterface>(CursorHit.GetActor());

	/*通过鼠标检测，可以分这几种情况
	 *
	 * A- LastActor 是空的吗 并且&& ThisActor 是空的吗？ 
	 *    什么也不做（碰到别的什么东西，墙什么的）
	 * B- LastActor 空  && ThisActor 不是空（有东西）
	 *    调用 HightActor 突出显示
	 * C- LastActor 有效 && ThisActor 为空
	 *    调用 UnHightActor 不突出显示
	 * D- 两者都有效，并且 LastActor != ThisActor
	 *    上一个就不显示高亮，现在这个才显示高亮
	 * E- 两者都有效，且是 LastActor == ThisActor
	 *    什么都不做
	 *  
	 *      
	 */

	if(LastActor == nullptr)
	{
		if(ThisActor!= nullptr)
		{
			// B
			ThisActor->HighlightActor();
		}
		else
		{
			// A 啥都不做
		}
	}
	else // LaseActor 有效
	{
		if(ThisActor == nullptr)
		{
			// C
			LastActor->UnHighlightActor();
		}
		else // 两者都有效
		{
			if(LastActor != ThisActor)
			{
				// D
				LastActor->UnHighlightActor();
				ThisActor->HighlightActor();
			}
			else
			{
				// e 啥都不做
			}
		}
	}
	
}







void AAuraPlayerController::BeginPlay()
{
	
	Super::BeginPlay();

	check(AuraContext);

	// UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<>();
	//
	// UEnhance
	//

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	check(Subsystem)
	Subsystem ->AddMappingContext(AuraContext,0);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);


	
}

void AAuraPlayerController::SetupInputComponent()
{

	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction,ETriggerEvent::Triggered,this,&AAuraPlayerController::Move);

}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{

	const FVector2d InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f,Rotation.Yaw,0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if(APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection,InputAxisVector.Y);  // w s 键盘  运动
		ControlledPawn->AddMovementInput(RightDirection,InputAxisVector.X);   // A D键盘 运动
		
	}
	
}



