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
#include "../admin.h"
#include "../adminlogged.h"

using namespace std;

void transaction(){
    clrscr();
    admin ad=adminInfo();
    int password;
    cout<<"************* Account transaction Panel ********************"<<endl<<endl;
    cout<<"Your account ID is :   "<<ad.accID<<endl;
    cout<<"Please Enter the account password to access detail :   ";
    cin>>password;
    if(remainder(ad.accID,password)==-1){
        while (true){
            cout<<"Wrong password. Try again :  ";
            cin>>password;
            if(remainder(ad.accID,password)>=0) break;
        }
    }
    clrscr();
    cout<<"************* Account transaction Panel ********************"<<endl<<endl;
    cout<<"Your account ID is :   "<<ad.accID<<endl;
    cout<<"The Transaction are shown as below format:"<<endl;
    cout<<"Tracking Number | dest accID | Cost | Year | Month | Day | Hour | Minute | Second | Explanation"<<endl;
    Sleep(2000);
    cout<<endl;
    vector<trans> vtr = getAllTrans(ad.accID);
    if(vtr.size()==0){
        cout<<"No Transaction done yet."<<endl;
    }
    else {
        for (int i = 0; i < vtr.size(); i++) {
            cout << vtr[i].trackingNumber << " | ";
            cout << vtr[i].dest << " | ";
            cout << vtr[i].cost << " | ";
            cout << vtr[i].d.year << " | ";
            cout << vtr[i].d.month << " | ";
            cout << vtr[i].d.day << " | ";
            cout << vtr[i].d.hour << " | ";
            cout << vtr[i].d.min << " | ";
            cout << vtr[i].d.sec << " | ";
            cout << vtr[i].exp;
            cout << endl;
        }
    }
    cout<<endl;
    cout<<"-----------------------------------"<<endl;
    cout<<endl;
    cout<<"The Account charge is :  "<<remainder(ad.accID,password)<<endl;
    cout<<endl;
    cout<<"************************************"<<endl;
    cout<<endl;
    cout<<"enter 0 to return to admin page"<<endl;
    while(true){
        int x;
        cin>>x;
        if(x==0){
            cout<<"Return to admin page ...";
            Sleep(1000);
            adminLogged();
            break;
        }
    }
}