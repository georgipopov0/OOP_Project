#include "BoughtTicket.h"

BoughtTicket::BoughtTicket(Ticket Ticket):Ticket(Ticket){}

TicketStatus BoughtTicket::getStatus() const{
    return bought;
}