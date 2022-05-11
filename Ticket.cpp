#include "Ticket.h"

Ticket::Ticket(int roll, int seat)
    : roll(roll), seat(seat){}

TicketStatus Ticket::getStatus() const{
    return available;
}

int Ticket::getRoll() const{
    return roll;
}

int Ticket::getSeat() const{
    return seat;
}
