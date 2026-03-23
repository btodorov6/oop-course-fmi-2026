#include "Ingredient.h"
using std::string;
string Ingredient::getName() const
{
	return name;
}
int Ingredient::getAmount() const
{
	return amount;
}
unit Ingredient::getUnit() const
{
	return measurementUnit;
}
Ingredient::Ingredient() = default;

Ingredient::Ingredient(const string& _name, int _amount, unit _measurementUnit)
	:name(_name), amount(_amount), measurementUnit(_measurementUnit)
{ 

}