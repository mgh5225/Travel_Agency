#include <iostream>
#include "Admin/admin.h"
#include <conio.h>
#include <vector>
#include <ctime>
#include "BankAccounts/account_func.h"
#include "someThingNecessary.h"
using namespace std;

#include <stdlib.h>

void toBinaryAcc(){
    FILE * f = fopen("BankAccounts/accounts.txt","r");
    if(f!=NULL){
        vector<account> acc;
        account temp;
        char a_temp[20];
        char p_temp[20];
        char r_temp[20];
        while(!feof(f)){
            fscanf(f,"%s\t%s\t%s",a_temp,p_temp,r_temp);
            temp.ID=atoi(a_temp);
            temp.password=atoi(p_temp);
            temp.remaind=atoi(r_temp);
            acc.push_back(temp);
        }
        fclose(f);
        remove("BankAccounts/accounts.txt");
        FILE * newFile = fopen("BankAccounts/accounts.dat","wb");
        for(int i=0;i<acc.size();i++){
            fwrite(&(acc[i]), sizeof(account), 1, newFile);
        }
        fclose(newFile);
    }
}

int main() {
    toBinaryAcc();
    clrscr();
    cout<<"##Welcome to Travel Agency##"<<endl;
    cout<<"Which one are you?! choose the number and press enter:"<<endl;
    cout<<"1    Admin"<<endl;
    cout<<"2    User"<<endl;
    cout<<"3    Driver"<<endl;
    int x;
    cin>>x;
    if(x==1){
        Admin();
    }
    else if(x==2){

    }
    else{
    }


    return 0;
}