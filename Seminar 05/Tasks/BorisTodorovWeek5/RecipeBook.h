#pragma once
#include "Recipe.h"
class RecipeBook
{
private:
	Recipe* recipes;
	int recipeCount;
	int recipeCapacity;
public:
	RecipeBook();
	~RecipeBook();
	RecipeBook(const RecipeBook&);
	RecipeBook& operator=(const RecipeBook&);
	void addNewRecipe(const Recipe&);
	void removeRecipe(int);
	Recipe findRecipe(int) const;
	Recipe findRecipeByName(const std::string&) const;
	void printAllRecipes() const;
	void filterRecipesByIngredient(const Ingredient&) const;
};

