#pragma once
#include "UWidget.h"

// Parent class of HorizontalBox and VerticalBox
class UPanelWidget : public UWidget
{
public:
	static UE4::UClass* StaticClass();

	void AddChild(UWidget* Content);

	UWidget* GetChildAt(int Index);

	bool RemoveChild(UWidget* Content);

	bool RemoveChildAt(int Index);
};