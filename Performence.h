#pragma once

#include <ctime>
#include "myString.h"
#include "myVector.h"

class Performence
{
private:
    std::time_t date;
    myString title;

public:
    Performence():title(myString()), date(std::time_t()){}
    Performence(std::time_t date, myString title);

    myString getTitle();
    std::time_t getDate();
};

Performence::Performence(/* args */)
{
}

Performence::~Performence()
{
}
