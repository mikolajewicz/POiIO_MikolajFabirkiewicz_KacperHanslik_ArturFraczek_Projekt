#include "TCoffe.h"
#include <iostream>
#include <string>

TCoffe::TCoffe(std::string name, int water, int coffe, int milk) {
	coffe_name = name;
	water_amount = water;
	coffe_amount = coffe;
	milk_amount = milk;
}

TCoffe::TCoffe(){
	coffe_name = "";
	water_amount = 0;
	coffe_amount = 0;
	milk_amount = 0;
}

int TCoffe::getWaterAmount(){
	return water_amount;
}

int TCoffe::getCoffeAmount(){
	return coffe_amount;
}

int TCoffe::getMilkAmount(){
	return milk_amount;
}

std::string TCoffe::getName(){
	return coffe_name;
}

void TCoffe::save(std::ostream& out) {
	out << coffe_name << ";"
		<< water_amount << ";"
		<< coffe_amount << ";"
		<< milk_amount << "\n";
}

