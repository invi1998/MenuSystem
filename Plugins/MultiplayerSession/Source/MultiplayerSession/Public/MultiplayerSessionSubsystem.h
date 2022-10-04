// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"

#include "MultiplayerSessionSubsystem.generated.h"

/**
 *
 */
UCLASS()
class MULTIPLAYERSESSION_API UMultiplayerSessionSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UMultiplayerSessionSubsystem();

	/// <summary>
	/// ����Ự���ܣ��˵������е��ã����ԴӰ�������ϵͳ���κ����е�������
	/// </summary>

	// �����Ự���������ûỰ��ֵ��
	void CreateSession(int32 NumPublicConnections, FString MatchType);

	/**
	 * @brief ���һỰ
	 * @param MaxSearchResults ָ��Ҫ�����Ľ������
	 */
	void FindSession(int32 MaxSearchResults);

	// ����Ҫ����ĻỰ�������������������Ϸ�Ự
	void JoinSession(const FOnlineSessionSearchResult& SessionSearchResult);

	// ���ٻỰ
	void DestroySession();

	// ��ʼ�Ự
	void StartSession();

protected:
	// ���ᱻ��ӵ����߻Ự�ӿ�ί���б�����ڲ��ص�����
	// ����Ҫ�����������е���

	void OnCreateSessionComplete(FName SessionName, bool bWasSuccessful);
	void OnFindSessionComplete(bool bWasSuccessful);
	void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);
	void OnDestroySessionComplete(FName SessionName, bool bWasSuccessful);
	void OnStartSessionComplete(FName SessionName, bool bWasSuccessful);

private:
	IOnlineSessionPtr SessionInterface;		// ���߻Ự������ָ��

	// ��ӵ����߻Ự����ί���б���
	// ���� MultiPlayerSessionSubsystem �ڲ��Ļص����� �������Щί�н��а�

	FOnCreateSessionCompleteDelegate CreateSessionCompleteDelegate;			// �����Ự���ί��
	FDelegateHandle CreateSessionCompleteDelegateHandle;
	FOnFindSessionsCompleteDelegate FindSessionsCompleteDelegate;			// ���һỰ���ί��
	FDelegateHandle FindSessionsCompleteDelegateHandle;
	FOnJoinSessionCompleteDelegate JoinSessionCompleteDelegate;				// ����Ự���ί��
	FDelegateHandle JoinSessionCompleteDelegateHandle;
	FOnDestroySessionCompleteDelegate DestroySessionCompleteDelegate;		// ���ٻỰ���ί��
	FDelegateHandle DestroySessionCompleteDelegateHandle;
	FOnStartSessionCompleteDelegate StartSessionCompleteDelegate;			// ��ʼ�Ự���ί��
	FDelegateHandle StartSessionCompleteDelegateHandle;
};
