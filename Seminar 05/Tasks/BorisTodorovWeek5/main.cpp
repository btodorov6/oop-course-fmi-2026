#include <iostream>
#include "Ingredient.h"
#include "Recipe.h"
#include "RecipeBook.h"
#include <print>
using std::print;
using std::println;
int main()
{
	Ingredient flour("Flour", 500, unit::g);
	Ingredient eggs("Eggs", 300, unit::g);
	Ingredient milk("Milk", 250, unit::ml);
	Ingredient sugar("Sugar", 150, unit::g);

	Recipe pancakes("Pancakes", "Pancakes are the best breakfast!");
	Recipe cake("Cake", "Happy birthday!");

	pancakes.addIngredient(flour);
	pancakes.addIngredient(eggs);
	pancakes.addIngredient(milk);

	cake.addIngredient(flour);
	cake.addIngredient(eggs);
	cake.addIngredient(milk);
	cake.addIngredient(sugar);

	RecipeBook myBook;
	myBook.addNewRecipe(pancakes);
	myBook.addNewRecipe(cake);

	println("\n\n---All Recipes---");
	myBook.printAllRecipes();

	println("\n\n---Filtered by sugar---");
	myBook.filterRecipesByIngredient(sugar);

	myBook.removeRecipe(1);

	println("\n\n---Removed recipe with id 1---");
	myBook.printAllRecipes();

	return 0;
}