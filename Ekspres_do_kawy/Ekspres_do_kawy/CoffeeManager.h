#pragma once

#include <vector>
#include <string>
#include "TCoffee.h"

class CoffeeManager
{
	static void writeDefaultCoffees(const std::string& filename);
	static void readFile(std::string filename, std::vector<TCoffee>& coffe_vector);
	static void saveVector(std::string filename, std::vector<TCoffee> coffe_vector);
	static void ensureDefaultCoffeeFileExists(const std::string& filename);
};



