#ifndef TRAVEL_AGENCY_UI_H
#define TRAVEL_AGENCY_UI_H
#include <string>
using namespace std;
void clrscr();
void gotoXY(int x ,int y);
int move_between_items(int items[][2],int l);
void create_raw_menu(int height,int width,int startX,int startY,bool clear_screen);
void add_text_to_raw_menu(string text,int startX,int startY);
void clear_panel(int height,int width,int startX,int startY);
string input(int max_char);
#endif
