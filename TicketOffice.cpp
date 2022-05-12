#include "TicketOffice.h"
#include <cstring>

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
            Vector<Performence*> performences = halls.get(i).findPerformence(title);
            int perf_size = performences.size();
            for (int i = 0; i < perf_size; i++)
            {
                time_t time = performences.get(i)->getDate();
                std::cout << "-----------------------------------" << std::endl
                        << performences.get(i)->getTitle().getChar() << " " << ctime(&time) << std::endl
                        << ": "  << performences.get(i)->getTicktesWithStatus(status);
            }
            }catch(char const*){
                std::cout << "wtd";
            }
        }
    }
    else if(!strcmp(title, "ALL"))
    {
        int halls_size = halls.size();
        for (int i = 0; i < halls_size; i++)
        {
            try{
            Vector<Performence*> performences = halls.get(i).findPerformence(date);
            int perf_size = performences.size();
            for (int i = 0; i < perf_size; i++)
            {
                std::cout << "-----------------------------------" << std::endl
                        << performences.get(i)->getTitle().getChar() << std::endl
                        << ": "  << performences.get(i)->getTicktesWithStatus(status);
            }
            }catch(char const*){
                //change that later
                std::cout << "wtf";
            }
        }
    }
    else{
        Performence& performence = findPerformence(title, date);
        Vector<Ticket*> tickets = performence.getTicktesWithStatus(status);
        std::cout << tickets;
    }
}

void TicketOffice::PrintBouthTicketsForHall(int hallId)const{
    // Equal to ALL
    if(hallId = -1){
        int halls_size = halls.size();
        for (int i = 0; i < halls_size; i++)
        {
            Hall& hall = halls.get(i);
            const Vector<Performence>& perf = hall.getPerformences();
            int perf_size = perf.size();
            std::cout << "----------------------------" << std::endl 
                << "Hall number " << hall.getHallId() << std::endl;
            for (int i = 0; i < perf_size; i++)
            {
                time_t time = perf.get(i).getDate();
                std::cout << perf.get(i).getTitle().getChar() << " " << ctime(&time)
                    << " | " << "Sold: " << perf.get(i).getTicktesWithStatus(bought).size();
            }
        }
    }
    else{
        Hall hall = this->findHall(hallId);
        const Vector<Performence>& perf = hall.getPerformences();
        int perf_size = perf.size();
        std::cout << "----------------------------" << std::endl 
            << "Hall number " << hall.getHallId() << std::endl;
        for (int i = 0; i < perf_size; i++)
        {
            time_t time = perf.get(i).getDate();
            std::cout << perf.get(i).getTitle().getChar() << " " << ctime(&time)
                << " | " << "Sold: " << perf.get(i).getTicktesWithStatus(bought).size();
        }
    }
}

// Pretty shure some lambda
// magic can be used here ...
void TicketOffice::ReservTicket(const char* title, time_t date, int roll, int seat, myString pass, myString description = myString()){
    this->findPerformence(title,date).ReserveTicket(roll, seat, pass, description);
}

void TicketOffice::CancelReservation(const char* title, time_t date, int roll, int seat){
    this->findPerformence(title, date).CancelReservation(roll, seat);
}

void TicketOffice::BuyTicket(const char* title, time_t date, int roll, int seat){
    this->findPerformence(title, date).BuyTicket(roll, seat);
}