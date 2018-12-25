#include "bankaccounts.h"
#include <stdio.h>
void save_accounts_file(vector<Account> accounts){
    FILE* fp=fopen("BankAccounts/b_accounts.txt","wb");
    for(long int i=0;i<accounts.size();i++)
        fwrite(&(accounts[i]),sizeof(Account),1,fp);
    fclose(fp);
}
void xchange_accounts(){
    vector<Account> accounts;
    FILE* ftxt=fopen("BankAccounts/accounts.txt","r");
    if(ftxt==NULL){
        return;
    }
    while (!feof(ftxt)){
        Account temp={};
        fscanf(ftxt,"%s\t%s\t%s",temp.id,temp.pass,temp.cash);
        if(temp.id[0]=='\0')break;
        accounts.push_back(temp);
    }
    fclose(ftxt);
    save_accounts_file(accounts);
}
vector<Account> get_accounts(){
    vector<Account> accounts;
    FILE* fp=fopen("BankAccounts/b_accounts.txt","rb");
    if(fp!=NULL){
        while (!feof(fp)){
            Account temp={};
            fread(&temp,sizeof(Account),1,fp);
            if(temp.id[0]=='\0')break;
            accounts.push_back(temp);
        }
        fclose(fp);
    }
    return accounts;
}

