#pragma once
#include "Deck.h"
#include "IFormattable.h"

class AdapterClass : public Deck, public IFormattable
{
public:
	AdapterClass(Deck* deck);
	wstring format() override;
};
