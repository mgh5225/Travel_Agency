#ifndef TRAVEL_AGENCY_MAIN_H
#define TRAVEL_AGENCY_MAIN_H
#include "ui.h"
#include "users.h"
#include "tickets.h"
void create_user_intro_panel();
void create_user_login_panel();
void create_user_panel(User);
void create_user_register_panel();
void create_setting_panel(User);
void create_delete_panel(User);
void create_edit_panel(User);
void create_guest_register_panel();
#endif