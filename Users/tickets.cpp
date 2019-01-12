#include "tickets.h"
void save_def_file(Ticket _ticket){
    FILE* fp_d=fopen("Users/tics/default.def","ab");
    fwrite(&(_ticket.id),sizeof(char),9,fp_d);
    fclose(fp_d);
}
void save_ticket_file(Ticket _ticket){
    string file_addr="Users/tics/"+(string)_ticket.id+".tic";
    FILE* fp_t=fopen(file_addr.c_str(),"wb");
    fwrite(&_ticket,sizeof(Ticket),1,fp_t);
    fclose(fp_t);
}
vector<Ticket> get_tickets(){
    vector<Ticket> tickets;
    FILE* fp_d=fopen("Users/tics/default.def","rb");
    if(fp_d!=NULL){
        while (true){
            char id[9]={};
            fread(&id,sizeof(char),9,fp_d);
            if(feof(fp_d))break;
            string file_addr="Users/tics/"+(string)id+".tic";
            Ticket temp={};
            FILE* fp_t=fopen(file_addr.c_str(),"rb");
            fread(&temp, sizeof(Ticket),1,fp_t);
            fclose(fp_t);
            tickets.push_back(temp);
        }
        fclose(fp_d);
    }
    return tickets;
}
Ticket get_ticket(char id[9]){
    string file_addr="Users/tics/"+(string)id+".tic";
    FILE* fp_t=fopen(file_addr.c_str(),"rb");
    Ticket temp={};
    if(fp_t!=NULL) {
        fread(&temp, sizeof(Ticket),1,fp_t);
        fclose(fp_t);
    }
    return temp;
}
vector<Ticket> get_user_tickets(User _user){
    vector<Ticket> tickets;
    FILE* fp_d=fopen("Users/tics/default.def","rb");
    if(fp_d!=NULL){
        while (true){
            char id[9]={};
            fread(&id,sizeof(char),9,fp_d);
            if(feof(fp_d))break;
            string file_addr="Users/tics/"+(string)id+".tic";
            Ticket temp={};
            FILE* fp_t=fopen(file_addr.c_str(),"rb");
            fread(&temp, sizeof(Ticket),1,fp_t);
            fclose(fp_t);
            int i;
            for(i=0;i<9 && temp.customer[i]==_user.user_name[i];i++);
            if(i==9) tickets.push_back(temp);
        }
        fclose(fp_d);
    }
    return tickets;
}
long int find_ticket_in_tickets(Ticket _ticket){
    vector<Ticket> tickets=get_tickets();
    for(long int i=0;i<tickets.size();i++){
        int j;
        for(j=0;j<9 && tickets[i].id[j]==_ticket.id[j];j++);
        if(j==9){
            return i;
        }
    }
    return -1;
}
long int find_ticket_in_file(char id[9]){
    string file_addr="Users/tics/"+(string)id+".tic";
    FILE* fp_t=fopen(file_addr.c_str(),"rb");
    if(fp_t==NULL) return -1;
    fclose(fp_t);
    return 1;
}
int add_ticket(Ticket _ticket){
    if(find_ticket_in_file(_ticket.id)==-1) {
        save_ticket_file(_ticket);
        save_def_file(_ticket);
        return 1;
    }
    return -1;
}
int remove_ticket(Ticket _ticket){
    if(find_ticket_in_file(_ticket.id)!=-1) {
        vector<Ticket> tickets=get_tickets();
        string file_addr="Users/tics/"+(string)_ticket.id+".tic";
        long int point=find_ticket_in_tickets(_ticket);
        tickets.erase(tickets.begin()+point);
        remove("Users/tics/default.def");
        remove(file_addr.c_str());
        for(int i=0;i<tickets.size();i++){
            save_def_file(tickets[i]);
        }
        return 1;
    }
    return -1;
}
//--------------------------------------------------------------------------