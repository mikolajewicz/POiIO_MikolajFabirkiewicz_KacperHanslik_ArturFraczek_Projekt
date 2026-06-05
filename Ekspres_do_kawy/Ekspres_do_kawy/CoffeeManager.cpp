#include "CoffeeManager.h"

#include <fstream>
#include <sstream>

void CoffeeManager::writeDefaultCoffees(const std::string& filename)
{
	std::ofstream plik(filename);

	if (!plik)
	{
		return;
	}

	TCoffee kawa_espresso("espresso", 50, 25, 0);
	TCoffee kawa_czarna("Kawa czarna", 250, 25, 0);
	TCoffee kawa_biala("Kawa biala", 100, 25, 150);
	TCoffee kawa_double_espresso("Double Espresso", 100, 50, 0);
	TCoffee kawa_cappuccino("Cappuccino", 100, 25, 150);
	TCoffee kawa_latte_macchiato("Latte Macchiato", 50, 25, 250);
	TCoffee kawa_americano("Americano", 350, 25, 0);
	TCoffee kawa_flat_white("Flat White", 100, 50, 150);

	kawa_espresso.save(plik);
	kawa_czarna.save(plik);
	kawa_biala.save(plik);
	kawa_double_espresso.save(plik);
	kawa_cappuccino.save(plik);
	kawa_latte_macchiato.save(plik);
	kawa_americano.save(plik);
	kawa_flat_white.save(plik);
}
void CoffeeManager::readFile(std::string filename, std::vector<TCoffee>& coffe_vector) {
	std::ifstream plik(filename);

	std::string linia;

	while (std::getline(plik, linia)) {
		std::stringstream ss(linia);

		std::string name;
		std::string water_text;
		std::string coffe_text;
		std::string milk_text;

		std::getline(ss, name, ';');
		std::getline(ss, water_text, ';');
		std::getline(ss, coffe_text, ';');
		std::getline(ss, milk_text, ';');

		int water_amount = std::stoi(water_text);
		int coffe_amount = std::stoi(coffe_text);
		int milk_amount = std::stoi(milk_text);

		TCoffee kawa(name, water_amount, coffe_amount, milk_amount);

		coffe_vector.push_back(kawa);
	}
}
void CoffeeManager::saveVector(std::string filename, std::vector<TCoffee> coffe_vector) {
	int count = coffe_vector.size();

	std::ofstream plik(filename);

	for (int i = 0; i < count; i++) {
		coffe_vector[i].save(plik);
	}
	plik.close();
}
void CoffeeManager::ensureDefaultCoffeeFileExists(const std::string& filename)
{
	std::ifstream plik(filename);

	if (!plik)
	{
		writeDefaultCoffees(filename);
	}
}

void CoffeeManager::ensureFavouriteCoffeeFileExists(const std::string& filename)
{
	std::ifstream plik(filename);

	if (!plik)
	{
		writeDefaultCoffees(filename);
	}
}







