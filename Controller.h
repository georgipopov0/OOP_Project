#pragma once
#include "TicketOffice.h"

class Controller
{
private:

    TicketOffice office;    

    void printBanner();
    time_t dateForm();
    void addPerformence();
    void printAvailable();
    void reserveTicket();
    void cancelReservation();
    void buyTicket();
    void printReservations();
    void printBoughtTicketsForHall();
public:
    Controller():office(TicketOffice("savefile.txt")){}
    void init();
};