// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiPlayerSessionSubSystem.h"
#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"

UMultiPlayerSessionSubSystem::UMultiPlayerSessionSubSystem() :
	CreateSessionCompleteDelegate(FOnCreateSessionCompleteDelegate::CreateUObject(this, &ThisClass::onCreateSessionComplete)),
	FindSessionCompleteDelegate(FOnFindSessionsCompleteDelegate::CreateUObject(this, &ThisClass::onFindSessionComplete)),
	JoinSessionCompleteDelegate(FOnJoinSessionCompleteDelegate::CreateUObject(this, &ThisClass::JoinSessionComplete)),
	DestroySessionCompleteDelegate(FOnDestroySessionCompleteDelegate::CreateUObject(this, &ThisClass::DestroySessionComplete)),
	StartSessionCompleteDelegate(FOnStartSessionCompleteDelegate::CreateUObject(this, &ThisClass::StartSessionComplete))
{
	IOnlineSubsystem* SubSystem = IOnlineSubsystem::Get();
	if (SubSystem)
	{
		SessionInterfacePtr = SubSystem->GetSessionInterface();
	}
}

void UMultiPlayerSessionSubSystem::CreateSession(int32 NumPublicConnections, FString MatchType)
{
	if (!SessionInterfacePtr.IsValid()) {
		return;
	}

	auto ExistingSession = SessionInterfacePtr->GetNamedSession(NAME_GameSession);
	if (ExistingSession != nullptr) {
		SessionInterfacePtr->DestroySession(NAME_GameSession);
	}
	//绑定回调
	CreateSessionCompleteDelegateHandle = SessionInterfacePtr->AddOnCreateSessionCompleteDelegate_Handle(CreateSessionCompleteDelegate);
	//Session设置
	LastSessionSettings = MakeShareable(new FOnlineSessionSettings());
	LastSessionSettings->bIsLANMatch = IOnlineSubsystem::Get()->GetSubsystemName() == "NULL" ? true : false;
	LastSessionSettings->NumPublicConnections = NumPublicConnections;
	LastSessionSettings->bAllowJoinInProgress = true;
	LastSessionSettings->bAllowJoinViaPresence = true;
	LastSessionSettings->bShouldAdvertise = true;
	LastSessionSettings->bUsesPresence = true;
	LastSessionSettings->bUseLobbiesIfAvailable = true;
	LastSessionSettings->Set(FName("MatchType"), MatchType, EOnlineDataAdvertisementType::ViaOnlineServiceAndPing);
	//创建Session
	const ULocalPlayer* LocalPlayer = GetWorld()->GetFirstLocalPlayerFromController();
	if (!SessionInterfacePtr->CreateSession(*LocalPlayer->GetPreferredUniqueNetId(), NAME_GameSession, *LastSessionSettings)) {
		SessionInterfacePtr->ClearOnCreateSessionCompleteDelegate_Handle(CreateSessionCompleteDelegateHandle);

		MultiplayerOnCreateSessionComplete.Broadcast(false);
	}

}

void UMultiPlayerSessionSubSystem::FindSession(int32 MaxSearchResults)
{
	if (!SessionInterfacePtr.IsValid()) {
		return;
	}

}

void UMultiPlayerSessionSubSystem::JoinSession(const FOnlineSessionSearchResult& SessionResult)
{

}

void UMultiPlayerSessionSubSystem::DestroySession()
{

}

void UMultiPlayerSessionSubSystem::StartSession()
{

}

void UMultiPlayerSessionSubSystem::onCreateSessionComplete(FName SessionName, bool bWasSuccessful)
{
	if (SessionInterfacePtr) {
		SessionInterfacePtr->ClearOnCreateSessionCompleteDelegate_Handle(CreateSessionCompleteDelegateHandle);
	}
	MultiplayerOnCreateSessionComplete.Broadcast(bWasSuccessful);
	if (bWasSuccessful) {
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(
				-1,
				15.f,
				FColor::Blue,
				FString::Printf(TEXT("Created session: %s"), *SessionName.ToString())
			);
		}
		//OpenLobby();

	}
	else {
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(
				-1,
				15.f,
				FColor::Red,
				FString::Printf(TEXT("Failed to create Session!!"))
			);
		}
	}
}

void UMultiPlayerSessionSubSystem::OpenLobby()
{
	UWorld* World = GetWorld();
	if (World) {
		//找到关卡，并开启一个listen服务器，等待其他玩家的加入
		World->ServerTravel("/Game/ThirdPerson/Maps/Lobby?listen");
	}
}

void UMultiPlayerSessionSubSystem::onFindSessionComplete(bool bWasSuccessful)
{

}

void UMultiPlayerSessionSubSystem::JoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result)
{

}

void UMultiPlayerSessionSubSystem::DestroySessionComplete(FName SessionName, bool bWasSuccessful)
{
}

void UMultiPlayerSessionSubSystem::StartSessionComplete(FName SessionName, bool bWasSuccessful)
{
}
