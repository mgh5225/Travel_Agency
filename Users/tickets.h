#ifndef TRAVEL_AGENCY_TICKETS_H
#define TRAVEL_AGENCY_TICKETS_H
#include "define.h"
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;
vector<Ticket> get_tickets();
vector<Ticket> get_user_tickets(User);
Ticket get_ticket(char[9]);
long int find_ticket_in_tickets(Ticket);//point or -1
long int find_ticket_in_file(char[9]);//1 or -1
int add_ticket(Ticket);//1 or -1
int remove_ticket(Ticket);//1 or -1
#endif