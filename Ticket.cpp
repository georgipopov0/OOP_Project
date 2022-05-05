#include "Ticket.h"

Ticket::Ticket(Performence performence, int roll, int seat)
    :performence(performence), roll(roll), seat(seat){}

TicketStatus Ticket::getStatus() const{
    return available;
}

Performence Ticket::getPerformence() const{
    return performence;
}

int Ticket::getRoll() const{
    return roll;
}

int Ticket::getSeat() const{
    return seat;
}