#pragma once

#include <ctime>
#pragma once
#include "myString.h"
#include "myVector.h"
#include "ReservedTicket.h"
#include "BoughtTicket.h"

class Performence
{
private:
    std::time_t date;
    myString title;
    Vector<Ticket*> tickets;

    void deleteTickets();
    void copyTickets(const Performence &);

public:
    Performence():title(myString()), date(std::time_t(), tickets(nullptr)){}
    Performence(std::time_t date, myString title);
    Performence(const Performence&);
    Performence(Performence&& performence);
    Performence& operator=(const Performence&);
    
    myString getTitle()const;
    std::time_t getDate()const;
    const Vector<Ticket*>& getTickets()const;

    void generateTickets(int rolls, int seats);
};
