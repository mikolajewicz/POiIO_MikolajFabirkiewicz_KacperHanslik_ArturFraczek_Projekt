#pragma once
#include <string>

class TCoffee
{
private:
	std::string coffee_name;
	int water_amount = 0;
	int coffee_amount = 0;
	int milk_amount = 0;

public:
	TCoffee();
	TCoffee(std::string name, int water, int coffee, int milk);
	int getWaterAmount() const;
	int getCoffeeAmount() const;
	int getMilkAmount() const;
	std::string getName() const;
	void save(std::ostream& out) const;
	

	void defineCoffeeAmount(int new_amount);
	void defineWaterAmount(int new_amount);
	void defineMilkAmount(int new_amount);
	void defineCoffeName(std::string name);

	void showCoffeeContents();

};
