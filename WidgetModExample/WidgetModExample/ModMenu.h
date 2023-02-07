#pragma once
#include "UWidget.h"
#include "UUserWidget.h"
#include "ModMenuItem.h"
#include "UVerticalBox.h"
#include "UTextBlock.h"
#include "UKismetTextLibrary.h"
#include "UGameplayStatics.h"

// Class reflecting UMG_CustomMenu in the LogicMod
class ModMenu : public UUserWidget
{
public:
	static UE4::UClass* WidgetBlueprintGeneratedClass();

	ModMenuItem* AddItem(UE4::FString ItemText);
};