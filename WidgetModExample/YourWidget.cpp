#include "YourWidget.h"

UE4::UClass* YourWidget::StaticClass()
{
	/*
	* You can use FModel to figure out where the Widget you want is located
	* /Game/ is equivalent to the Content folder, so leave '/Game/' as is and add your path after it, e.g /Game/GUI/Widgets/UMG_CheckBox.UMG_CheckBox_C
	* UMG_CheckBox.UMG_CheckBox_C at the end of the above example is the package (UMG_CheckBox.uasset)
	* I recommend making a new class rather than editing this one. That way you can use this class as a reference when making new ones
	*/
	const std::wstring InstancePath = L"/Game/yourpathhere/yourwidgetname.yourwidgetname_C";
	static UE4::UClass* InstanceClass = UE4::UClass::LoadClassFromString(InstancePath.c_str(), false);
	return InstanceClass;
}