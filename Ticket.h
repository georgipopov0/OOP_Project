#pragma once
#include "Performence.h"

    // Not sure where to put the enum
    enum TicketStatus{
        available,
        bought,
        reserved
    };

class Ticket
{
private:


    Performence performence;
    int roll;
    int seat;

public:
    Ticket():performence(Performence()), roll(0), seat(0){}
    Ticket(Performence,int,int);

    virtual TicketStatus getStatus() const;
    Performence getPerformence() const;
    int getRoll() const;
    int getSeat() const;
};