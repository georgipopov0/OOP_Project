#pragma once
#include "Ticket.h"

/**
 * @brief 
 * 
 */
class BoughtTicket : public Ticket
{
private:
public:
    BoughtTicket():Ticket::Ticket(){}
    BoughtTicket(Ticket);
    TicketStatus getStatus() const;
};