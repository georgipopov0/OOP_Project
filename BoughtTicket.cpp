#include "BoughtTicket.h"

/**
 * @brief Construct a new Bought Ticket:: Bought Ticket object
 * 
 * @param Ticket 
 */
BoughtTicket::BoughtTicket(Ticket Ticket):Ticket::Ticket(Ticket){}

/**
 * @brief 
 * 
 * @return TicketStatus 
 */
TicketStatus BoughtTicket::getStatus() const{
    return bought;
}