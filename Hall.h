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
    Hall():hallId(0),performences(Vector<Performence>()),rolls(0),seats(0){}
    Hall(int, Vector<Performence>, int, int);
    Hall(const Hall&);

    int getHallId()const;
    const Vector<Performence>& getPerformences()const;
    int getRolls()const;
    int getSeats()const;

    void addPerformence(Performence performence);
    Performence* findPerformence(myString, std::time_t)const ;
    Vector<Performence*> findPerformence(myString)const;
    Vector<Performence*> findPerformence(std::time_t date)const;
};
