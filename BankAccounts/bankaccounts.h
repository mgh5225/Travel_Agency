#ifndef TRAVEL_AGENCY_BANKACCOUNTS_H
#define TRAVEL_AGENCY_BANKACCOUNTS_H
#include <vector>
using namespace std;
typedef struct account{
    char id[11]={};
    char pass[5]={};
    char cash[11]={};
}Account;
void save_accounts_file(vector<Account>);
void xchange_accounts();
vector<Account> get_accounts();
//void subtract_cost(char[11],int);
#endif
