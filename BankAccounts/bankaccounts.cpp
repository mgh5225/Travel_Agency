#include "bankaccounts.h"
#include <stdio.h>
void fill_accounts(){
    vector<Account> accounts;
    FILE* ftxt=fopen("BankAccounts/accounts.txt","r");
    FILE* fp=fopen("BankAccounts/b_accounts.txt","wb");
    if(ftxt==NULL){
        return;
    }
    while (!feof(ftxt)){
        Account temp={};
        fscanf(ftxt,"%s\t%s\t%s",temp.id,temp.pass,temp.cash);
        accounts.push_back(temp);
    }
    for(int i=0;i<accounts.size();i++)
        fwrite(&(accounts[i]), sizeof(Account),1,fp);
    fclose(ftxt);
    fclose(fp);
}
vector<Account> get_accounts(){
    vector<Account> accounts;
    FILE* fp=fopen("BankAccounts/b_accounts.txt","rb");
    if(fp!=NULL){
        while (!feof(fp)){
            Account temp={};
            fread(&temp,sizeof(Account),1,fp);
            accounts.push_back(temp);
        }
    }
    return accounts;
}

