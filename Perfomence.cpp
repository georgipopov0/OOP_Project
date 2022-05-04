#include "Performence.h"

Performence::Performence(std::time_t date, myString title)
            :date(date), title(title){}

myString Performence::getTitle(){
    return title;
}

std::time_t Performence::getDate(){
    return date;
}