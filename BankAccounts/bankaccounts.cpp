#include "bankaccounts.h"
#include <stdio.h>
void save_accounts_file(vector<Account> accounts){
    FILE* fp=fopen("BankAccounts/b_accounts.txt","wb");
    for(long int i=0;i<accounts.size();i++)
        fwrite(&(accounts[i]),sizeof(Account),1,fp);
    fclose(fp);
}
vector<Account> get_accounts(){
    vector<Account> accounts;
    FILE* fp=fopen("BankAccounts/b_accounts.txt","rb");
    if(fp!=NULL){
        while (1){
            Account temp={};
            fread(&temp,sizeof(Account),1,fp);
            if(feof(fp))break;
            accounts.push_back(temp);
        }
        fclose(fp);
    }
    return accounts;
}
void xchange_accounts(){
    vector<Account> accounts;
    FILE* fp=fopen("BankAccounts/accounts.txt","r");
    if(fp==NULL){
        return;
    }
    while (1){
        Account temp={};
        fscanf(fp,"%s\t%s\t%d",temp.id,temp.pass,&temp.cash);
        if(feof(fp))break;
        accounts.push_back(temp);
    }
    fclose(fp);
    save_accounts_file(accounts);
}
long int find_account(vector<Account> accounts,Account _account){
    for(long int i=0;i<accounts.size();i++){
        int j;
        for(j=0;j<11 && accounts[i].id[j]==_account.id[j];j++);
        if(j==11){
            return i;
        }
    }
    return -1;
}
Account connect_to_account(Account _account){
    vector<Account> accounts=get_accounts();
    long int point=find_account(accounts,_account);
    if(point!=-1){
        int j;
        for(j=0;j<5 && accounts[point].pass[j]==_account.pass[j];j++);
        if(j==5) return accounts[point];
    }
    return Account{};
}

