#ifndef TRAVEL_AGENCY_DISCOUNT_H
#define TRAVEL_AGENCY_DISCOUNT_H
#include <vector>
using namespace std;
typedef struct discount{
    int id=0;
    int dis=0;
}Discount;
void save_discounts_file(vector<Discount>);
vector<Discount> get_discounts();
void add_discount(Discount);
void remove_discount(Discount)
#endif
