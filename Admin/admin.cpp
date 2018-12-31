//
// Created by mgh on 12/24/18.
//
#include "admin.h"

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <windows.h>

#include "../main.h"
#include "adminlogged.h"
#include "../BankAccounts/account_func.h"
#include "../someThingNecessary.h"


using namespace std;

void SignUp(){
    cout<<"Admin is not registered. You should register one time."<<endl;
    FILE *f=fopen("Admin/admin.txt","w");
    string username;
    string password;
    int accID;
    int accpw;
    //-----------------------------assigning username--------------------//
    cout<<"Username :   ";
    cin>>username;
    //-----------------------------assigning password---------------------//
    cout<<"Password :   ";
    cin>>password;
    //----------------------------assigning Account ID--------------------//
    while(true){
        cout<<"Account ID :    ";
        cin>>accID;
        if(remainder(accID,0) == -1){
            while(true){
                cout<<"Account password :   ";
                cin>>accpw;
                if(remainder(accID,accpw)>=0){
                    break;
                }
                else{
                    cout<<"\aSorry, your account password is wrong. try again:\n";
                }
            }
            break;
        }
        else{
            cout<<"\aSorry, No such account ID exist. try again:\n";
        }
    }
    fprintf(f,"%s\t%s\t%d",username.c_str(),password.c_str(),accID);
    cout<<"\nYou have registered successfully.";
    cout<<"\n Backing to the main page ...";
    fclose(f);
    Sleep(3000);
    clrscr();
    main();

}

int Admin(){
    clrscr();
    FILE * f=fopen("Admin/admin.txt","r");
    if(f==NULL){
        fclose(f);
        SignUp();
    }
    else{
        char u[1000],s[1000];
        fscanf(f,"%s\t%s",u,s);
        string username(u),password(s);
        while(true){
            cout<<".:   Login   :."<<endl;
            string u_username,u_password;
            cout<<"Username:    ";
            cin>>u_username;
            cout<<"Password:    ";
            cin>>u_password;
            if(u_username==username && u_password==password){
                cout<<"logging in ...";
                Sleep(1000);
                adminLogged();
                break;
            }
            else{
                cout<<"Username or password is wrong. try again:"<<endl;
                Sleep(1000);
                clrscr();
            }
        }
    }

    }



