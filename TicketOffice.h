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
    void addPerformence(const char* title, time_t date, int hallId);
    const Vector<Hall>& getHalls()const;
    void PrintTicketsWithStatus(const char*, time_t, TicketStatus)const;
    void PrintBouthTicketsForHall(int) const;
    void ReservTicket(const char*, time_t, int, int, myString, myString);
    void CancelReservation(const char*, time_t, int, int);
    void BuyTicket(const char*, time_t, int, int);
};
