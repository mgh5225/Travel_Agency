//
// Created by Jarvis on 12/30/2018.
//
//HEADER:
#include "setting.h"
//Necessary Includes:
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <windows.h>
//necessary:
#include "../../main.h"
#include "../../BankAccounts/account_func.h"
#include "../../someThingNecessary.h"

using namespace std;

void setting(){
    clrscr();
    cout<<"************* Setting Panel ********************"<<endl;
    int id,pass;
    cin>>id>>pass;
    cout<<remainder(id,pass);
    int x;
    cin>>x;
}