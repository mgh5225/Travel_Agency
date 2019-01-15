#include "main.h"
#include "users.h"
#include "tickets.h"
//----------------------------------------------------------------------------------------
void create_user_intro_panel(){
    create_raw_menu(7,76,1,1,true);
    add_text_to_raw_menu("Hello!", 4, 3);
    add_text_to_raw_menu("This Is User Panel. You Can Move Between Items By W(up) And S(down).", 6, 4);
    add_text_to_raw_menu("To Select Your Item You Must Move On It And Press Enter.", 6, 5);
    _sleep(10000);
    while(true) {
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
        int items[2][2] = {{15, 4,},{5,  10}};
        int h = 12;
        int w = 56;
        create_raw_menu(h, w,1,1,true);
        add_text_to_raw_menu("If You Want To Add Your Username Press Enter.  ", 4, 2);
        add_text_to_raw_menu("Username : ", 4, 4);
        add_text_to_raw_menu("Password : ", 4, 6);
        for (int i = 2; i < w; i++) {
            add_text_to_raw_menu("-", i, 8);
        }
        add_text_to_raw_menu("[#] Back To Previous Panel.", 4, 10);
        gotoXY(15, 4);
        int i = 0;
        i = move_between_items(items, 2);
        if (i == 0) {
            char name[9] = {};
            scanf("%s", name);
            gotoXY(15, 6);
            char pass[9] = {};
            scanf("%s", pass);
            loggedin_user = user_login(name, pass);
        } else if (i == 1) {
            return;
        }
        if(loggedin_user.user_name[0]!='\0') break;
        create_raw_menu(3,56,1,13,false);
        add_text_to_raw_menu("Your Username Or Password Is Wrong Please Try Again.",3,14);
        gotoXY(1,15);
        _sleep(5000);
    }
    create_raw_menu(3,46,1,1,true);
    add_text_to_raw_menu("Hello "+(string)loggedin_user.fname+" "+(string)loggedin_user.lname+".",3,2);
    gotoXY(1,4);
    _sleep(1000);
    create_user_panel();
}
void create_user_panel(){
    while(true) {
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
                break;
            case 3:
                return;
        }
    }
}
//----------------------------------------------------------------------------------------
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
        User new_user={};
        gotoXY(14, 4);
        scanf("%s", new_user.user_name);
        if (find_user_in_file(new_user.user_name) == -1) {
            gotoXY(14, 6);
            scanf("%s", new_user.user_pass);
            gotoXY(16, 8);
            scanf("%s", new_user.lname);
            gotoXY(15, 10);
            scanf("%s", new_user.fname);
            gotoXY(18, 12);
            scanf("%s", new_user.bank_account);
            gotoXY(18, 14);
            scanf("%s", new_user.phone_number);
            gotoXY(35, 17);
            scanf("%s", new_user.reference);
            int n=add_user(new_user);
            if(n==1) break;
            else{
                create_raw_menu(3, 58, 1, 24, false);
                add_text_to_raw_menu("Something Went Wrong Please Try Again.", 3, 20);
                gotoXY(1, 25);
            }
        }
        create_raw_menu(3, 58, 1, 24, false);
        add_text_to_raw_menu("User " + (string) new_user.user_name + " is Exists Please Enter Another Username.", 3, 25);
        gotoXY(1, 26);
        _sleep(5000);
    }
}