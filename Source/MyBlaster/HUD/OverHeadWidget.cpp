// Fill out your copyright notice in the Description page of Project Settings.


#include "OverHeadWidget.h"

#include "Components/TextBlock.h"

void UOverHeadWidget::SetDisplayText(FString TextToDisplay)
{
	if (DisplayText)
	{
		DisplayText->SetText(FText::FromString(TextToDisplay));
	}
}

void UOverHeadWidget::ShowPlayerNetRole(APawn* InPawn)
{
	ENetRole RemoteRole = InPawn->GetRemoteRole();
	FString Role;
	switch (RemoteRole)
	{
	case ENetRole::ROLE_Authority:
		Role = FString("ROLE_Authority");
		break;
	case ENetRole::ROLE_AutonomousProxy:
		Role = FString("ROLE_AutonomousProxy");
		break;
	case ENetRole::ROLE_SimulatedProxy:
		Role = FString("ROLE_SimulatedProxy");
		break;
	case ENetRole::ROLE_None:
		Role = FString("ROLE_None");
		break;
	}
	const FString RemoteRoleString = FString::Printf(TEXT("Remote Role: %s"), *Role);
	SetDisplayText(RemoteRoleString);
}

void UOverHeadWidget::BeginDestroy()
{
	Super::BeginDestroy();
	RemoveFromParent();
}
