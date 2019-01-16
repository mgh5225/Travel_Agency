#include "main.h"
bool goto_intro_panel=false;
//----------------------------------------------------------------------------------------
char*str_to_char(string str,int length){
    char *ch=(char*)malloc(sizeof(char)*length);
    for(int i=0;i<length;i++){
        ch[i]='\0';
    }
    for(int i=0;i<str.length();i++){
        ch[i]=str[i];
    }
    return ch;
}
User create_new_user(string user_name,string user_pass,string fname,string lname ,string bank_account,string phone_number,string reference){
    User new_user={};
    for(int i=0;i<9;i++){
        new_user.user_name[i]=str_to_char(user_name,9)[i];
        new_user.user_pass[i]=str_to_char(user_pass,9)[i];
        new_user.reference[i]=str_to_char(reference,9)[i];
    }
    for(int i=0;i<21;i++){
        new_user.fname[i]=str_to_char(fname,21)[i];
        new_user.lname[i]=str_to_char(lname,21)[i];
    }
    for(int i=0;i<11;i++){
        new_user.bank_account[i]=str_to_char(bank_account,11)[i];
    }
    for(int i=0;i<12;i++){
        new_user.phone_number[i]=str_to_char(phone_number,12)[i];
    }
    return new_user;
}
//----------------------------------------------------------------------------------------
void create_user_intro_panel(){
    create_raw_menu(7, 76, 1, 1, true);
    add_text_to_raw_menu("Hello!", 4, 3);
    add_text_to_raw_menu("This Is User Panel. You Can Move Between Items By W(up) And S(down).", 6, 4);
    add_text_to_raw_menu("To Select Your Item You Must Move On It And Press Enter.", 6, 5);
    _sleep(10000);
    while(true) {
        goto_intro_panel = false;
        int items[4][2] = {{4, 3},{4, 4},{4, 5},{4, 9}};
        int h = 11;
        int w = 32;
        create_raw_menu(h, w,1,1,true);
        add_text_to_raw_menu("[1] Login Into Your Account.", 3, 3);
        add_text_to_raw_menu("[2] Create New Account.", 3, 4);
        add_text_to_raw_menu("[3] Join As A Guest.", 3, 5);
        for (int i = 2; i < w; i++) {
            add_text_to_raw_menu("-", i, 7);
        }
        add_text_to_raw_menu("[#] Back To Previous Panel.", 3, 9);
        gotoXY(4, 3);
        int i = move_between_items(items, 4);
        switch (i) {
            case 0:
                create_user_login_panel();
                break;
            case 1:
                create_user_register_panel();
                break;
            case 2:
                break;
            case 3:
                return;
        }
    }
}
//----------------------------------------------------------------------------------------
void create_user_login_panel(){
    User loggedin_user={};
    while (true) {
        if(goto_intro_panel) return;
        int items[2][2] = {{14, 4,},{5,  10}};
        int h = 12;
        int w = 56;
        create_raw_menu(h, w,1,1,true);
        add_text_to_raw_menu("If You Want To Add Your Username Press Enter.  ", 4, 2);
        add_text_to_raw_menu("Username : ", 3, 4);
        add_text_to_raw_menu("Password : ", 3, 6);
        for (int i = 2; i < w; i++) {
            add_text_to_raw_menu("-", i, 8);
        }
        add_text_to_raw_menu("[#] Back To Previous Panel.", 4, 10);
        gotoXY(14, 4);
        int i = move_between_items(items, 2);
        if (i == 0) {
            string name = input(8);
            gotoXY(14, 6);
            string  pass = input(8);
            loggedin_user = user_login(str_to_char(name,9),str_to_char(pass,9) );
        } else if (i == 1) {
            return;
        }
        if(loggedin_user.user_name[0]!='\0') break;
        create_raw_menu(3,56,1,13,false);
        add_text_to_raw_menu("Your Username Or Password Is Wrong Please Try Again.",3,14);
        gotoXY(1,15);
        _sleep(5000);
    }
    create_user_panel(loggedin_user);
}
void create_user_register_panel(){
    while(true) {
        int items[2][2]={{14,4},{5,21}};
        int h = 23;
        int w = 58;
        create_raw_menu(h, w, 1, 1, true);
        add_text_to_raw_menu("If You Want To Add Your Username Press Enter.  ",3, 2);
        add_text_to_raw_menu("Username : ", 3, 4);
        add_text_to_raw_menu("Password : ", 3, 6);
        add_text_to_raw_menu("First Name : ", 3, 8);
        add_text_to_raw_menu("Last Name : ", 3, 10);
        add_text_to_raw_menu("Bank Account : ", 3, 12);
        add_text_to_raw_menu("Phone Number : ", 3, 14);
        add_text_to_raw_menu("If You Have Reference", 3, 16);
        add_text_to_raw_menu("Please Enter His/Her Username : ", 3, 17);
        for (int i = 2; i < w; i++) {
            add_text_to_raw_menu("-", i, 19);
        }
        add_text_to_raw_menu("[#] Back To Previous Panel.", 4, 21);
        int n=move_between_items(items,2);
        if(n==1) break;
        gotoXY(14, 4);
        string user_name=input(8);
        if (find_user_in_file(str_to_char(user_name,9)) == -1) {
            gotoXY(14, 6);
            string user_pass=input(8);
            gotoXY(16, 8);
            string fname=input(20);
            gotoXY(15, 10);
            string lname=input(20);
            gotoXY(18, 12);
            string bank_account=input(10);
            gotoXY(18, 14);
            string phone_number=input(11);
            gotoXY(35, 17);
            string reference=input(8);
            User new_user=create_new_user(user_name,user_pass,fname,lname,bank_account,phone_number,reference);
            int n=add_user(new_user);
            if(n==1) break;
            else{
                create_raw_menu(3, 58, 1, 24, false);
                add_text_to_raw_menu("Something Went Wrong Please Try Again.", 3, 20);
                gotoXY(1, 25);
            }
        }
        create_raw_menu(3, 58, 1, 24, false);
        add_text_to_raw_menu("User " + user_name + " is Exists Please Enter Another Username.", 3, 25);
        gotoXY(1, 26);
        _sleep(5000);
    }
}
//----------------------------------------------------------------------------------------
void create_user_panel(User _user){
    while(true) {
        if(goto_intro_panel) return;
        create_raw_menu(3,46,1,1,true);
        add_text_to_raw_menu("Hello "+(string)_user.fname+" "+(string)_user.lname+".",3,2);
        gotoXY(1,4);
        _sleep(1000);
        int items[4][2] = {{4, 6},{4, 7},{4, 8},{4, 12}};
        int h = 11;
        int w = 46;
        create_raw_menu(h, w,1,4, false);
        add_text_to_raw_menu("[1] Show My Tickets.", 3, 6);
        add_text_to_raw_menu("[2] Buy New Ticket.", 3, 7);
        add_text_to_raw_menu("[3] Setting.", 3, 8);
        for (int i = 2; i < w; i++) {
            add_text_to_raw_menu("-", i, 10);
        }
        add_text_to_raw_menu("[4] Log out.", 3, 12);
        gotoXY(4,6);
        int i = move_between_items(items, 4);
        switch (i) {
            case 0:
                break;
            case 1:
                break;
            case 2:
                create_setting_panel(_user);
                break;
            case 3:
                return;
        }
    }
}
void create_setting_panel(User _user){
    while(true) {
        if(goto_intro_panel) return;
        int items[3][2] = {{4, 3},{4, 4},{4, 9}};
        int h = 11;
        int w = 32;
        create_raw_menu(h, w,1,1,true);
        add_text_to_raw_menu("[1] Edit My Account.", 3, 3);
        add_text_to_raw_menu("[2] Delete My Account.", 3, 4);
        for (int i = 2; i < w; i++) {
            add_text_to_raw_menu("-", i, 7);
        }
        add_text_to_raw_menu("[#] Back To Previous Panel.", 3, 9);
        gotoXY(4, 3);
        int i = move_between_items(items, 3);
        switch (i) {
            case 0:
                create_edit_panel(_user);
                break;
            case 1:
                create_delete_panel(_user);
                break;
            case 2:
                clrscr();
                return;
        }
    }
}
//----------------------------------------------------------------------------------------
void create_delete_panel(User _user){
    int items[2][2] = {{4, 4},{4, 5}};
    int h = 8;
    int w = 39;
    create_raw_menu(h, w,1,1, true);
    add_text_to_raw_menu("Do You Want To Delete Your Account?", 3, 2);
    add_text_to_raw_menu("[#] Yes.", 3, 4);
    add_text_to_raw_menu("[#] No.", 3, 5);
    gotoXY(4, 4);
    int i = move_between_items(items, 2);
    switch (i) {
        case 0:
            remove_user(_user);
            goto_intro_panel=true;
            break;
        case 1:
            break;
    }
}
void create_edit_panel(User _user){
    while(true) {
        int items[2][2]={{4,2},{5,20}};
        int h = 22;
        int w = 58;
        create_raw_menu(h, w, 1, 1, true);
        add_text_to_raw_menu("[#] Edit My Profile. ",3, 2);
        add_text_to_raw_menu("Username : "+(string)_user.user_name, 3, 4);
        add_text_to_raw_menu("Password : "+(string)_user.user_pass, 3, 6);
        add_text_to_raw_menu("First Name : "+(string)_user.fname, 3, 8);
        add_text_to_raw_menu("Last Name : "+(string)_user.lname, 3, 10);
        add_text_to_raw_menu("Bank Account : "+(string)_user.bank_account, 3, 12);
        add_text_to_raw_menu("Phone Number : "+(string)_user.phone_number, 3, 14);
        add_text_to_raw_menu("Reference Username : "+(string)_user.reference, 3, 16);
        for (int i = 2; i < w; i++) {
            add_text_to_raw_menu("-", i, 18);
        }
        add_text_to_raw_menu("[#] Back To Previous Panel.", 4, 20);
        int n=move_between_items(items,2);
        if(n==1) break;
        goto_intro_panel=true;
        int items2[6][2]={{14,6},{16,8},{15,10},{18,12},{18,14},{24,16}};
        int n2=move_between_items(items2,6);
        if(n2==0){
            for(int i=0;i<9;i++){
                printf(" ");
            }
            gotoXY(14,6);
            string user_pass=input(8);
            User new_user=create_new_user(_user.user_name,user_pass,_user.fname,_user.lname,_user.bank_account,_user.phone_number,_user.reference);
            edit_user_profile(new_user);
        }
        if(n2==1){
            for(int i=0;i<21;i++){
                printf(" ");
            }
            gotoXY(16,8);
            string fname=input(20);
            User new_user=create_new_user(_user.user_name,_user.user_pass,fname,_user.lname,_user.bank_account,_user.phone_number,_user.reference);
            edit_user_profile(new_user);
        }
        if(n2==2){
            for(int i=0;i<21;i++){
                printf(" ");
            }
            gotoXY(15,10);
            string lname=input(20);
            User new_user=create_new_user(_user.user_name,_user.user_pass,_user.fname,lname,_user.bank_account,_user.phone_number,_user.reference);
            edit_user_profile(new_user);
        }
        if(n2==3){
            for(int i=0;i<11;i++){
                printf(" ");
            }
            gotoXY(18,12);
            string bank_account=input(10);
            User new_user=create_new_user(_user.user_name,_user.user_pass,_user.fname,_user.lname,bank_account,_user.phone_number,_user.reference);
            edit_user_profile(new_user);
        }
        if(n2==4){
            for(int i=0;i<12;i++){
                printf(" ");
            }
            gotoXY(18,14);
            string phone_number=input(11);
            User new_user=create_new_user(_user.user_name,_user.user_pass,_user.fname,_user.lname,_user.bank_account,phone_number,_user.reference);
            edit_user_profile(new_user);
        }
        if(n2==5){
            for(int i=0;i<9;i++){
                printf(" ");
            }
            gotoXY(24,16);
            string reference=input(8);
            User new_user=create_new_user(_user.user_name,_user.user_pass,_user.fname,_user.lname,_user.bank_account,_user.phone_number,reference);
            edit_user_profile(new_user);
        }
    }
}