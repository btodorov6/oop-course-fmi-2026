#pragma once
#include <string>
enum class unit
{
	g,
	ml,
	Kg,
	L
};
class Ingredient
{
private:
	std::string name;
	int amount;
	unit measurementUnit;
public:
	std::string getName() const;
	Ingredient();
	Ingredient(const std::string&, int, unit);
	int getAmount() const;
	unit getUnit() const;
};

