#include "Ticket.h"

/**
 * @brief Construct a new Ticket:: Ticket object
 * 
 * @param roll 
 * @param seat 
 */
Ticket::Ticket(int roll, int seat)
    : roll(roll), seat(seat){}

/**
 * @brief 
 * 
 * @return TicketStatus 
 */
TicketStatus Ticket::getStatus() const{
    return available;
}

/**
 * @brief 
 * 
 * @return int 
 */
int Ticket::getRoll() const{
    return roll;
}

/**
 * @brief 
 * 
 * @return int 
 */
int Ticket::getSeat() const{
    return seat;
}
