//
// Created by Jarvis on 12/30/2018.
//
//HEADER
#include "transaction.h"
//Necessary Includes:
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <windows.h>
#include <vector>
//necessary:
#include "../../main.h"
#include "../../someThingNecessary.h"
#include "../../BankAccounts/account_func.h"

using namespace std;

void transaction(){
    clrscr();
    vector<trans> vtr1;
    trans temp;
    temp.trackingNumber=1;
    temp.cost=500;
    temp.dest=200001;
    temp.acc.ID=200000;
    temp.acc.remaind=8000;
    temp.acc.password=1318;
    temp.d.year=132;
    temp.d.month=1;
    temp.d.day=3;
    temp.d.hour=3;
    temp.d.min=5;
    temp.d.sec=6;
    memcpy(temp.exp,"fuck this",50);
    vtr1.push_back(temp);
    updateTrans(vtr1);
    cout<<"************* Account transaction Panel ********************"<<endl;
    vector<trans> vtr = getAllTrans(200000);
    cout<<vtr.size()<<endl;
    for(int i=0;i<vtr.size();i++){
        cout<<vtr[i].trackingNumber<<"|";
        cout<<vtr[i].dest<<"|";
        cout<<vtr[i].cost<<"|";
        cout<<vtr[i].d.year<<"|";
        cout<<vtr[i].d.month<<"|";
        cout<<vtr[i].d.day<<"|";
        cout<<vtr[i].d.hour<<"|";
        cout<<vtr[i].d.min<<"|";
        cout<<vtr[i].d.sec<<"|";
        cout<<vtr[i].exp;
        cout<<endl;
    }

    int x;
    cin>>x;
}