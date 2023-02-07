#include "ModMenu.h"

UE4::UClass* ModMenu::WidgetBlueprintGeneratedClass()
{
	auto ptr = UE4::UObject::FindClass("WidgetBlueprintGeneratedClass UMG_ModMenu.UMG_ModMenu_C");
	return ptr;
}

ModMenuItem* ModMenu::AddItem(UE4::FString ItemText)
{
	auto fn = UE4::UObject::FindObject<UE4::UFunction>("Function UMG_ModMenu.UMG_ModMenu_C.AddItem");
	struct
	{
		UE4::FString ItemText;
		ModMenuItem* Item;
	}params;
	params.ItemText = ItemText;
	this->ProcessEvent(fn, &params);
	return params.Item;
}