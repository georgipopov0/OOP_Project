#pragma once
#include "Ticket.h"
#include "Hall.h"
#include <fstream>

class TicketOffice
{
private:
    Vector<Hall> halls;

    Performence& findPerformence(myString title, std::time_t date )const;
    Hall& findHall(int hallId) const;
    void save(const char* filename);

public:
    TicketOffice():halls(Vector<Hall>()){
        std::ifstream in;
        in.open("savefile.txt");
        if (in.is_open())
        {
            in >> *this;
        }
        
    }
    
    void addHall(Hall);
    void addPerformence(const char* title, time_t date, int hallId);
    
    const Vector<Hall>& getHalls()const;
    
    void PrintTicketsWithStatus(const char*, time_t, TicketStatus)const;
    void PrintBouthTicketsForHall(int) const;
    
    void ReservTicket(const char*, time_t, int, int, myString, myString);
    void CancelReservation(const char*, time_t, int, int);
    void BuyTicket(const char*, time_t, int, int);

    friend std::ofstream& operator <<(std::ofstream & output, TicketOffice const& ticketOffice);    
    friend std::ifstream& operator >>(std::ifstream& is, TicketOffice& office);
};
