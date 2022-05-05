#pragma once
#include "Ticket.h"

class ReservedTicket: public Ticket
{
private:
    myString descriptin;
    myString password;
public:
    // This class will alway be created from a Ticket
    // there is no need to make a lot of constructors
    ReservedTicket(Ticket, myString, myString);
    ReservedTicket():Ticket(),descriptin(myString()),password(myString()){}
    TicketStatus getStatus() const;
    myString getPassword() const;
    myString getDescription() const;
};

