// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "OnlineSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "MultiPlayerSessionSubSystem.generated.h"

//
//Declaring our own delegates for the Menu Class to bind callbacks to
//
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMultiplayerOnCreateSessionComplete, bool, bWasSuccessful);


/**
 * 
 */
UCLASS()
class MULTIPLAYERSESSIONS_API UMultiPlayerSessionSubSystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public :
	UMultiPlayerSessionSubSystem();
	void CreateSession(int32 NumPub,FString MatchType);
	void FindSession(int32 MaxSearchResults);
	void JoinSession(const FOnlineSessionSearchResult& SessionResult);
	void DestroySession();
	void StartSession();
	
	//our own Delegate for the Menu class
	FMultiplayerOnCreateSessionComplete MultiplayerOnCreateSessionComplete;
protected:
	void OpenLobby();

	void onCreateSessionComplete(FName SessionName, bool bWasSuccessful);
	void onFindSessionComplete(bool bWasSuccessful);
	void JoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);
	void DestroySessionComplete(FName SessionName, bool bWasSuccessful);
	void StartSessionComplete(FName SessionName, bool bWasSuccessful);
private:
	IOnlineSessionPtr SessionInterfacePtr;
	TSharedPtr<FOnlineSessionSettings> LastSessionSettings;
	TSharedPtr<FOnlineSessionSearch> SessionSearch;


	FOnCreateSessionCompleteDelegate CreateSessionCompleteDelegate;
	FDelegateHandle CreateSessionCompleteDelegateHandle;

	FOnFindSessionsCompleteDelegate FindSessionCompleteDelegate;
	FDelegateHandle FindSessionsCompleteDelegateHandle;

	FOnJoinSessionCompleteDelegate JoinSessionCompleteDelegate;
	FDelegateHandle JoinSessionCompleteDelegateHandle;

	FOnDestroySessionCompleteDelegate DestroySessionCompleteDelegate;
	FDelegateHandle DestroySessionCompleteDelegateHandle;

	FOnStartSessionCompleteDelegate StartSessionCompleteDelegate;
	FDelegateHandle StartSessionCompleteDelegateHandle;
};
