#ifndef TRAVEL_AGENCY_USERS_H
#define TRAVEL_AGENCY_USERS_H
#include <vector>
using namespace std;
typedef struct user{
    char user_name[9]={};
    char user_pass[9]={};
    char fname[21]={};
    char lname[21]={};
    char bank_account[11]={};
    char phone_number[12]={};
    char reference[21]={};
}User;
//------------------------------------
void save_users_file(vector<User>);
vector<User> get_users();
long int find_user(vector<User>,User);
void add_user(User);
User user_login(char[9],char[9]);
void edit_user_profile(User);
//------------------------------------
#endif
