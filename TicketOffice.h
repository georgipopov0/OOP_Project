#pragma once
#include "Ticket.h"
#include "Hall.h"

class TicketOffice
{
private:
    Vector<Hall> halls;

    Performence& findPerformence(myString title, std::time_t date )const;
    Hall& findHall(int hallId) const;
    

public:
    TicketOffice():halls(Vector<Hall>()){}
    void addHall(Hall);
    void addPerformence(Performence, int hallId);
    const Vector<Hall>& getHalls()const;
    void PrintTicketsWithTitle();
    void PrintTicketsWithStatus(myString, time_t, TicketStatus)const;
    void ReservTicket(myString, time_t, int, int, myString, myString);
    void CancelReservation(myString, time_t, int, int);
    void BuyTicket(myString, time_t, int, int);
};
