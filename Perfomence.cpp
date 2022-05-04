#include "Performence.h"

Performence::Performence(std::time_t date, myString title)
            :date(date), title(title){}

//not sure that this improves anything 
//but im doing it anyway
Performence::Performence(Performence&& performence){
    this->date=performence.date;
    this->title=performence.title;
    performence.title= myString();
    date = std::time_t();
}

Performence::Performence(const Performence &performence){
    this->date = performence.date;
    this->title = performence.title;
}

Performence& Performence::operator=(const Performence& performence){
    this->date = performence.date;
    this->title = performence.title;
    return *this;
}

myString Performence::getTitle(){
    return title;
}

std::time_t Performence::getDate(){
    return date;
}