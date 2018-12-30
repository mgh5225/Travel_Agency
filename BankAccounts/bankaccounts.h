#ifndef TRAVEL_AGENCY_BANKACCOUNTS_H
#define TRAVEL_AGENCY_BANKACCOUNTS_H
#include <vector>
#include "../Users/users.h"
using namespace std;
typedef struct account{
    char id[11]={};
    char pass[5]={};
    int cash=0;
}Account;
void save_accounts_file(vector<Account>);
vector<Account> get_accounts();
long int find_account(vector<Account>,Account);
void xchange_accounts();
Account connect_to_account(Account);
#endif

