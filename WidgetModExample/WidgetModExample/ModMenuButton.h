#pragma once
#include <functional>
#include "UUserWidget.h"
#include "WidgetEvent.h"
#include "ObjectEventManager.h"

class ModMenuButton : public UUserWidget
{
public:
	static UE4::UClass* WidgetBlueprintGeneratedClass();

	void AddEvent(WidgetEvent::EventType eventType, std::function<void()> cb);
};