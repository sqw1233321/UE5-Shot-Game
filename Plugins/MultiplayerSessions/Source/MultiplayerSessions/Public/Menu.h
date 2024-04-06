// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MultiPlayerSessionSubSystem.h"
#include "Menu.generated.h"

/**
 *
 */
UCLASS()
class MULTIPLAYERSESSIONS_API UMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void MenuSetUp(int32 NumPublicConnections = 4, FString MatchType = FString(TEXT("FreeForAll")));

protected:
	virtual bool Initialize() override;
	virtual void NativeDestruct() override;

	UFUNCTION()
	void OnCreateSession(bool bWasSuccessful);

private:
	int32 NumPublicConnections{ 4 };
	FString MatchType{ TEXT("FreeForAll") };

	void OpenLobby();
	void MenuTearDown();

	TSharedPtr<SWidget> InWidgetToFocus;

	UPROPERTY(meta = (BindWidget))
	class UButton* HostButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* JoinButton;

	UFUNCTION()
	void HostButtonClicked();

	UFUNCTION()
	void JoinButtonClicked();

	//The subsystem designed to handle all online session functionality
	class UMultiPlayerSessionSubSystem* MultiPlayerSessionSubSystem;
};
