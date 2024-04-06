// Fill out your copyright notice in the Description page of Project Settings.


#include "Menu.h"
#include "Components/Button.h"
#include "MultiPlayerSessionSubSystem.h"
void UMenu::MenuSetUp(int32 NumOfPublicConnections, FString FMatchType)
{
	ThisClass::NumPublicConnections = NumOfPublicConnections;
	UMenu::MatchType = FMatchType;
	AddToViewport();
	SetVisibility(ESlateVisibility::Visible);
	bIsFocusable = true;

	UWorld* World = GetWorld();
	if (World) {
		APlayerController* PlayerController = World->GetFirstPlayerController();
		if (PlayerController) {
			FInputModeUIOnly InputModeData;
			InWidgetToFocus = TakeWidget();
			InputModeData.SetWidgetToFocus(InWidgetToFocus);
			InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
			PlayerController->SetInputMode(InputModeData);
			PlayerController->SetShowMouseCursor(true);
		}
		UGameInstance* Game =  GetGameInstance();
		if (Game) {
			MultiPlayerSessionSubSystem = Game->GetSubsystem<UMultiPlayerSessionSubSystem>();
		}
		if (MultiPlayerSessionSubSystem) {
			MultiPlayerSessionSubSystem->MultiplayerOnCreateSessionComplete.AddDynamic(this, &ThisClass::OnCreateSession);
		}
	}
}

bool UMenu::Initialize()
{
	if (!Super::Initialize()) {
		return false;
	}

	if (HostButton) {
		HostButton->OnClicked.AddDynamic(this, &ThisClass::HostButtonClicked);
	}

	if (JoinButton) {
		JoinButton->OnClicked.AddDynamic(this, &ThisClass::JoinButtonClicked);
	}

	return true;
}

//这个方法没用
void UMenu::NativeDestruct()
{
	MenuTearDown();	
	Super::NativeDestruct();
}

void UMenu::OnCreateSession(bool bWasSuccessful)
{
	if (bWasSuccessful) {
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(
				-1,
				15.f,
				FColor::Blue,
				FString(TEXT("SessionCreate Successfull!!!"))
			);
		}
		OpenLobby();
	}
	else {
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(
				-1,
				15.f,
				FColor::Red,
				FString(TEXT("SessionCreate Failed!!!"))
			);
		}
	}
}

void UMenu::HostButtonClicked()
{
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(
			-1,
			15.f,
			FColor::Yellow,
			FString(TEXT("HostButton Clicked"))
		);
	}
	if (!MultiPlayerSessionSubSystem) return;
	MultiPlayerSessionSubSystem->CreateSession(NumPublicConnections,MatchType);
	MenuTearDown();
}

void UMenu::JoinButtonClicked()
{
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(
			-1,
			15.f,
			FColor::Yellow,
			FString(TEXT("JoinButton Clicked 12333"))
		);
	}
	if (!MultiPlayerSessionSubSystem) return;
}

void UMenu::OpenLobby()
{
	UWorld* World = GetWorld();
	if (World) {
		//找到关卡，并开启一个listen服务器，等待其他玩家的加入
		World->ServerTravel("/Game/ThirdPerson/Maps/Lobby?listen");
	}
}

void UMenu::MenuTearDown() {
	RemoveFromParent();
	UWorld* World = GetWorld();
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(
			-1,
			15.f,
			FColor::Yellow,
			FString(TEXT("Mode mode mode 123123"))
		);
	}
	if (World) {
		APlayerController* PlayerController = World->GetFirstPlayerController();
		if (PlayerController) {
			if (GEngine) {
				GEngine->AddOnScreenDebugMessage(
					-1,
					15.f,
					FColor::Yellow,
					FString(TEXT("Mode mode mode"))
				);
			}
			FInputModeGameOnly InputModeData;
			PlayerController->SetInputMode(InputModeData);
			PlayerController->SetShowMouseCursor(false);
		}
	}
}