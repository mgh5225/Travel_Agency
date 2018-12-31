#ifndef TRAVEL_AGENCY_TICKETS_H
#define TRAVEL_AGENCY_TICKETS_H
#include <vector>
#include "users.h"
using namespace std;
typedef struct ticket{
    int code_order=0;
    int code_discount=0;
    int mode=0;
    int cost=0;
    User customer={};
    //Journey ticket_journey={};
}Ticket;
void save_tickets_file(vector<Ticket>);
vector<Ticket> get_tickets(User);
vector<Ticket> get_tickets_by_mode(int);
long int find_ticket(vector<Ticket>,Ticket);
void add_ticket(User,Ticket);
void remove_ticket(User,Ticket);
#endif