#ifndef TRAVEL_AGENCY_UI_H
#define TRAVEL_AGENCY_UI_H
#include <string>
using namespace std;
void clrscr();
void clear_menu(int height,int width);
void create_raw_menu(int height,int width);
void add_text_to_raw_menu(string text,int startX,int startY);
void clear_panel(int height,int width);
void create_user_intro_panel();
void create_user_login_panel();
#endif
