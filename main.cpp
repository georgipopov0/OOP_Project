#include <iostream>
#include <ctime>
#include "TicketOffice.h"


int main(int argc, char const *argv[])
{
    try{
    Vector<int> vector;
    for (int i = 0; i < 20; i++)
    {
        vector.push(i);
    }
    
    for (int j = 0; j < 20; j++)
    {
        std::cout << vector.get(j) << std::endl;
    }

    std::tm tm{};
    tm.tm_year = 2020-1900; // 2020
    tm.tm_mon = 2; // February
    tm.tm_mday = 15; // 15th
    tm.tm_hour = 10;
    tm.tm_min = 15;
    tm.tm_isdst = 0; // Not daylight saving
    std::time_t t = std::mktime(&tm);

    Hall hall(1, Vector<Performence>(), 5, 5);
    TicketOffice office;
    office.addHall(hall);

    office.addPerformence(Performence(std::mktime(&tm),myString("1")),1);
    office.PrintTicketsWithStatus(myString("1"), std::mktime(&tm), available);
    
    office.ReservTicket(myString("1"), std::mktime(&tm),2,2,myString("a"),myString("a"));
    office.PrintTicketsWithStatus(myString("1"), std::mktime(&tm), reserved);
    // std::cout << hall.getHallId() << hall.getRolls() << hall.getSeats() << hall.getPerformences().get(0).getTitle().getChar();
    // // hall.addPerformence(Performence(std::mktime(&tm),myString("title2")));
    // std::cout << std::endl << "size: "<< hall.getPerformences().get(0).getTickets().size();
    // hall.getPerformences().get(0).ReserveTicket(0,0,myString("ads"), myString("ads"));

    // Vector<Ticket*> ave = hall.getPerformences().get(0).getTicktesWithStatus(reserved);
    // std::cout << "asd " << ave.size();
    // for (int i = 0; i < ave.size(); i++)
    // {
    //     std::cout << "a" ;
    //     std::cout << "roll: " << ave.get(i)->getRoll() << "seat: " << ave.get(i)->getSeat() << std::endl;
    // }
    
    // hall.getPerformences().get(0).BuyTicket(0,0);

    // ave = hall.getPerformences().get(0).getTicktesWithStatus(bought);
    // std::cout << ave;

    // std::cout<<a<<b<<c;
    return 0;
    }
    catch(char const* error){
        std::cout << error;
    }
}
