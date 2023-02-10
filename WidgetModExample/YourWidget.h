#pragma once
#include "UUserWidget.h"

/*
* Template for replicating any widgets from a game / mod
* Make sure the Widget class you replicate is inheriting from public UUserWidget!
*/

class YourWidget : public UUserWidget
{
public:
	static UE4::UClass* StaticClass();
};