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
	int getWaterAmount();
	int getCoffeeAmount();
	int getMilkAmount();
	std::string getName();
	void save(std::ostream& out);
};
