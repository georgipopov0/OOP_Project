#include "Performence.h"

void Performence::deleteTickets(){
    for (int i = 0; i < this->tickets.size(); i++)
    {
        delete this->tickets.get(i);
    }
}

void Performence::copyTickets(const Performence& performence){
    for (int i = 0; i < performence.tickets.size(); i++)
    {
        this->tickets.push(new Ticket(*performence.tickets.get(i)),i);
    }
}

Performence::Performence(std::time_t date, myString title)
            :date(date), title(title){}

//not sure that this improves anything 
//but im doing it anyway
Performence::Performence(Performence&& performence){
    this->date=performence.date;
    this->title=performence.title;
    performence.title= performence.title;
    date = performence.date;
    this->tickets=performence.tickets;
    performence.tickets.~Vector();
}

Performence::Performence(const Performence &performence){
    this->date = performence.date;
    this->title = performence.title;
    this->copyTickets(performence);
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
    for (int i = 0; i < rolls; i++)
    {
        for (int j = i ; j < seats; j++)
        { 
            tickets.push(new Ticket(i, j));
        }
    }
    
}