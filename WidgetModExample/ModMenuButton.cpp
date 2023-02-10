#include "ModMenuButton.h"

UE4::UClass* ModMenuButton::WidgetBlueprintGeneratedClass()
{
	auto ptr = UE4::UObject::FindClass("WidgetBlueprintGeneratedClass UMG_ModMenuButton.UMG_ModMenuButton_C");
	return ptr;
}

void ModMenuButton::AddEvent(WidgetEvent::EventType eventType, std::function<void()> cb)
{
	auto eventName = WidgetEvent::GetName(eventType);
	ObjectEventManager::RegisterEvent(this, eventName, cb);
}