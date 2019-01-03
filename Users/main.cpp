#include "main.h"
#include "users.h"
#include "tickets.h"
#include <iostream>
using namespace std;
void login_page(){
    char user_name[9]={};
    char user_pass[9]={};
    cout<<"Please Enter Your User Name : ";
    cin>>user_name;
    cout<<"Please Enter Your Password (Max 8 characters) : ";
    cin>>user_pass;
    User _user=user_login(user_name,user_pass);
    while(_user.user_name[0]=='\0'){
        cout<<"Something Went Wrong Please Try Again"<<endl;
        cout<<"Please Enter Your User Name : ";
        cin>>user_name;
        cout<<"Please Enter Your Password (Max 8 characters) : ";
        cin>>user_pass;
        _user=user_login(user_name,user_pass);
    }
    cout<<"Hello "<<_user.fname<<" "<<_user.lname<<endl;
}
void register_page(){
    User new_user={};
    cout<<"Please Enter Your User Name (Max 8 characters): ";
    cin>>new_user.user_name;
    while (find_user_in_file(new_user.user_name)!=-1){
        cout<<"User "<<new_user.user_name<<" Exist Please Enter Another User Name : ";
        cin>>new_user.user_name;
    }
    cout<<"Hello "<<new_user.user_name<<" !"<<endl;
    cout<<"Please Enter Your Password (Max 8 characters) : ";
    cin>>new_user.user_pass;
    cout<<"Please Enter Your First Name : ";
    cin>>new_user.fname;
    cout<<"Please Enter Your Last Name : ";
    cin>>new_user.lname;
    cout<<"Please Enter Your Bank Account Number : ";
    cin>>new_user.bank_account;
    cout<<"Please Enter Your Phone Number : ";
    cin>>new_user.phone_number;
    cout<<"If You Have Reference Please Enter His/Her User Name For Discount Or Enter -1 : ";
    cin>>new_user.reference;
    add_user(new_user);
    cout<<"Now Go To Login Page"<<endl;
    login_page();

}
void user_intro(){
    cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*##User Panel##*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
    cout<<"[1] Login Into Your Account."<<endl;
    cout<<"[2] Not A User Register Now!"<<endl;
    cout<<"[3] Join As A Guest."<<endl;
    cout<<"[4] Back To Previous Panel."<<endl;
    int n;
    cout<<"[Enter Number(1-4)] ";
    cin>>n;
    switch (n){
        case 1:login_page();break;
        case 2:register_page();break;
        case 3:break;
        case 4:;
        default:return;
    }
    
}
