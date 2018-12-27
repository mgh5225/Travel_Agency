#ifndef TRAVEL_AGENCY_USERS_H
#define TRAVEL_AGENCY_USERS_H
#include <vector>
#include "../Cities/cities.h"
#include "../Date/date.h"
using namespace std;
typedef struct user{
    char user_name[101]={};
    char user_pass[33]={};
    char fname[21]={};
    char lname[21]={};
    char bank_account[11];
    char phone_number[12]={};
    char reference[21];
}User;
typedef struct ticket{
    int code=0;
    //Driver journey_driver={};
    User customer={};
    City origin={};
    City purpose={};
    Date journey_date={};
}Ticket;
//------------------------------------
void save_users_file(vector<User>);
vector<User> get_users();
long int find_user(vector<User>,User);
void add_user(User);
User user_login(char[101],char[33]);
void edit_user_profile(User new_user);
//------------------------------------
void save_tickets_file(vector<Ticket>);
vector<Ticket> get_tickets(User);
long int find_ticket(vector<Ticket>,Ticket);
void buy_ticket(User,Ticket);
void cancel_ticket(User,Ticket);
//------------------------------------
#endif
