#include "ReservedTicket.h"

ReservedTicket::ReservedTicket(Ticket ticket, myString arg_description, myString arg_password)
    :Ticket(ticket), descriptin(arg_description), password(arg_password){}

TicketStatus ReservedTicket::getStatus() const{
    return reserved;
}

myString ReservedTicket::getPassword() const{
    return password;
}

myString ReservedTicket::getDescription() const{
    return descriptin;
}