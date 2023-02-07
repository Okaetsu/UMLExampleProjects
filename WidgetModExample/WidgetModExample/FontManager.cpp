#include "FontManager.h"

std::vector<UFont*> loadedFonts;

UFont* FontManager::Import(std::string fontFamily)
{
	auto font = Find(fontFamily);
	if (font != nullptr)
	{
		loadedFonts.push_back(font);
		return font;
	}
	return nullptr;
}

UFont* FontManager::Get(std::string fontFamily)
{
	for (const auto& f : loadedFonts)
	{
		if (f->GetName() == fontFamily)
		{
			return f;
		}
	}

	auto f = Import(fontFamily);

	if (f != nullptr)
	{
		return f;
	}
	
	return nullptr;
}

UFont* FontManager::Find(std::string fontFamily)
{
	auto v = UE4::UWorld::GetAllObjectsOfType<UFont>(UFont::StaticClass(), true);
	for (const auto& f : v)
	{
		if (f->GetClass()->GetName() == "Font")
		{
			if (f->GetName() == fontFamily)
			{
				return f;
			}
		}
	}
	return nullptr;
}