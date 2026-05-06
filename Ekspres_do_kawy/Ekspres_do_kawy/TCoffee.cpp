#include "TCoffee.h"
#include <iostream>
#include <string>

TCoffee::TCoffee(std::string name, int water, int coffee, int milk) {
	coffee_name = name;
	water_amount = water;
	coffee_amount = coffee;
	milk_amount = milk;
}

TCoffee::TCoffee(){
	coffee_name = "";
	water_amount = 0;
	coffee_amount = 0;
	milk_amount = 0;
}

int TCoffee::getWaterAmount(){
	return water_amount;
}

int TCoffee::getCoffeeAmount(){
	return coffee_amount;
}

int TCoffee::getMilkAmount(){
	return milk_amount;
}

std::string TCoffee::getName(){
	return coffee_name;
}

void TCoffee::save(std::ostream& out) {
	out << coffee_name << ";"
		<< water_amount << ";"
		<< coffee_amount << ";"
		<< milk_amount << "\n";
}

