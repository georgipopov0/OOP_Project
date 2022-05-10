#include <iostream>
#include "Performence.h"
#include <cstring>

void Performence::deleteTickets(){
    for (int i = 0; i < this->tickets.size(); i++)
    {
        delete this->tickets.get(i);
    }
}

void Performence::copyTickets(const Performence& performence){
    for (int i = 0; i < performence.tickets.size(); i++)
    {
        this->tickets.push(new Ticket(*performence.tickets.get(i)));
    }
}

Ticket* &Performence::findTicket(int roll, int seat) const{
    int rollSize = 0;
    for (int i = 0;  tickets.get(i)->getRoll() == tickets.get(i+1)->getRoll() ; i++)
    {
        rollSize++;
    }
    return tickets.get(rollSize*roll + seat);
}

Performence::Performence(std::time_t date, myString title)
:date(date), title(title), tickets(Vector<Ticket*>()){}

//not sure that this improves anything 
//but im doing it anyway
Performence::Performence(Performence&& performence){
    this->date=performence.date;
    this->title=performence.title;
    this->tickets=performence.tickets;
    performence.tickets.~Vector();
}

Performence::Performence(const Performence &performence){
    this->date = performence.date;
    this->title = performence.title;
    this->copyTickets(performence);
}

Performence::~Performence(){
    deleteTickets();
}

Performence& Performence::operator=(const Performence& performence){
    deleteTickets();
    copyTickets(performence);
    this->date = performence.date;
    this->title = performence.title;
    
    return *this;
}

myString Performence::getTitle()const{
    return title;
}

std::time_t Performence::getDate()const{
    return date;
}

const Vector<Ticket*>& Performence::getTickets() const{
    return tickets;
}

void Performence::generateTickets(int rolls, int seats){
    this->tickets = Vector<Ticket*>();
    for (int i = 0; i < rolls; i++)
    {
        for (int j = i ; j < seats; j++)
        { 
            tickets.push(new Ticket(i, j));
        }
    }
    
}

Vector<Ticket*> Performence::getTicktesWithStatus(TicketStatus status)const{
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

void Performence::ReserveTicket(int roll, int seat, myString password, myString descriprion){
    Ticket* &ticket = findTicket(roll, seat);
    if(ticket->getStatus() != available){
        throw "Not available";
    }
    ReservedTicket* reserved =  new ReservedTicket(*ticket, descriprion, password);
    delete ticket;
    ticket = reserved;
    reserved = nullptr;
}

void Performence::CancelReservation(int roll, int seat){
    Ticket* &reservedTicket = findTicket(roll, seat);
    if(reservedTicket->getStatus() != reserved){
        throw "Not reserved";
    }
    Ticket* availableTicket =  new Ticket(reservedTicket->getRoll(), reservedTicket->getSeat());
    delete reservedTicket;
    reservedTicket = availableTicket; 
}

void Performence::BuyTicket(int roll, int seat){
    Ticket* &ticket = findTicket(roll, seat);
    
    if(ticket->getStatus() == bought){
        throw "Already bought";
    }

    if(ticket->getStatus() == reserved){
        // Not the best way to get the imput but 
        // cant come up with better one.
        std::cout << "Enter password for " << this->title.getChar() << " seat " << seat << " roll " << roll << std::endl;
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