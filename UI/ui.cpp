#include "ui.h"
#include <stdio.h>
#include <unistd.h>
void clrscr(){
    printf("\033[2J\033[1;1H");
}
void gotoXY(int x ,int y){
    printf("\033[%d;%dH", y, x);
}
void move_between_items(int items[],int l){

    int n;
    while (n!='\n') {
        static int i = 1;
        system("stty cbreak");
        n = getc(stdin);
        gotoXY(items[0], items[i]);
        printf("%d", i);
        if (n == 's') {
            i += 1;
            if (i == l) i = 1;
        }
        if (n == 'w') {
            i -= 1;
            if (i == 0) i = l - 1;
        }
        gotoXY(items[0], items[i]);
    }
}
void create_raw_menu(int height,int width){
    clrscr();
    for(int i=1;i<=height;i++){
        gotoXY(1,i);
        printf("*");
        gotoXY(width,i);
        printf("*");
    }
    for(int i=1;i<=width;i++){
        gotoXY(i,1);
        printf("*");
        gotoXY(i,height);
        printf("*");
    }
    gotoXY(1,height+1);
}
void add_text_to_raw_menu(string text,int startX,int startY){
    gotoXY(startX,startY);
    printf("%s",text.c_str());
}
void create_user_intro_panel(){
    int items[5]={5,3,4,5,9};
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
    move_between_items(items,5);
    gotoXY(1,h+1);
}