#include "Controller.h"
#include <cstring>


/**
 * @brief Prints a manual.
 * 
 */
void Controller::printBanner(){
    std::cout << "Options:" << std::endl 
        << "1) Add performence" << std::endl
        << "2) Print availabe tickets" << std::endl
        << "3) Resrve Ticket" << std::endl
        << "4) Cancel reservation" << std::endl
        << "5) Buy ticket" << std::endl
        << "6) Print reserved tickets" << std::endl
        << "7) Print bought tickets" << std::endl
        << "8) Exit" << std::endl;
};

/**
 * @brief Starts a dialog for date input
 * 
 * @return time_t The date from the form in epoch format.
 */
time_t Controller::dateForm(){
    std::cout << "Date\n";
    std::tm time;
    std::cout<<"Year: ";
    char year[4];
    std::cin >> year;

    if(!strcmp(year,"ALL")){
        return 0;
    }

    time.tm_year =  std::atoi(year) - 1900;
    std::cout << "Month: ";
    char month[3];
    std::cin >> month;
    time.tm_mon = std::atoi(month) - 1;
    std::cout << "Day: ";
    char day[3];
    std::cin >> day;
    time.tm_mday = std::atoi(day);
    std::cout << "Hour: ";
    char hour[3];
    std::cin >> hour;
    time.tm_hour = std::atoi(hour);
    std::cout << "Minutes: ";
    char minutes[3];
    std::cin >> minutes;
    time.tm_min = std::atoi(minutes);

    return mktime(&time);
};

/**
 * @brief Starts a dialog for adding a new performance
 * 
 */
void Controller::addPerformence(){
    char title[256];
    std::cout << "Title: ";
    std::cin >> title;
    // std::cin.get();
    std::cout << "Hall: ";
    char hallId[4];
    std::cin >> hallId;
    time_t time = dateForm();

    office.addPerformence(title, time, std::atoi(hallId));
};

/**
 * @brief Prints available tickets for a given performance.
 * 
 */
void Controller::printAvailable(){
    char title[256];
    std::cout << "Title :";
    std::cin >> title;
    time_t time = dateForm();
    office.PrintTicketsWithStatusToConsole(title, time, available);
};


/**
 * @brief Start a dialog for ticket reservation.
 * 
 */
void Controller::reserveTicket(){
    char title[256];
    std::cout << "Title :" << std::endl;
    std::cin >> title;
    time_t date = dateForm();
    char roll[4];
    std::cout << "Roll:" << std::endl;
    std::cin >> roll;
    char seat[4];
    std::cout << "Seat:" << std::endl;
    std::cin >> seat;
    char pass[64];
    std::cout << "Password:" << std::endl;
    std::cin >> pass;
    char desc[256];
    std::cout << "Description:" << std::endl;
    std::cin >> desc;

    office.ReservTicket(title, date,  std::atoi(roll),  std::atoi(seat), pass, desc);
};


/**
 * @brief Starts a dialog for reservation cancelation.
 * 
 */
void Controller::cancelReservation(){
    char title[256];
    std::cout << "Title :" << std::endl;
    std::cin >> title;
    time_t date = dateForm();
    char roll[4];
    std::cout << "Roll:" << std::endl;
    std::cin >> roll;
    char seat[4];
    std::cout << "Seat:" << std::endl;
    std::cin >> seat;

    office.CancelReservation(title, date,  std::atoi(roll),  std::atoi(seat));
}


/**
 * @brief Starts a dialog for buying tickets.
 * 
 */
void Controller::buyTicket(){
    char title[256];
    std::cout << "Title :" << std::endl;
    std::cin >> title;
    time_t date = dateForm();
    char roll[4];
    std::cout << "Roll:" << std::endl;
    std::cin >> roll;
    char seat[4];
    std::cout << "Seat:" << std::endl;
    std::cin >> seat;

    office.BuyTicket(title, date,  std::atoi(roll),  std::atoi(seat));
}

/**
 * @brief Creats report files for the reservations.
 * 
 */
void Controller::printReservations(){
    std::cout << "Title :" << std::endl;
    char title[256];
    std::cin >> title;
    time_t time = dateForm();
    office.PrintTicketsWithStatusToFile(title, time, reserved);
}

/**
 * @brief Prints bought tickets for a performance
 * 
 */
void Controller::printBoughtTicketsForHall(){
    char hallId[4];
    std::cout << "Hall id:";
    std::cin >> hallId;

    office.PrintBouthTicketsForHall( std::atoi(hallId));
}


/**
 * @brief Intializes an infinite loop for command interpretation.
 * 
 */
void Controller::init(){
    TicketOffice office;
    bool exit = 0;
    while (!exit)
    {
        printBanner();
        char input;
        std::cin >> input;
        try{
            switch (input)
            {
            case '1':
                addPerformence();
                break;
            case '2':
                printAvailable();
                break;

            case '3':
                ReservedTicket();
                break;

            case '4':
                cancelReservation();
                break;

            case '5':
                buyTicket();
                break;

            case '6':
                printReservations();
                break;

            case '7':
                printBoughtTicketsForHall();
                break;

            case '8':
                exit = true;
                break;

            default:
                break;
            }
        }catch(const char* message){
            std::cout << message << std::endl;
        }
    }
}
