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
	/// 处理会话功能，菜单类会进行调用，可以从包含此子系统的任何类中调用他们
	/// </summary>

	// 创建会话并负责设置会话键值对
	void CreateSession(int32 NumPublicConnections, FString MatchType);

	/**
	 * @brief 查找会话
	 * @param MaxSearchResults 指定要搜索的结果数量
	 */
	void FindSession(int32 MaxSearchResults);

	// 传入要加入的会话搜索结果，进而加入游戏会话
	void JoinSession(const FOnlineSessionSearchResult& SessionSearchResult);

	// 销毁会话
	void DestroySession();

	// 开始会话
	void StartSession();

protected:
	// 将会被添加到在线会话接口委托列表里的内部回调函数
	// 不需要在这个类外进行调用

	void OnCreateSessionComplete(FName SessionName, bool bWasSuccessful);
	void OnFindSessionComplete(bool bWasSuccessful);
	void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);
	void OnDestroySessionComplete(FName SessionName, bool bWasSuccessful);
	void OnStartSessionComplete(FName SessionName, bool bWasSuccessful);

private:
	IOnlineSessionPtr SessionInterface;		// 在线会话的智能指针

	// 添加到在线会话界面委托列表中
	// 我们 MultiPlayerSessionSubsystem 内部的回调函数 将会对这些委托进行绑定

	FOnCreateSessionCompleteDelegate CreateSessionCompleteDelegate;			// 创建会话完成委托
	FDelegateHandle CreateSessionCompleteDelegateHandle;
	FOnFindSessionsCompleteDelegate FindSessionsCompleteDelegate;			// 查找会话完成委托
	FDelegateHandle FindSessionsCompleteDelegateHandle;
	FOnJoinSessionCompleteDelegate JoinSessionCompleteDelegate;				// 加入会话完成委托
	FDelegateHandle JoinSessionCompleteDelegateHandle;
	FOnDestroySessionCompleteDelegate DestroySessionCompleteDelegate;		// 销毁会话完成委托
	FDelegateHandle DestroySessionCompleteDelegateHandle;
	FOnStartSessionCompleteDelegate StartSessionCompleteDelegate;			// 开始会话完成委托
	FDelegateHandle StartSessionCompleteDelegateHandle;
};
