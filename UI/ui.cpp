#include "ui.h"
#include <stdio.h>
#include <windows.h>
#include <conio.h>
void clrscr(){
    system("@cls");
}
void gotoXY(int x ,int y){
    COORD pos = {(short)x, (short)y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}
int move_between_items(int items[][2],int l){
    int n=0;
    int i = 0;
    while (n!=13) {
        n =_getch();
        if (n == 's') {
            i += 1;
            if (i == l) i = 0;
        }
        if (n == 'w') {
            i -= 1;
            if (i == -1) i = l - 1;
        }
        gotoXY(items[i][0], items[i][1]);
    }
    return i;
}
void create_raw_menu(int height,int width){
    clrscr();
    for(int i=1;i<=height;i++){
        gotoXY(1,i);
        printf("*");
        gotoXY(width,i);
        printf("*");
        _sleep(10);
    }
    for(int i=1;i<=width;i++){
        gotoXY(i,1);
        printf("*");
        gotoXY(i,height);
        printf("*");
        _sleep(10);
    }
    gotoXY(1,height+1);
}
void add_text_to_raw_menu(string text,int startX,int startY){
    gotoXY(startX,startY);
    printf("%s",text.c_str());
}
void clear_panel(int height,int width){
    for(int i=1;i<=height;i++){
        for(int j=1;j<=width;j++){
            _sleep(1);
            gotoXY(j,i);
            printf(" ");
        }
    }
    clrscr();
}
