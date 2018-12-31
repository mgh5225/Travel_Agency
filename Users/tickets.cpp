#include "tickets.h"
#include "users.h"
#include <stdio.h>
void save_tickets_file(vector<Ticket> tickets){
    FILE* fp=fopen("Users/b_tickets.txt","wb");
    for(long int i=0;i<tickets.size();i++)
        fwrite(&(tickets[i]),sizeof(Ticket),1,fp);
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
            for(j=0;j<9 && _user.user_name[j]==temp.customer.user_name[j];j++);
            if(j==9)tickets.push_back(temp);
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