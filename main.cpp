#include <iostream>
#include "Cities/cities.h"
#include "BankAccounts/bankaccounts.h"
#include "Users/users.h"
int main() {
    xchange_accounts();
    //xchange_cities();
    Account ac={"200000","1318"};
    Account ac2;
    //ac2=connect_to_account(ac);
    printf("%d",ac2.cash);

}