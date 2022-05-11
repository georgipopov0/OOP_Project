#include "Hall.h"
#include <cstring>

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
    this->performences.get(this->performences.size()-1).generateTickets(rolls, seats);

}

Performence* Hall::findPerformence(myString title, std::time_t date)const{
    for (int i = 0; i < performences.size(); i++){
        Performence& performence = performences.get(i);
        if(strcmp(performence.getTitle().getChar(), title.getChar()) 
            && performence.getDate() == date){
                return &performence;
        }
    }
    return nullptr;
}

Vector<Performence> Hall::findPerformence(myString title)const{
    Vector<Performence> tmpPerformences;
    for (int i = 0; i < performences.size(); i++){
        Performence& performence = performences.get(i);
        if(strcmp(performence.getTitle().getChar(), title.getChar())){
                tmpPerformences.push(performence);
        }
    }
    return tmpPerformences;
}

Vector<Performence> Hall::findPerformence(std::time_t date)const{
    Vector<Performence> tmpPerformences;
    for (int i = 0; i < performences.size(); i++){
        Performence& performence = performences.get(i);
        if(performence.getDate() == date){
                tmpPerformences.push(performence);
        }
    }
    return tmpPerformences;
}
