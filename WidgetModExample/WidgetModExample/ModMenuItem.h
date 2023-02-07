#pragma once
#include <functional>
#include "UUserWidget.h"
#include "UTextBlock.h"
#include "UImage.h"
#include "WidgetEvent.h"
#include "ObjectEventManager.h"

// Class reflecting UMG_ModMenuItem in the LogicMod
class ModMenuItem : public UUserWidget
{
public:
	static UE4::UClass* WidgetBlueprintGeneratedClass();

	void AddEvent(WidgetEvent::EventType eventType, std::function<void()> cb);

	UImage* GetBackgroundImage();

	UTextBlock* GetTextBlock();

	void SetItemText(UE4::FString String);
};