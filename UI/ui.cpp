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
void move_between_items(int items[][2],int l){
    int n=0;
    while (n!=13) {
        static int i = 0;
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
            _sleep(10);
            gotoXY(j,i);
            printf(" ");
        }
    }
    clrscr();
}
void create_user_intro_panel(){
    int items[4][2]={{5,3},{5,4},{5,5},{5,9}};
    int h=11;
    int w=33;
    create_raw_menu(h,w);
    add_text_to_raw_menu("[1] Login Into Your Account.",4,3);
    add_text_to_raw_menu("[2] Create New Account.",4,4);
    add_text_to_raw_menu("[3] Join As A Guest.",4,5);
    for(int i=2;i<w;i++){
        add_text_to_raw_menu("-",i,7);
    }
    add_text_to_raw_menu("[4] Back To Previous Panel.",4,9);
    gotoXY(5,3);
    move_between_items(items,4);
    gotoXY(1,h+1);
}
void create_user_login_panel(){

}