#ifndef TRAVEL_AGENCY_USERS_H
#define TRAVEL_AGENCY_USERS_H
#include <vector>
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
void save_users_file(vector<User>);
vector<User> get_users();
User user_login(char[101],char[33]);
long int find_user(vector<User>,User);
void edit_user_profile(User new_user);
void add_user(User);
#endif
