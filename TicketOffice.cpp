#include "TicketOffice.h"

// The hardcode is real
// (had to put it here or the linker gets angry)
std::ostream& operator<<(std::ostream& os, const Vector<Ticket*>& vec){
    int size = vec.size();
    for (int i = 0; i < size; i++)
    {
        os << "(" << vec.get(i)->getRoll() << "," << vec.get(i)->getSeat() << ")" <<std::endl;
    }
    return os;
}


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

void TicketOffice::addHall(Hall hall){
    this->halls.push(hall);
}


void TicketOffice::addPerformence(const char* title, time_t date, int hallId){
    Hall& hall = findHall(hallId);
    hall.addPerformence(Performence(date, myString(title)));
}

const Vector<Hall>& TicketOffice::getHalls()const{
    return halls;
}



void TicketOffice::PrintTicketsWithStatus(const char* title, time_t date, TicketStatus status)const{
    // Eqivalent to ALL
    if(date == 0){
        int halls_size = halls.size();
        for (int i = 0; i < halls_size; i++)
        {
            try{
            Vector<Performence> performences = halls.get(i).findPerformence(title);
            int perf_size = performences.size();
            for (int i = 0; i < perf_size; i++)
            {
                std::cout << performences.get(i).getTitle().getChar() 
                        << ": "  << performences.get(i).getTickets();
            }
            }catch(char const*){
                std::cout << "wtd";
            }
        }
    }
    else{
        Performence& performence = findPerformence(title, date);
        Vector<Ticket*> tickets = performence.getTicktesWithStatus(status);
        std::cout << tickets;
    }
}

// Pretty shure some functional 
// programing magic cat be used here ...
void TicketOffice::ReservTicket(const char* title, time_t date, int roll, int seat, myString pass, myString description = myString()){
    this->findPerformence(title,date).ReserveTicket(roll, seat, pass, description);
}

void TicketOffice::CancelReservation(const char* title, time_t date, int roll, int seat){
    this->findPerformence(title, date).CancelReservation(roll, seat);
}

void TicketOffice::BuyTicket(const char* title, time_t date, int roll, int seat){
    this->findPerformence(title, date).BuyTicket(roll, seat);
}