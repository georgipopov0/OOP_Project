#include "Hall.h"

Hall::Hall(int hallId, Vector<Performence> performences, int rolls, int seats)
    :hallId(hallId), performences(performences), rolls(rolls), seats(seats){}

Hall::Hall(const Hall& hall){
    this->hallId = hall.hallId;
    this->performences = hall.performences;
    this->rolls = hall.rolls;
    this->seats = hall.seats;
}

int Hall::getHallId()const{
    return hallId;
}

const Vector<Performence>& Hall::getPerformences()const{
    return performences;
}

int Hall::getRolls()const{
    return rolls;
}

int Hall::getSeats()const{
    return seats;
}

void Hall::addPerformence(Performence performence){
    int performenceCount = performences.size();

    for (int i = 0; i < performenceCount; i++)
    {
        if(performence.getDate() == performences.get(i).getDate()){
            throw "Hall is buisy";
        }
    }
    this->performences.push(performence);
}