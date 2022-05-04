#include "Hall.h"

Hall::Hall(int hallId, Vector<Performence> performences, int rolls, int seats)
    :hallId(hallId), performences(performences), rolls(rolls), seats(seats){}

int Hall::getHallId(){
    return hallId;
}

const Vector<Performence>* Hall::getPerformences(){
    return &performences;
}