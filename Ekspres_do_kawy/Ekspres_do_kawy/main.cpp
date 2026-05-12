#include <iostream>
#include "TCoffee.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <limits>

void writeDefaultCoffees();
void readFile(std::string filename, std::vector<TCoffee>& coffe_vector);
void saveVector(std::string filename, std::vector<TCoffee> coffe_vector);
TCoffee Personalize(std::vector<TCoffee> coffe_vector, int _id);
void printFile(std::string filename);

int main()
{
	std::ifstream plik_domyslnych("default_coffees.txt");

	if (!plik_domyslnych) {
		writeDefaultCoffees();
	}

	std::vector<TCoffee> default_coffees_vector;
	readFile("default_coffees.txt", default_coffees_vector);

	TCoffee NewCoffee = Personalize(default_coffees_vector, 2);

	std::cout << "\nNacisnij Enter, aby zakonczyc...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
}

void writeDefaultCoffees() {
	TCoffee kawa_espresso("espresso", 50, 25, 0);
	TCoffee kawa_czarna("Kawa czarna", 250, 25, 0);
	TCoffee kawa_biala("Kawa biala", 100, 25, 150);
	TCoffee kawa_double_espresso("Double Espresso", 100, 50, 0);
	TCoffee kawa_cappuccino("Cappuccino", 100, 25, 150);
	TCoffee kawa_latte_macchiato("Latte Macchiato", 50, 25, 250);
	TCoffee kawa_americano("Americano", 350, 25, 0);
	TCoffee kawa_flat_white("Flat White", 100, 50, 150);


	std::ofstream plik("default_coffees.txt");

	kawa_espresso.save(plik);
	kawa_czarna.save(plik);
	kawa_biala.save(plik);

	kawa_double_espresso.save(plik);
	kawa_cappuccino.save(plik);
	kawa_latte_macchiato.save(plik);
	kawa_americano.save(plik);
	kawa_flat_white.save(plik);

	plik.close();
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
	plik.close();
}

TCoffee Personalize(std::vector<TCoffee> coffe_vector, int _id) {
	
	// zapis do wektora ulubionych
	std::vector<TCoffee> favourite_coffees_vector;
	readFile("favourite_coffees.txt", favourite_coffees_vector);
	
	std::string odpowiedz = "N";

	//odczyt oraz zmiana wartości
	TCoffee Kawa = coffe_vector[_id];
	int nowa_ilosc_kawy;
	int nowa_ilosc_wody;
	int nowa_ilosc_mleka;

	std::cout << "Aktualna ilosc kawy: " << Kawa.getCoffeeAmount() << "\n";
	std::cout << "Aktualna ilosc wody: " << Kawa.getWaterAmount() << "\n";
	std::cout << "Aktualna ilosc mleka: " << Kawa.getMilkAmount() << "\n\n";
	
	std::cout << "Nowa ilosc wody: ";
	std::cin >> nowa_ilosc_wody;
	Kawa.defineWaterAmount(nowa_ilosc_wody);

	std::cout << "Nowa ilosc kawy: ";
	std::cin >> nowa_ilosc_kawy;
	Kawa.defineCoffeeAmount(nowa_ilosc_kawy);

	std::cout << "Nowa ilosc mleka: ";
	std::cin >> nowa_ilosc_mleka;
	Kawa.defineMilkAmount(nowa_ilosc_mleka);


	
	std::cout << "Czy chcesz zapisac swoj wybor? T/N: ";
	std::cin >> odpowiedz;

	if (odpowiedz == "T" || odpowiedz == "t") {
		
		bool exists = true;
		std::string name;

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		while (exists == true) {
			exists = false;
			std::cout << "Wpisz nazwe nowej kawy: ";
			std::getline(std::cin, name);

			//sprawdzenie czy juz taka kawa istnieje

			int count = favourite_coffees_vector.size();
			for (int i = 0; i < count && exists == false; i++) {
				if (name == favourite_coffees_vector[i].getName()) {
					exists = true;
					std::cout << "Taka kawa juz istnieje, ";
				}
				else {
					exists = false;
				}

			}
		}

		Kawa.defineCoffeName(name);

		favourite_coffees_vector.push_back(Kawa);

		// zapis do pliku ulubionych
		saveVector("favourite_coffees.txt", favourite_coffees_vector);
	}

	Kawa.showCoffeeContents();
	printFile("favourite_coffees.txt");
	return Kawa;


}

void printFile(std::string filename) {
	std::vector<TCoffee> wektor;
	readFile(filename, wektor);
	int count = wektor.size();

	std::cout << "\n";
	for (int i = 0; i < count; i++) {
		std::cout << wektor[i].getName() << "\n";
	}
}