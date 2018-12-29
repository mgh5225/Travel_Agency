//
// Created by Jarvis on 12/28/2018.
//
//header:
#include "adminlogged.h"
//necessary libraries:
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <windows.h>
//necessary project files:
#include "../main.h"
#include "../BankAccounts/account_func.h"


using namespace std;


void adminLogged(){
    clrscr();
    int ac,pw;
    cin>>ac>>pw;
    cout<<remainder(ac,pw);

    int x;
    cin>>x;



}