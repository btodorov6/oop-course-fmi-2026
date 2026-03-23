#include "RecipeBook.h"
using std::string;

RecipeBook::RecipeBook() 
	:recipeCount(0), recipeCapacity(10)
{
	recipes = new Recipe[recipeCapacity];
}

RecipeBook::~RecipeBook()
{
	delete[] recipes;
}

RecipeBook::RecipeBook(const RecipeBook& other)
	:recipeCount(other.recipeCount), recipeCapacity(other.recipeCapacity)
{
	recipes = new Recipe[recipeCapacity];
	for (int i = 0;i < recipeCount;i++)
	{
		recipes[i] = other.recipes[i];
	}
}
RecipeBook& RecipeBook::operator=(const RecipeBook& other)
{
	if (this != &other)
	{
		recipeCount = other.recipeCount;
		recipeCapacity = other.recipeCapacity;
		delete[] recipes;
		recipes = new Recipe[recipeCapacity];
		for (int i = 0;i < recipeCount;i++)
		{
			recipes[i] = other.recipes[i];
		}
	}
	return *this;
}

void RecipeBook::addNewRecipe(const Recipe& newRecipe)
{
	if (recipeCount == recipeCapacity)
	{
		recipeCapacity += 10;
		Recipe* temp = new Recipe[recipeCapacity];
		for (int i = 0;i < recipeCount;i++)
		{
			temp[i] = recipes[i];
		}
		delete[] recipes;
		recipes = temp;
	}
	recipes[recipeCount++] = newRecipe;
}

void RecipeBook::removeRecipe(int idToRemove)
{
	for (int i = 0;i < recipeCount;i++)
	{
		if (recipes[i].getId() == idToRemove)
		{
			recipeCount--;
			for (int j = i; j < recipeCount; ++j)
			{
				recipes[j] = recipes[j + 1];
			}
			return;
		}
	}
}
Recipe RecipeBook::findRecipe(int id) const
{
	for (int i = 0;i < recipeCount;i++)
	{
		if (recipes[i].getId() == id)
		{
			return recipes[i];
		}
	}
	return Recipe();
}
Recipe RecipeBook::findRecipeByName(const string& nameToFind) const
{
	for (int i = 0;i < recipeCount;i++)
	{
		if (recipes[i].getName() == nameToFind)
		{
			return recipes[i];
		}
	}
	return Recipe();
}
void RecipeBook::printAllRecipes() const
{
	for (int i = 0;i < recipeCount;i++)
	{
		recipes[i].printRecipe();
	}
}
void RecipeBook::filterRecipesByIngredient(const Ingredient& ingredientToFind) const
{
	for (int i = 0;i < recipeCount;i++)
	{
		if (recipes[i].containsIngredient(ingredientToFind.getName()))
		{
			recipes[i].printRecipe();
		}
	}
}