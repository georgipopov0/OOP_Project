#pragma once

    // Not sure where to put the enum
    enum TicketStatus{
        available = 1,
        bought = 2,
        reserved = 3
    };

class Ticket
{
protected:
    int roll;
    int seat;

public:
    Ticket():roll(0), seat(0){}
    Ticket(int,int);

    virtual TicketStatus getStatus() const;
    int getRoll() const;
    int getSeat() const;
};