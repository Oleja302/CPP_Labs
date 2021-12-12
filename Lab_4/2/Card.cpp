#include "Card.h"

Card::Card() : Card(0, L"??") {}
Card::Card(int newPower, wstring newSurface) : power(newPower), surface(newSurface) {}
void Card::SetPower(int power) { this->power = power; }
void Card::SetSurface(wstring surface) { this->surface = surface; }
int Card::GetPower() { return this->power; }
wstring Card::GetSurface() { return this->surface; }
