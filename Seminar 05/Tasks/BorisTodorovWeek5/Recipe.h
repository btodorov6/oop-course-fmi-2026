#pragma once
#include "Ingredient.h"
class Recipe
{
private:
	Ingredient* ingredientList;
	std::string name;
	std::string instructions;
	int ingredientsCount;
	int ingredientsCapacity;
	int id;
	static int idCounter;
public:
	Recipe();
	Recipe(const std::string& recipeName, const std::string& recipeInstructions);
	Recipe(const Recipe&);
	Recipe& operator=(const Recipe&);	
	~Recipe();
	void addIngredient(const Ingredient&);
	void removeIngredient(const std::string&);
	bool containsIngredient(const std::string&) const;
	void printRecipe() const;
	int getId() const;
	std::string getName() const;
};

