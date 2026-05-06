#include <iostream>
#include "TCoffe.h"
#include <fstream>
#include <sstream>
#include <vector>

void writeDefaultCoffees();
void readFile(std::string filename, std::vector<TCoffe>& coffe_vector);

int main()
{
	//writeDefaultCoffees();
	std::vector<TCoffe> default_coffees;
	readFile("default_coffees.txt", default_coffees);

	for (int i = 0; i < default_coffees.size(); i++)
	{
		default_coffees[i].save(std::cout);
	}

	std::cin.get();
}

void writeDefaultCoffees() {
	TCoffe kawa_espresso("espresso", 50, 25, 0);
	TCoffe kawa_czarna("Kawa czarna", 250, 25, 0);
	TCoffe kawa_biala("Kawa biala", 100, 25, 150);
	

	std::ofstream plik("default_coffees.txt");
	kawa_espresso.save(plik);
	kawa_czarna.save(plik);
	kawa_biala.save(plik);
}

void readFile(std::string filename, std::vector<TCoffe>& coffe_vector) {
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

		TCoffe kawa(name, water_amount, coffe_amount, milk_amount);

		coffe_vector.push_back(kawa);
	}
}

