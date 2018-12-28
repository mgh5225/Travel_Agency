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
long int find_account(vector<Account> accounts,User _user){
    for(long int i=0;i<accounts.size();i++){
        int j;
        for(j=0;j<11 && accounts[i].id[j]==_user.bank_account[j];j++);
        if(j==11){
            return i;
        }
    }
    return -1;
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
void subtract_cost(User _user,Ticket* _ticket/*,Journey _journey*/){
    vector<Account> accounts=get_accounts();
    long int point=find_account(accounts,_user);
    if(accounts[point].cash>=_ticket->cost){
        accounts[point].cash-=_ticket->cost;
        _ticket->mode=TICKET_BOUGHT;
        //_ticket->ticket_journey=_journey;
        save_accounts_file(accounts);
    }
}

