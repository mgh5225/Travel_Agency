//
// Created by Jarvis on 12/29/2018.
//

#include "account_func.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int remainder(int accounts,int password){
    FILE * f = fopen("BankAccounts/accounts.txt","r");
    char c_a[20];
    char c_p[20];
    char c_remain[20];
    for (int i=0;i<100000;i++){
        fscanf(f,"%s\t%s\t%s",c_a,c_p,c_remain);
        if(atoi(c_a)==accounts){
            if(atoi(c_p)==password){
                fclose(f);
                return atoi(c_remain);
            }
            fclose(f);
            return -1;
        }
    }
    fclose(f);
    return -2;
}