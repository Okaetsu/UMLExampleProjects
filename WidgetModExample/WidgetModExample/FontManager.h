#pragma once
#include "CoreUObject_classes.hpp"
#include "UFont.h"

/*
* Custom class for easier management of font objects
*/
class FontManager
{
public:
	static UFont* Get(std::string fontFamily);
private:
	static UFont* Import(std::string fontFamily);

	static UFont* Find(std::string fontFamily);
};