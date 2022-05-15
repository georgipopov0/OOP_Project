#pragma once
#include "TicketOffice.h"


/**
 * @brief Handles the user interactions.
 * 
 */
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
    /**
     * @brief Construct a new Controller object fom a savefile
     * 
     */
    Controller():office(TicketOffice("savefile.txt")){}
    void init();
};