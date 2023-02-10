#pragma once
#include "UPanelWidget.h"
#include "UHorizontalBoxSlot.h"

class UHorizontalBox : public UPanelWidget
{
public:
	static UE4::UClass* StaticClass();

	UHorizontalBoxSlot* AddChildToHorizontalBox(UWidget* Content);
};