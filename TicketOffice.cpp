#include "TicketOffice.h"

Performence& TicketOffice::findPerformence(myString title, std::time_t date) const{
for (int i = 0; i < halls.size(); i++)
    {
        Performence *performence = halls.get(i).findPerformence(title, date);
        if (performence)
        {
            return *performence;
        }
    }
    throw "Performence not found";
}

Hall& TicketOffice::findHall(int hallId) const{
    for (int i = 0; i < halls.size(); i++)
    {
        Hall& hall = halls.get(i);
        if(hall.getHallId() == hallId){
            return hall;
        }
    }
    throw "Hall not found";
}

void TicketOffice::addPerformence(Performence performence, int hallId){
    Hall& hall = findHall(hallId);
    hall.addPerformence(performence);
}

const Vector<Hall>& TicketOffice::getHalls()const{
    return halls;
}

Vector<Ticket*> TicketOffice::getAvailableTickets(myString title, time_t date) const{
    Performence& performence = findPerformence(title, date);
    return performence.getAvailableTicktes();
}

