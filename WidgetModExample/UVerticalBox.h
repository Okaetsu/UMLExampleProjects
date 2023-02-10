#pragma once
#include "UPanelWidget.h"
#include "UVerticalBoxSlot.h"

class UVerticalBox : public UPanelWidget
{
public:
	static UE4::UClass* StaticClass();

	UVerticalBoxSlot* AddChildToVerticalBox(UWidget* Content);
};