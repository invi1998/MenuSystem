// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Menu.generated.h"

/**
 *
 */
UCLASS()
class MULTIPLAYERSESSION_API UMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
		void MenuSetup();

protected:

	virtual bool Initialize() override;

private:

	// 指定绑定小部件，这样做之后我们的蓝图上的按钮部件将会链接到c++中的按钮变量
	// 注意，这里	C++变量必须与我们蓝图里的部件名称完全相同
	UPROPERTY(meta = (BindWidget))
		class UButton* HostButton;

	UPROPERTY(meta = (BindWidget))
		UButton* JoinButton;

	UFUNCTION()
		void HostButtonClicked();

	UFUNCTION()
		void JoinButtonClicked();

	// 处理所有在线会话功能的子系统
	class UMultiplayerSessionSubsystem* MultiplayerSessionSubsystem;
};
