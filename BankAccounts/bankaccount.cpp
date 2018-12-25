#include <stdio.h>
#include "bankaccount.h"
#include <vector>
using namespace std;
typedef struct bank_accounts{
    char name[6]={};
    char pass[4]={};
    char cash[10]={};
}Bank_Accounts;
vector<Bank_Accounts> accounts;
void fill(){
    FILE* ftxt=fopen("BankAccounts/accounts.txt","r");
    FILE* fp=fopen("BankAccounts/b_accounts.txt","wb");
    if(ftxt==NULL){
        return;
    }
    while (!feof(ftxt)){
        Bank_Accounts temp={};
        fscanf(ftxt,"%s\t%s\t%s",temp.name,temp.pass,temp.cash);
        accounts.push_back(temp);
    }
    for(int i=0;i<accounts.size();i++)
        fwrite(&(accounts[i]), sizeof(accounts[i]),1,fp);
}