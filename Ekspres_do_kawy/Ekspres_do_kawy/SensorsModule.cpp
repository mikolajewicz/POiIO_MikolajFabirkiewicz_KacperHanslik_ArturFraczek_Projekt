#include "SensorsModule.h"
#include <iostream>

SensorsModule::SensorsModule(int initial_water, int initial_beans) 
    : water_level(initial_water), beans_amount(initial_beans), grounds_count(0) {}

bool SensorsModule::canBrew(TCoffe& coffee) {
    if (water_level < coffee.getWaterAmount()) {
        std::cout << "ALARM: Brak wody.\n";
        return false;
    }
    if (beans_amount < coffee.getCoffeAmount()) {
        std::cout << "ALARM: Brak ziaren.\n";
        return false;
    }
    if (grounds_count >= MAX_GROUNDS) {
        std::cout << "ALARM: Oproznij pojemnik na fusy.\n";
        return false;
    }
    return true;
}

void SensorsModule::processBrewing(TCoffe& coffee) {
    if (canBrew(coffee)) {
        water_level -= coffee.getWaterAmount();
        beans_amount -= coffee.getCoffeAmount();
        grounds_count++; // Inkrementacja fusów co każdą kawę
        
        std::cout << "Parzenie: " << coffee.getName() << " zakonczone.\n";
    }
}

void SensorsModule::refillWater(int amount) { water_level += amount; }
void SensorsModule::refillBeans(int amount) { beans_amount += amount; }
void SensorsModule::emptyGrounds() { grounds_count = 0; }

void SensorsModule::statusCheck() {
    std::cout << "--- STATUS SYSTEMU ---\n"
              << "Woda: " << water_level << " ml\n"
              << "Ziarna: " << beans_amount << " g\n"
              << "Fusy: " << grounds_count << "/" << MAX_GROUNDS << "\n"
              << "----------------------\n";
}