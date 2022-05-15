#pragma once
#include <ctime>
#include "myString.h"
#include "myVector.h"
#include "ReservedTicket.h"
#include "BoughtTicket.h"

class Performance
{
private:
    std::time_t date;/** Date of the performance */
    myString title;/** Title of the performance*/
    Vector<Ticket*> tickets;/** List of tickets for the performance (Runtime polymorphism) */
    
    void deleteTickets();
    void copyTickets(const Performance &);
    Ticket* &findTicket(int,int)const;

public:
    Performance():title(myString()), date(std::time_t()), tickets(Vector<Ticket*>()){}
    Performance(std::time_t date, myString title);
    Performance(const Performance&);
    myString getTitle()const;
    Performance(Performance&& performence);
    ~Performance();
    Performance& operator=(const Performance&);
    std::time_t getDate()const;
    const Vector<Ticket*>& getTickets()const;


    void generateTickets(int rolls, int seats);
    Vector<Ticket*> getTicktesWithStatus(TicketStatus) const;
    void ReserveTicket(int roll, int seat, myString, myString);
    void CancelReservation(int roll, int seat);
    void BuyTicket(int roll, int seat);

    //Hardcode for file reading
    void UpdateTicket(Ticket* newTicket);
    void UpdateTickets( const Vector<Ticket*>& tickets);
};
