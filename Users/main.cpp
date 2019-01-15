#include "main.h"
#include "users.h"
#include "tickets.h"
//----------------------------------------------------------------------------------------
/*void create_rand_id(char id[9]){
    long int n=1;
    int rnd;
    while(n==1){
        srand(time(0));
        rnd=rand()%90000000+10000000;
        string rnd_s=to_string(rnd);
        for(int i=0;i<9;i++){
            id[i]=rnd_s[i];
        }
        n=find_ticket_in_file(id);
    }

}
User edit_user_profile_panel(User _user,bool isUser){
    User new_user=_user;
    bool is_edited=false;
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
        if(isUser) {
            cout << "[4] Change My Password." << endl;
        }
        cout << "[-1] Exit." << endl;
        cout<<"-----------------------------------------------------------------"<<endl;
        if(isUser) {
            cout<<"Please Enter Number Between 1-4 Or -1 For Exit From This Panel : ";
        }
        else {
            cout<<"Please Enter Number Between 1-3 Or -1 For Exit From This Panel : ";
        }
        int n;
        cin >> n;
        clrscr();
        if(n==1) {
            is_edited=true;
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
            is_edited=true;
            char temp_b[11]={};
            cout << "Enter New Bank Account Number : ";
            cin >> temp_b;
            for(int i=0;i<11;i++) {
                new_user.bank_account[i] = temp_b[i];
            }
        }else if(n==3) {
            is_edited=true;
            char temp_p[12]={};
            cout << "Enter New Phone Number : ";
            cin >> temp_p;
            for(int i=0;i<12;i++) {
                new_user.phone_number[i] = temp_p[i];
            }
        }else if(n==4 && isUser){
            is_edited=true;
            char temp_p[9]={};
            cout<<"Enter New Password : ";
            cin>>temp_p;
            for(int i=0;i<9;i++) {
                new_user.user_pass[i] = temp_p[i];
            }
        }else if(n==-1) {
            if (is_edited) {
                cout << "-----------------------------------------------------------------" << endl;
                cout << "Do You Want To Save Your Changes [Y/N] : ";
                char b;
                cin >> b;
                if ((b == 'y' || b == 'Y')) {
                    if (isUser)
                        edit_user_profile(new_user);
                    return new_user;
                } else return _user;
            } else return _user;
        }
    }
}
void show_ticket_panel(User _user){
    clrscr();
    vector<Ticket> tickets=get_user_tickets(_user);
    cout<<"You Reserved "<<tickets.size()<<" Ticket(s)."<<endl<<endl;
    for(long int i=0;i<tickets.size();i++){
        cout<<"["<<i+1<<"]"<<endl;
        cout<<"################################################################"<<endl;
        cout<<"[id] "<<tickets[i].id<<endl;
        cout<<"----------------------------------------------------------------"<<endl;
        cout<<"From : \t";
        cout<<"To : "<<endl;
        cout<<"Start Date : "<<endl;
        cout<<"Cost : "<<tickets[i].cost<<endl;
        cout<<"################################################################"<<endl<<endl;
    }
    cout<<"\nPlease Press Enter To Exit This Panel. ";
    bool b=false;
    while(true){
        getc(stdin);
        if(b)break;
        b=true;
    }
}
void buy_ticket_panel(User _user){
    clrscr();
    Ticket new_ticket={};
    cout<<"Choose One Of The Vehicle: "<<endl;
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"[1] Bus."<<endl;
    cout<<"[2] Train."<<endl;
    cout<<"[3] Airplane."<<endl;
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"Please Enter Your Vehicle :";
    int n;
    cin>>n;
    cout<<"----------------------------------------------------------------"<<endl;
    //swich case to set driver mode to 1-2-3
    cout<<"please Enter Origin City For Your Journey : ";
    int origin_city;
    cin>>origin_city;
    cout<<"please Enter Destination City For Your Journey : ";
    int destination_city;
    cin>>destination_city;
    //show available journey and cost to add it.
    create_rand_id(new_ticket.id);
    add_ticket(new_ticket);
}
void user_panel(User _user,bool isUser){
    user_state= true;
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
                buy_ticket_panel(_user);
                break;
            case 2:
                show_ticket_panel(_user);
                break;
            case 3:
                _user=edit_user_profile_panel(_user,isUser);
                break;
            case 4:;
            default:
                return;
        }
    }
}
//----------------------------------------------------------------------------------------
void user_login_panel(){
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
            return;
        }
        cout<<"Please Enter Your User Name : ";
        cin>>user_name;
        cout<<"Please Enter Your Password (Max 8 characters) : ";
        cin>>user_pass;
        _user=user_login(user_name,user_pass);
    }
    clrscr();
    user_panel(_user,true);
}
//----------------------------------------------------------------------------------------
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
void guest_register_panel(){
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
    user_panel(guest_user,false);
}
//----------------------------------------------------------------------------------------
void user_intro_panel(){
    User _user={};
    while (1) {
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
                user_login_panel();
                break;
            case 2:
                user_register_panel();
                break;
            case 3:
                guest_register_panel();
                break;
            case 4:;
            default:
                return;
        }


    }

}
//----------------------------------------------------------------------------------------*/
void create_user_intro_panel(){
    while(1) {
        int items[4][2] = {{5, 3},{5, 4},{5, 5},{5, 9}};
        int h = 11;
        int w = 33;
        create_raw_menu(h, w);
        add_text_to_raw_menu("[1] Login Into Your Account.", 4, 3);
        add_text_to_raw_menu("[2] Create New Account.", 4, 4);
        add_text_to_raw_menu("[3] Join As A Guest.", 4, 5);
        for (int i = 2; i < w; i++) {
            add_text_to_raw_menu("-", i, 7);
        }
        add_text_to_raw_menu("[4] Back To Previous Panel.", 4, 9);
        gotoXY(5, 3);
        int i = move_between_items(items, 4);
        switch (i) {
            case 0:
                create_user_login_panel();
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                return;
        }
        gotoXY(1, h + 1);
    }
}
void create_user_login_panel(){
    int items[3][2]={{15,3,},{5,9}};
    int h=11;
    int w=52;
    create_raw_menu(h,w);
    add_text_to_raw_menu("If You Want To Add Your Username Press Enter. : ",4,2);
    add_text_to_raw_menu("Username : ",4,3);
    add_text_to_raw_menu("Password : ",4,5);
    for(int i=2;i<w;i++){
        add_text_to_raw_menu("-",i,7);
    }
    add_text_to_raw_menu("[#] Back To Previous Panel.",4,9);
    gotoXY(15,3);
    int i=0;
    i=move_between_items(items,2);
    if(i==0) {
        char name[9] = {};
        scanf("%s", name);
        gotoXY(15, 5);
        char pass[9] = {};
        scanf("%s", pass);

    }
    else if(i==1){
        return;
    }
}