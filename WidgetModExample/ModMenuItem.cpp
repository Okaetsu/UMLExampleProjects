#include "ModMenuItem.h"

UE4::UClass* ModMenuItem::WidgetBlueprintGeneratedClass()
{
	auto ptr = UE4::UObject::FindClass("WidgetBlueprintGeneratedClass UMG_ModMenuItem.UMG_ModMenuItem_C");
	return ptr;
}

void ModMenuItem::AddEvent(WidgetEvent::EventType eventType, std::function<void()> cb)
{
	auto eventName = WidgetEvent::GetName(eventType);
	ObjectEventManager::RegisterEvent(this, eventName, cb);
}

UImage* ModMenuItem::GetBackgroundImage()
{
	UImage* BackgroundImage;
	UE4::GetVariable<UImage*>(this, "BackgroundImage", BackgroundImage);
	return BackgroundImage;
}

UTextBlock* ModMenuItem::GetTextBlock()
{
	UTextBlock* TextBlock;
	UE4::GetVariable<UTextBlock*>(this, "MainTextBlock", TextBlock);
	return TextBlock;
}

void ModMenuItem::SetItemText(UE4::FString String)
{
	auto fn = UE4::UObject::FindObject<UE4::UFunction>("Function UMG_ModMenuItem.UMG_ModMenuItem_C.SetItemText");
	struct
	{
		UE4::FString String;
	}params;
	params.String = String;
	this->ProcessEvent(fn, &params);
}