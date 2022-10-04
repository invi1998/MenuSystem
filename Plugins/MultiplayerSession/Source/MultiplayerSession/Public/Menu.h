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

	// ָ����С������������֮�����ǵ���ͼ�ϵİ�ť�����������ӵ�c++�еİ�ť����
	// ע�⣬����	C++����������������ͼ��Ĳ���������ȫ��ͬ
	UPROPERTY(meta = (BindWidget))
		class UButton* HostButton;

	UPROPERTY(meta = (BindWidget))
		UButton* JoinButton;

	UFUNCTION()
		void HostButtonClicked();

	UFUNCTION()
		void JoinButtonClicked();

	// �����������߻Ự���ܵ���ϵͳ
	class UMultiplayerSessionSubsystem* MultiplayerSessionSubsystem;
};
