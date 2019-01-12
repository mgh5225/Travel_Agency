//
// Created by Jarvis on 12/30/2018.
//

#ifndef TRAVEL_AGENCY_SOMETHINGNECESSARY_H
#define TRAVEL_AGENCY_SOMETHINGNECESSARY_H
//Clear Screen;
void clrscr();

//Date structure:
typedef struct mydate{
    int year;
    int month;
    int day;
    int hour;
    int min;
    int sec;
}myDate;


//Return Now time:
myDate nowTime();


#endif //TRAVEL_AGENCY_SOMETHINGNECESSARY_H
