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
    void addPerformence(Performence, int hallId);
    const Vector<Hall>& getHalls()const;
    Vector<Ticket*> getAvailableTickets(myString, time_t)const;
    void ReservTicket(myString, time_t, Ticket*);
    void CancelReservation(myString, time_t, Ticket* );
    void BuyTicket(myString, time_t, Ticket*);
    Vector<ReservedTicket> getReservations()const;
    Vector<BoughtTicket> getBoughtTickets()const;


};
