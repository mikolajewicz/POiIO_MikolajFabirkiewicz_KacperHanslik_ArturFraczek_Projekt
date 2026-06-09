#pragma once
#include "TCoffee.h"

class SensorsModule {
private:
    
    int water_level;     // [ml]
    int beans_amount;    // [g]
    int grounds_count;   // [licznik kaw]
  

    // Progi krytyczne (Thresholds)
    const int MIN_WATER = 50;
    const int MIN_BEANS = 10;
    const int MAX_GROUNDS = 10;

public:
    SensorsModule(int initial_water, int initial_beans);

    bool canBrew(std::string& error_msg);
    bool canBrew(std::string& error_msg, TCoffee& coffee);
    void processBrewing(TCoffee& coffee);

    void refillWater(int amount);
    void refillBeans(int amount);
    void emptyGrounds();

    int getWaterLevel() const { return water_level; }
    int getBeansAmount() const { return beans_amount; }
    int getGroundsCount() const { return grounds_count; }

    // Diagnostyka
    void statusCheck();
};