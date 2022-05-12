#include <fstream>
#include <iostream>
#include <ctime>
#include "TicketOffice.h"


int main(int argc, char const *argv[])
{
    try{
    std::tm tm{};
    tm.tm_year = 2022-1900; // 2022
    tm.tm_mon = 5 - 1 ;
    tm.tm_mday = 20; 
    tm.tm_hour = 0;
    tm.tm_min = 0;
    tm.tm_isdst = 0; // Not daylight saving
    std::time_t t = std::mktime(&tm);

    Hall hall1(1, Vector<Performence>(), 5, 5);
    Hall hall2(2, Vector<Performence>(), 4, 4);
    TicketOffice office;
    office.addHall(hall1);
    office.addHall(hall2);


    
    office.addPerformence("1", t,1);
    office.addPerformence("2", t+1,1);
    office.addPerformence("3", t, 2); 
    office.addPerformence("3", t+2, 2); 
    office.addPerformence("4", t+1, 2);

    // office.PrintTicketsWithStatus("3", std::mktime(&tm), available);
    office.ReservTicket("1", std::mktime(&tm),2,2,"a","a");
    
    office.ReservTicket("1",t,1,1,"pass","desc");
    office.BuyTicket("4", t+1, 2,2);
    office.BuyTicket("4", t+1, 2,3);
    office.BuyTicket("4", t+1, 3,3);

    office.PrintTicketsWithStatus("1", 0, reserved);    
    // office.PrintTicketsWithStatus("ALL", t+1, bought);
    // office.PrintBouthTicketsForHall(-1);

    std::ofstream myFile;
    myFile.open("test.txt");
    myFile << office;
    myFile.close();

    }
    catch(char const* error){
        std::cout << error;
    }
    return 0;
}

