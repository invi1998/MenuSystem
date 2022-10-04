// Fill out your copyright notice in the Description page of Project Settings.

#include "MultiplayerSessionSubsystem.h"
#include "OnlineSubsystem.h"

UMultiplayerSessionSubsystem::UMultiplayerSessionSubsystem()
{
	IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get();

	if (Subsystem)
	{
		SessionInterface = Subsystem->GetSessionInterface();
		// ������ϵͳ�����л���˻Ự�ӿڲ�����洢��˽�б��� SessionInterface ��
		// ���ھͿ���ʹ����Щ�Ự�ӿں������������ǵ���Ϸ�Ự
	}
}