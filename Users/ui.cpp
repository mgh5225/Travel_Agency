#include "ui.h"
#include <stdio.h>
#include <Windows.h>
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
void create_raw_menu(int height,int width,int startX ,int startY,bool clear_screen){
    if(clear_screen)clrscr();
    for(int i=1;i<=height;i++){
        gotoXY(startX,i+startY-1);
        printf("*");
        gotoXY(width+startX-1,i+startY-1);
        printf("*");
        _sleep(10);

    }
    for(int i=1;i<=width;i++){
        gotoXY(i+startX-1,startY);
        printf("*");
        gotoXY(i+startX-1,height+startY-1);
        printf("*");
        _sleep(10);
    }
    gotoXY(1,height+1);
}
void add_text_to_raw_menu(string text,int startX,int startY){
    gotoXY(startX,startY);
    printf("%s",text.c_str());
}
void clear_panel(int height,int width,int startX,int startY){
    for(int i=1;i<=height;i++){
        for(int j=1;j<=width;j++){
            _sleep(1);
            gotoXY(j+startX-1,i+startY-1);
            printf(" ");
        }
    }
    clrscr();
}
string input(int min_char,int max_char,char output_char,bool can_num,bool can_word,bool can_char){
    int i=0;
    string output;
    while(true){
        char n=(char)_getch();
        bool is_num=(n>='0' && n<='9') && can_num;
        bool is_word=((n>='a' && n<='z') || (n>='A' && n<='Z'))&&can_word;
        bool is_char=n>32 && n!=127 && can_char;
        if(n==13 && (output.length()>=min_char)) break;
        if(i<max_char){
            if(is_char || is_num || is_word) {
                i++;
                output += n;
                if(output_char=='\0') printf("%c", n);
                else printf("%c", output_char);
            }
        }
        if(n=='\b' && i>0){
            i--;
            output.erase(output.end()-1);
            printf("%c %c",n,n);
        }
    }
    return output;
}
