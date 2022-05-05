#include "ReservedTicket.h"

ReservedTicket::ReservedTicket(Ticket ticket, myString getDescription, myString password)
    :Ticket(ticket), descriptin(descriptin), password(password){}

TicketStatus ReservedTicket::getStatus() const{
    return reserved;
}

myString ReservedTicket::getPassword() const{
    return password;
}

myString ReservedTicket::getDescription() const{
    return descriptin;
}