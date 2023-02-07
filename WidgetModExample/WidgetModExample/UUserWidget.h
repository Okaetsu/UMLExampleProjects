#pragma once
#include "UWidget.h"

#ifndef UUSERWIDGET
#define UUSERWIDGET

class UWidget;

class UUserWidget : public UWidget
{
public:
	static UE4::UClass* StaticClass();

	void AddToViewport(int ZIndex);
};

#endif