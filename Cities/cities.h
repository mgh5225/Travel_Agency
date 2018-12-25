#ifndef TRAVEL_AGENCY_CITIES_H
#define TRAVEL_AGENCY_CITIES_H
#include <vector>
using namespace std;
typedef struct city{
    int id=0;
    int X=0;
    int Y=0;
}City;
void fill_cities();
vector<City> get_cities();
#endif