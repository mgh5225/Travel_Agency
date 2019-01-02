#ifndef TRAVEL_AGENCY_TICKETS_H
#define TRAVEL_AGENCY_TICKETS_H
#include <vector>
using namespace std;
typedef struct ticket{
    char id[9]={};
    int cost=0;
}Ticket;
vector<Ticket> get_tickets();
long int find_ticket_in_tickets(Ticket);//point or -1
long int find_ticket_in_file(char[9]);//1 or -1
int add_ticket(Ticket);//1 or -1
int remove_ticket(Ticket);//1 or -1
#endif