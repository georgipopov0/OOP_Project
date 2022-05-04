#pragma once

#include "myString.h"
#include "myVector.h"
#include "Performence.h"

class Hall
{
private:
    int hallId;
    Vector<Performence> performences;
    int rolls;
    //seats per row
    int seats;
public:
    Hall():hallId(0),performences(Vector<Performence>()),rolls(0),seats(0);
    Hall(int, Vector<Performence>, int, int);

    int getHallId();
    const Vector<Performence>* getPerformences();
    int getRolls();
    int getSeats();

    void addPerformence(Performence performence);
};
