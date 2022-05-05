#pragma once
#include "Ticket.h"

class BoughtTicket : public Ticket
{
private:
public:
    BoughtTicket():Ticket(){}
    BoughtTicket(Ticket);
    TicketStatus getStatus() const;
};