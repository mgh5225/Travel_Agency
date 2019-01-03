#ifndef TRAVEL_AGENCY_USERS_H
#define TRAVEL_AGENCY_USERS_H
#include <vector>
#include "define.h"
using namespace std;
//------------------------------------
vector<User> get_users();
User get_user(char[9]);
int add_user(User);
User user_login(char[9],char[9]);
void edit_user_profile(User);
long int find_user_in_file(char[9]);
//------------------------------------
#endif
