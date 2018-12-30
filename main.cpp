#include <iostream>
#include "Admin/admin.h"
#include <conio.h>
using namespace std;

#include <stdlib.h>

void clrscr(){
    system("@cls||clear");
}

int main() {
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