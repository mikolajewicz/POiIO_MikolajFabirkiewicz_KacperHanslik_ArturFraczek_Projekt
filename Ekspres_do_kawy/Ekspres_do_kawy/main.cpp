#include <iostream>
#include "TCoffee.h"
#include <fstream>
#include <sstream>
#include <vector>

void writeDefaultCoffees();
void readFile(std::string filename, std::vector<TCoffee>& coffe_vector);
void saveVector(std::string filename, std::vector<TCoffee> coffe_vector);

int main()
{
	std::ifstream plik_domyslnych("default_coffees.txt");

	if (!plik_domyslnych) {
		writeDefaultCoffees();
	}

	std::vector<TCoffee> default_coffees_vector;
	readFile("default_coffees.txt", default_coffees_vector);

	std::ifstream plik_ulubionych("favourite_coffees.txt");
	saveVector("favourite_coffees", default_coffees_vector);

	for (int i = 0; i < default_coffees_vector.size(); i++)
	{
		default_coffees_vector[i].save(std::cout);
	}

	std::cin.get();
}

void writeDefaultCoffees() {
	TCoffee kawa_espresso("espresso", 50, 25, 0);
	TCoffee kawa_czarna("Kawa czarna", 250, 25, 0);
	TCoffee kawa_biala("Kawa biala", 100, 25, 150);
	

	std::ofstream plik("default_coffees.txt");
	kawa_espresso.save(plik);
	kawa_czarna.save(plik);
	kawa_biala.save(plik);
}

void readFile(std::string filename, std::vector<TCoffee>& coffe_vector) {
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

void saveVector(std::string filename, std::vector<TCoffee> coffe_vector) {
	int count = coffe_vector.size();

	std::ofstream plik(filename);

	for (int i = 0; i < count; i++) {
		coffe_vector[i].save(plik);
	}

}

