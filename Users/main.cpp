#include "main.h"
#include "users.h"
#include "tickets.h"
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
using namespace std;
bool intro_state= true;
bool user_state= true;
void clrscr(){
    sleep(1);
    cout << "\033[2J\033[1;1H";
}
void edit_user_profile_panel(User _user){
    User new_user=_user;
    while (1) {
        clrscr();
        cout << "Your Information Is : " << endl;
        cout<<"----------------------------------------------------------------"<<endl;
        cout << "Name : " << new_user.fname << " " <<new_user.lname << endl;
        cout << "Bank Account : " << new_user.bank_account << endl;
        cout << "Phone Number : " << new_user.phone_number << endl;
        cout<<"----------------------------------------------------------------"<<endl;
        cout<< "Which One Do You Want To Edit it? "<<endl;
        cout<<"----------------------------------------------------------------"<<endl;
        cout << "[1] Change My Name." << endl;
        cout << "[2] Change My Bank Account." << endl;
        cout << "[3] Change My Phone Number." << endl;
        cout << "[4] Change My Password." << endl;
        cout << "[-1] Cancel." << endl;
        cout<<"-----------------------------------------------------------------"<<endl;
        cout<<"Please Enter Number Between 1-4 Or -1 For Cancel Editing Your Information : ";
        int n;
        cin >> n;
        clrscr();
        if(n==1) {
            char temp_f[21] = {};
            char temp_l[21] = {};
            cout << "Enter New First Name : ";
            cin >> temp_f;
            cout << "Enter New Last Name : ";
            cin >> temp_l;
            for(int i=0;i<21;i++) {
                new_user.fname[i] = temp_f[i];
                new_user.lname[i] = temp_l[i];
            }
        }else if(n== 2) {
            char temp_b[11]={};
            cout << "Enter New Bank Account Number : ";
            cin >> temp_b;
            for(int i=0;i<11;i++) {
                new_user.bank_account[i] = temp_b[i];
            }
        }else if(n==3) {
            char temp_p[12]={};
            cout << "Enter New Phone Number : ";
            cin >> temp_p;
            for(int i=0;i<12;i++) {
                new_user.bank_account[i] = temp_p[i];
            }
        }else if(n==4){
            char temp_p[9]={};
            cout<<"Enter New Password : ";
            cin>>temp_p;
            for(int i=0;i<9;i++) {
                new_user.bank_account[i] = temp_p[i];
            }
        }else{
            return;
        }
        cout<<"-----------------------------------------------------------------"<<endl;
        cout<<"Do You Want To Save Your Changes? [Y/N] : ";
        char b;
        cin>>b;
        if(b=='y' || b=='Y'){
            edit_user_profile(new_user);
            user_state= false;
        }
    }

}
void user_panel(User _user){
    user_state= true;
    intro_state= true;
    while (user_state) {
        clrscr();
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*##User Panel##*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
        cout<<"Hello "<<_user.fname<<" "<<_user.lname<<"."<<endl;
        cout<<endl;
        cout << "[1] Buy New Ticket." << endl;
        cout << "[2] Show My Tickets." << endl;
        cout << "[3] Edit Your Profile." << endl;
        cout << "[4] Logout." << endl;
        int n;
        cout << "[Enter Number(1-4)] ";
        cin >> n;
        switch (n) {
            case 1:
                break;
            case 2:

                break;
            case 3:
                edit_user_profile_panel(_user);
                break;
            case 4:;
            default:
                return;
        }
    }
}
User user_login_panel(){
    clrscr();
    char user_name[9]={};
    char user_pass[9]={};
    cout<<"Please Enter Your User Name : ";
    cin>>user_name;
    cout<<"Please Enter Your Password (Max 8 characters) : ";
    cin>>user_pass;
    User _user=user_login(user_name,user_pass);
    while(_user.user_name[0]=='\0'){
        clrscr();
        cout<<"Something Went Wrong Please Try Again."<<endl;
        cout<<"If Not Register Now Please Create A New User By Enter 2 Else -1 : ";
        int n;
        cin>>n;
        if(n==2){
            intro_state=true;
            return User{};
        }
        cout<<"Please Enter Your User Name : ";
        cin>>user_name;
        cout<<"Please Enter Your Password (Max 8 characters) : ";
        cin>>user_pass;
        _user=user_login(user_name,user_pass);
    }
    clrscr();
    intro_state= false;
    return _user;
}
void user_register_panel(){
    clrscr();
    User new_user={};
    cout<<"Please Enter Your User Name (Max 8 characters): ";
    cin>>new_user.user_name;
    while (find_user_in_file(new_user.user_name)!=-1){
        clrscr();
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
    clrscr();
    cout<<"Now Go To Login Page."<<endl;
    clrscr();
    user_login_panel();

}
User guest_panel(){
    clrscr();
    User guest_user={};
    cout<<"Please Enter Your User Name (Max 8 characters): ";
    cin>>guest_user.user_name;
    while (find_user_in_file(guest_user.user_name)!=-1){
        clrscr();
        cout<<"User "<<guest_user.user_name<<" Exist Please Enter Another User Name : ";
        cin>>guest_user.user_name;
    }
    clrscr();
    cout<<"Hello "<<guest_user.user_name<<" !"<<endl;
    cout<<"Please Enter Your First Name : ";
    cin>>guest_user.fname;
    cout<<"Please Enter Your Last Name : ";
    cin>>guest_user.lname;
    cout<<"Please Enter Your Bank Account Number : ";
    cin>>guest_user.bank_account;
    cout<<"Please Enter Your Phone Number : ";
    cin>>guest_user.phone_number;
    clrscr();
    cout<<"User Create Success Your Information is : "<<endl;
    cout<<"User Name : "<<guest_user.user_name<<endl;
    cout<<"Bank Account : "<<guest_user.bank_account<<endl;
    cout<<"Full  Name : "<<guest_user.fname<<" "<<guest_user.lname<<endl;
    cout<<"Phone Number : "<<guest_user.phone_number<<endl;
    intro_state=false;
    return guest_user;
}
void user_intro_panel(){
    intro_state=true;
    User _user={};
    while (intro_state) {
        clrscr();
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*##Welcome To Travel Agency##*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
        cout << "[1] Login Into Your Account." << endl;
        cout << "[2] Not A User Register Now!" << endl;
        cout << "[3] Join As A Guest." << endl;
        cout << "[4] Back To Previous Panel." << endl;
        int n;
        cout << "[Enter Number(1-4)] ";
        cin >> n;
        switch (n) {
            case 1:
                _user= user_login_panel();
                break;
            case 2:
                user_register_panel();
                break;
            case 3:
                _user=guest_panel();
                break;
            case 4:;
            default:
                return;
        }
        if(_user.user_name[0]!='\0')
        user_panel(_user);

    }

}
//----------------------------------------------------------------------------------------