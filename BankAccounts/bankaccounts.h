#ifndef TRAVEL_AGENCY_BANKACCOUNTS_H
#define TRAVEL_AGENCY_BANKACCOUNTS_H
#include <vector>
using namespace std;
typedef struct account{
    char id[10]={};
    char pass[4]={};
    char cash[10]={};
}Account;
void fill_accounts();
vector<Account> get_accounts();
#endif
