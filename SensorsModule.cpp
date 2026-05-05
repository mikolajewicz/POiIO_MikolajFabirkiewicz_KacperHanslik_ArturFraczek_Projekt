#include "SensorsModule.h"
#include <iostream>
#include <random>


float min_waterlevel = 200;		// [ml]
float min_beansamount = 10;		// [g]??
float max_grounds = 10;			// nie mam zielonego pojęcia

int waterlevel;
int beansamount;
int groundsamount;


void checksensors()
{
	checkwater();
	checkbeans();
	checkgrounds();

}
bool isReadytobrew()
{
	if (waterlevel > min_waterlevel && beansamount > min_beansamount && groundsamount < max_grounds)
		return true;
	else
		return false;
}
int checkwater()
{
	waterlevel = (rand() % 200) + 100;
	return waterlevel;
}
int checkbeans()
{
	beansamount= (rand() % 30) + 7;
	return beansamount;
}
int checkgrounds()
{
	groundsamount = (rand() % 15);
	return groundsamount;
}