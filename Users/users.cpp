#include "users.h"
#include <stdio.h>
#include <cstdlib>
void save_user_file(User _user){
    char str[]="Users/";
    char format[]=".usr";
    int i;
    for(i=0;_user.user_name[i]!='\0';i++){
        str[i+6]=_user.user_name[i];
    }
    for(int j=0;j<5;j++){
        str[i+j+1]=format[j];
    }
    FILE* fp=fopen(str,"wb");
    fwrite(&_user,sizeof(User),1,fp);
    fclose(fp);
}
vector<User> get_users(){
    vector<User> users;
    FILE* fp=fopen("Users/b_users.usr","rb");
    if(fp!=NULL){
        while (!feof(fp)){
            User temp={};
            fread(&temp,sizeof(User),1,fp);
            if(temp.user_name[0]=='\0')break;
            users.push_back(temp);
        }
        fclose(fp);
    }
    return users;
}
long int find_user(vector<User> users,User _user){
    for(long int i=0;i<users.size();i++){
        int j;
        for(j=0;j<101 && users[i].user_name[j]==_user.user_name[j];j++);
        if(j==101){
            return i;
        }
    }
    return -1;
}
void add_user(User _user){
    vector<User> users=get_users();
    if(find_user(users,_user)==-1) {
        users.push_back(_user);
        save_users_file(users);
    }

}
User user_login(char user_name[101],char user_pass[33]){
    vector<User> users=get_users();
    for(long int i=0;i<users.size();i++){
        int j;
        for(j=0;j<101 && users[i].user_name[j]==user_name[j];j++);
        if(j==101){
            int k;
            for(k=0;k<33 && users[i].user_pass[k]==user_pass[k];k++);
            if(k==33){
                return users[i];
            }
        }
    }
    return User{};
}
void edit_user_profile(User _user){
    vector<User> users=get_users();
    long int point=find_user(users,_user);
    if(point!=-1) {
        for (int i = 0; i < 33; i++) {
            users[point].user_pass[i] = _user.user_pass[i];
        }
        for (int i = 0; i < 21; i++) {
            users[point].fname[i] = _user.fname[i];
            users[point].lname[i] = _user.lname[i];
            users[point].reference[i] = _user.reference[i];
        }
        for (int i = 0; i < 11; i++) {
            users[point].bank_account[i] = _user.bank_account[i];
        }
        for (int i = 0; i < 12; i++) {
            users[point].phone_number[i] = _user.phone_number[i];
        }
        save_users_file(users);
    }
}
//--------------------------------------------------------------------------
void save_tickets_file(vector<Ticket> tickets){
    FILE* fp=fopen("Users/b_tickets.txt","wb");
    for(long int i=0;i<tickets.size();i++)
        fwrite(&(tickets[i]),sizeof(User),1,fp);
    fclose(fp);
}
vector<Ticket> get_tickets(User _user){
    vector<Ticket> tickets;
    FILE* fp=fopen("Users/b_tickets.txt","rb");
    if(fp!=NULL){
        while (!feof(fp)){
            Ticket temp={};
            fread(&temp,sizeof(User),1,fp);
            int j;
            for(j=0;j<101 && _user.user_name[j]==temp.customer.user_name[j];j++);
            if(j==101)tickets.push_back(temp);
        }
        fclose(fp);
    }
    return tickets;
}
vector<Ticket> get_tickets_by_mode(int MODE){
    vector<Ticket> tickets;
    FILE* fp=fopen("Users/b_tickets.txt","rb");
    if(fp!=NULL){
        while (!feof(fp)){
            Ticket temp={};
            fread(&temp,sizeof(User),1,fp);
            if(temp.mode==MODE)tickets.push_back(temp);
        }
        fclose(fp);
    }
    return tickets;
}
long int find_ticket(vector<Ticket> tickets,Ticket _ticket){
    for(long int i=0;i<tickets.size();i++){
        if(tickets[i].code_order==_ticket.code_order)return i;
    }
    return -1;
}
void add_ticket(User _user, Ticket _ticket){
    vector<Ticket> tickets=get_tickets(_user);
    if(find_ticket(tickets,_ticket)==-1){
        tickets.push_back(_ticket);
        save_tickets_file(tickets);
    }
}
void remove_ticket(User _user, Ticket _ticket){
    vector<Ticket> tickets=get_tickets(_user);
    long int point=find_ticket(tickets,_ticket);
    if(point!=-1) {
        tickets.erase(tickets.begin() + point);
        save_tickets_file(tickets);
    }
}
//--------------------------------------------------------------------------
Ticket buy_ticket(User _user,/*Journey _journey,*/Discount _discount){
    Ticket _ticket={};
    add_ticket(_user,_ticket);
    int r=rand()%100;
    r=r*(rand()%100)+1;
    _ticket.code_order=r;
    _ticket.code_discount=_discount.id;
    int cost=0/*get_journey_cost(_journey)*/;
    if(_discount.dis){
        cost*=_discount.dis;
    }
    _ticket.cost=cost;
    subtract_cost(_user,&_ticket/*,Journey*/);
    return _ticket;
}
//--------------------------------------------------------------------------