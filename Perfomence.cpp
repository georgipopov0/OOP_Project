#include <iostream>
#include "Performence.h"
#include <cstring>

/**
 * @brief Clears the allocated memmory for the tickets
 * 
 */
void Performance::deleteTickets(){
    for (int i = 0; i < this->tickets.size(); i++)
    {
        delete this->tickets.get(i);
    }
}

/**
 * @brief Coppies the tickets of another performence.
 * 
 * @param performence 
 */
void Performance::copyTickets(const Performance& performence){
    for (int i = 0; i < performence.tickets.size(); i++)
    {
        this->tickets.push(new Ticket(*performence.tickets.get(i)));
    }
}

/**
 * @brief Find a ticket.
 * 
 * @param roll Roll of the ticket.
 * @param seat Seat of the ticket.
 * @return Ticket*& Referrence to the found ticket.
 */
Ticket* &Performance::findTicket(int roll, int seat) const{
    int rollSize = 0;
    for (int i = 0;  tickets.get(i)->getRoll() == tickets.get(i+1)->getRoll() ; i++)
    {
        rollSize++;
    }
    rollSize++;
    return tickets.get(rollSize*roll + seat);
}


/**
 * @brief Construct a new Performence:: Performence object
 * 
 * @param date 
 * @param title 
 */
Performance::Performance(std::time_t date, myString title)
:date(date), title(title), tickets(Vector<Ticket*>()){}

//not sure that this improves anything 
//but im doing it anyway
/**
 * @brief Move constructor.
 * 
 * @param performence 
 */
Performance::Performance(Performance&& performence){
    this->date=performence.date;
    this->title=performence.title;
    this->tickets=performence.tickets;
    performence.tickets.~Vector();
}

/**
 * @brief Copy constructor
 * 
 * @param performence 
 */
Performance::Performance(const Performance &performence){
    this->date = performence.date;
    this->title = performence.title;
    this->copyTickets(performence);
}

/**
 * @brief Destroy the Performence:: Performence object
 * 
 */
Performance::~Performance(){
    deleteTickets();
}

/**
 * @brief Asignment operator
 * 
 * @param performence 
 * @return Performence& 
 */
Performance& Performance::operator=(const Performance& performence){
    deleteTickets();
    copyTickets(performence);
    this->date = performence.date;
    this->title = performence.title;
    
    return *this;
}

/**
 * @brief 
 * 
 * @return myString Title of the performence.
 */
myString Performance::getTitle()const{
    return title;
}

/**
 * @brief 
 * 
 * @return std::time_t Date of the performence.
 */
std::time_t Performance::getDate()const{
    return date;
}

/**
 * @brief 
 * 
 * @return const Vector<Ticket*>& Refference to the tickets of the performance.
 */
const Vector<Ticket*>& Performance::getTickets() const{
    return tickets;
}

/**
 * @brief Generates tickets for the specified amount of seats.
 * 
 * @param rolls Number of rolls.
 * @param seats Number of seats per roll.
 */
void Performance::generateTickets(int rolls, int seats){
    this->tickets = Vector<Ticket*>();
    for (int i = 0; i < rolls; i++)
    {
        for (int j = 0 ; j < seats; j++)
        { 
            tickets.push(new Ticket(i, j));
        }
    }
    
}

/**
 * @brief Finds all tickets with the specified status (available,reserved,bought).
 * 
 * @param status 
 * @return Vector<Ticket*> Vector containing all tickets with the specified status.
 */
Vector<Ticket*> Performance::getTicktesWithStatus(TicketStatus status)const{
    Vector<Ticket*> availabelTickets;
    for (int i = 0; i < tickets.size(); i++)
    {
        Ticket* tmpTicket = tickets.get(i);
        if(tmpTicket->getStatus() == status){
            availabelTickets.push(tmpTicket);
        }
    }
    return availabelTickets;
}

/**
 * @brief Changes a ticket from Tieckt to ReservedTicket.
 * 
 * @param roll 
 * @param seat 
 * @param password 
 * @param descriprion 
 */
void Performance::ReserveTicket(int roll, int seat, myString password, myString descriprion){
    Ticket* &ticket = findTicket(roll, seat);
    if(ticket->getStatus() != available){
        throw "Not available";
    }
    ReservedTicket* reserved =  new ReservedTicket(*ticket, descriprion, password);
    delete ticket;
    ticket = reserved;
    reserved = nullptr;
}

/**
 * @brief Returns ticket from ReservedTicket to Ticket
 * 
 * @param roll 
 * @param seat 
 */
void Performance::CancelReservation(int roll, int seat){
    Ticket* &reservedTicket = findTicket(roll, seat);
    if(reservedTicket->getStatus() != reserved){
        throw "Not reserved";
    }
    Ticket* availableTicket =  new Ticket(reservedTicket->getRoll(), reservedTicket->getSeat());
    delete reservedTicket;
    reservedTicket = availableTicket; 
}

/**
 * @brief Changes a ticket to BoughtTicket.
 * 
 * @param roll 
 * @param seat 
 */
void Performance::BuyTicket(int roll, int seat){
    Ticket* &ticket = findTicket(roll, seat);
    
    if(ticket->getStatus() == bought){
        throw "Already bought";
    }

    if(ticket->getStatus() == reserved){
    // Not the best way to get the imput but 
    // cant come up with better one.
    std::cout << "Enter password for " << this->title.getChar() << " on" << ctime(&(this->date)) << " seat " << seat << " roll " << roll << std::endl;
    char pass[50];
    std::cin.getline(pass, 49);
    if(strcmp(pass, ((ReservedTicket*)ticket)->getPassword().getChar())){
        return;
    }
    }

    BoughtTicket* boughtTicket = new BoughtTicket(*ticket);
    delete ticket;
    ticket = boughtTicket;
    boughtTicket = nullptr;
}

/**
 * @brief Replace a Ticket.
 * 
 * @param newTicket 
 */
void Performance::UpdateTicket(Ticket* newTicket){
    Ticket*& tmp = findTicket(newTicket->getRoll(), newTicket->getSeat());
    delete tmp;
    tmp = newTicket;
}

/**
 * @brief Replaces all tickets
 * 
 * @param tickets 
 */
void Performance::UpdateTickets(Vector<Ticket*> tickets){
    deleteTickets();
    this->tickets = tickets;
}