#include "Recipe.h"
#include <print>
using std::string;
using std::print;
using std::println;

int Recipe::idCounter = 0;

Recipe::Recipe()
	:name(),instructions(),ingredientsCount(0),
	ingredientsCapacity(5),id(++idCounter)
{
	ingredientList = new Ingredient[ingredientsCapacity];
}

Recipe::Recipe(const string& recipeName, const string& recipeInstructions)
	:name(recipeName), instructions(recipeInstructions),
	ingredientsCount(0), ingredientsCapacity(5), id(++idCounter)
{
	ingredientList = new Ingredient[ingredientsCapacity];
}

Recipe::Recipe(const Recipe& other)
	:name(other.name), instructions(other.instructions),
	ingredientsCount(other.ingredientsCount), ingredientsCapacity(other.ingredientsCapacity),
	id(++idCounter)
{
	ingredientList = new Ingredient[ingredientsCapacity];
	for (int i = 0; i < ingredientsCount; ++i)
	{
		ingredientList[i] = other.ingredientList[i];
	}
}

Recipe& Recipe::operator=(const Recipe& other)
{
	if (this != &other)
	{
		id = other.id;
		name = other.name;
		instructions = other.instructions;
		ingredientsCount = other.ingredientsCount;
		ingredientsCapacity = other.ingredientsCapacity;
		delete[] ingredientList;
		ingredientList = new Ingredient[ingredientsCapacity];
		for (int i = 0; i < ingredientsCount; ++i)
		{
			ingredientList[i] = other.ingredientList[i];
		}
	}
	return *this;
}

Recipe::~Recipe()
{
	delete[] ingredientList;
}

void Recipe::addIngredient(const Ingredient& newIngredient)
{
	if (containsIngredient(newIngredient.getName()))
	{
		println("Ingredient is already contained!");
		return;
	}
	if (ingredientsCount == ingredientsCapacity)
	{
		ingredientsCapacity += 5;
		Ingredient* temp = new Ingredient[ingredientsCapacity];
		for (int i = 0;i < ingredientsCount;i++)
		{
			temp[i] = ingredientList[i];
		}
		delete[] ingredientList;
		ingredientList = temp;
	}
	ingredientList[ingredientsCount++] = newIngredient;
}

void Recipe::removeIngredient(const string& name)
{
	for (int i = 0;i < ingredientsCount;++i)
	{
		if (ingredientList[i].getName() == name)
		{
			ingredientList[i] = ingredientList[ingredientsCount-1];
			--ingredientsCount;
			return;
		}
	}
}

bool Recipe::containsIngredient(const string& name) const
{
	for (int i = 0;i < ingredientsCount;++i)
	{
		if (ingredientList[i].getName() == name)
		{
			return true;
		}
	}
	return false;
}

static string measurementUnitToStr(unit msrUnit)
{
	switch (msrUnit)
	{
	case unit::g:
		return "g";
	case unit::Kg:
		return"Kg";
	case unit::ml:
		return "ml";
	case unit::L:
		return "L";
	default:
		return "n/a";
	}
}
void Recipe::printRecipe() const
{
	print("{}. ", id);
	println("{}",name);
	println("---------------------");
	println("{}",instructions);
	print("---Ingredients---\n");
	for (int i = 0;i < ingredientsCount;i++)
	{
		const Ingredient& currIngr = ingredientList[i];
		println("{}. {} {}{}", i + 1, currIngr.getName(), currIngr.getAmount(), measurementUnitToStr(currIngr.getUnit()));
	}
	println("---------------------");
}
int Recipe::getId() const
{
	return id;
}
string Recipe::getName() const
{
	return name;
}