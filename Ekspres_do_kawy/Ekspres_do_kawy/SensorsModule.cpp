#include "SensorsModule.h"
#include <iostream>

SensorsModule::SensorsModule(int initial_water, int initial_beans) 
    : water_level(initial_water), beans_amount(initial_beans), grounds_count(0) {}

bool SensorsModule::canBrew(std::string& error_msg) {
    if (water_level < MIN_WATER) {
        error_msg = "WODA";
        return false;
    }
    if (beans_amount < MIN_BEANS) {
        error_msg = "ZIARNA";
        return false;
    }
    if (grounds_count >= MAX_GROUNDS) {
        error_msg = "FUSY";
        return false;
    }
    error_msg = "";
    return true;
}

bool SensorsModule::canBrew(std::string& error_msg, TCoffee& coffee) {
    if (!canBrew(error_msg)) return false;

    // Potem sprawdź, czy starczy na konkretny przepis
    if (water_level < coffee.getWaterAmount()) {
        error_msg = "WODA";
        return false;
    }
    if (beans_amount < coffee.getCoffeeAmount()) {
        error_msg = "ZIARNA";
        return false;
    }
    return true;
}


void SensorsModule::processBrewing(TCoffee& coffee) {
    std::string dummy_error;

    if (canBrew(dummy_error, coffee)) {
        water_level -= coffee.getWaterAmount();
        beans_amount -= coffee.getCoffeeAmount();
        grounds_count++; // Inkrementacja fusów co każdą kawę
        
        std::cout << "Parzenie: " << coffee.getName() << " zakonczone.\n";
    }
}

void SensorsModule::refillWater(int amount) { water_level += amount; }
void SensorsModule::refillBeans(int amount) { beans_amount += amount; }
void SensorsModule::emptyGrounds() { grounds_count = 0; }

void SensorsModule::statusCheck() {
    std::cout << "\n--- STATUS SYSTEMU ---\n"
              << "Woda: " << water_level << " ml\n"
              << "Ziarna: " << beans_amount << " g\n"
              << "Fusy: " << grounds_count << "/" << MAX_GROUNDS << "\n"
              << "----------------------\n\n";
}