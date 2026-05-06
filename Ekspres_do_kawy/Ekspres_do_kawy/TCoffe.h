#pragma once
#include <string>

class TCoffe
{
private:
	std::string coffe_name;
	int water_amount = 0;
	int coffe_amount = 0;
	int milk_amount = 0;

public:
	TCoffe();
	TCoffe(std::string name, int water, int coffe, int milk);
	int getWaterAmount();
	int getCoffeAmount();
	int getMilkAmount();
	std::string getName();
	void save(std::ostream& out);
};
