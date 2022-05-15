#pragma once

#include "myString.h"
#include "myVector.h"
#include "Performence.h"

/**
 * @brief Hall for the performances.
 * 
 */
class Hall
{
private:
    int hallId; /// Id
    Vector<Performance> performences; /// Contains all the performances in the hall;
    int rolls; /// Number of rolls
    int seats; /**Seats per row*/
public:
    /**
     * @brief Construct a new Hall object
     * 
     */
    Hall():hallId(0),performences(Vector<Performance>()),rolls(0),seats(0){}
    Hall(int, Vector<Performance>, int, int);
    Hall(const Hall&);

    int getHallId()const;
    const Vector<Performance>& getPerformences()const;
    int getRolls()const;
    int getSeats()const;

    void addPerformence(Performance performence);
    Performance* findPerformence(myString, std::time_t)const ;
    Vector<Performance*> findPerformence(myString)const;
    Vector<Performance*> findPerformence(std::time_t date)const;
};
