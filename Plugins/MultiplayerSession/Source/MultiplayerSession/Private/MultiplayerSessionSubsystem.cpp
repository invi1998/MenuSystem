// Fill out your copyright notice in the Description page of Project Settings.

#include "MultiplayerSessionSubsystem.h"
#include "OnlineSubsystem.h"

UMultiplayerSessionSubsystem::UMultiplayerSessionSubsystem()
{
	IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get();

	if (Subsystem)
	{
		SessionInterface = Subsystem->GetSessionInterface();
		// 访问子系统并从中获得了会话接口并将其存储在私有变量 SessionInterface 中
		// 现在就可以使用这些会话接口函数来管理我们的游戏会话
	}
}