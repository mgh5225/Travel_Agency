#include "users.h"
#include <stdio.h>
void save_users_file(vector<User> users){
    FILE* fp=fopen("Users/b_users.txt","wb");
    for(long int i=0;i<users.size();i++)
        fwrite(&(users[i]),sizeof(User),1,fp);
    fclose(fp);
}
vector<User> get_users(){
    vector<User> users;
    FILE* fp=fopen("Users/b_users.txt","rb");
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
void add_user(User new_user){
    vector<User> users=get_users();
    if(find_user(users,new_user)==-1) {
        users.push_back(new_user);
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
void edit_user_profile(User new_user){
    vector<User> users=get_users();
    long int point=find_user(users,new_user);
    for(int i=0;i<33;i++){
        users[point].user_pass[i]=new_user.user_pass[i];
    }
    for(int i=0;i<21;i++){
        users[point].fname[i]=new_user.fname[i];
        users[point].lname[i]=new_user.lname[i];
        users[point].reference[i]=new_user.reference[i];
    }
    for(int i=0;i<11;i++){
        users[point].bank_account[i]=new_user.bank_account[i];
    }
    for(int i=0;i<12;i++){
        users[point].phone_number[i]=new_user.phone_number[i];
    }
    save_users_file(users);
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
long int find_ticket(vector<Ticket> tickets,Ticket _ticket){
    for(long int i=0;i<tickets.size();i++){
        if(tickets[i].code==_ticket.code)return i;
    }
    return -1;
}
void cancel_ticket(User _user,Ticket _ticket){
    vector<Ticket> tickets=get_tickets(_user);
    long int point=find_ticket(tickets,_ticket);
    tickets.erase(tickets.begin()+point);
    save_tickets_file(tickets);
}