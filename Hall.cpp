#include "Hall.h"
#include <cstring>


/**
 * @brief Construct a new Hall:: Hall object
 * 
 * @param hallId Id.
 * @param performences Linst of performences.
 * @param rolls Number of rolls in the hall.
 * @param seats Number of seats per roll.
 */
Hall::Hall(int hallId, Vector<Performance> performences, int rolls, int seats)
    :hallId(hallId), performences(performences), rolls(rolls), seats(seats){}


/**
 * @brief Copu constructor for hall.
 * 
 * @param hall 
 */
Hall::Hall(const Hall& hall){
    this->hallId = hall.hallId;
    this->performences = hall.performences;
    this->rolls = hall.rolls;
    this->seats = hall.seats;
}

/**
 * @brief 
 * 
 * @return int Hall id.
 */
int Hall::getHallId()const{
    return hallId;
}

/**
 * @brief 
 * 
 * @return Vector<Performence>&;
 */
const Vector<Performance>& Hall::getPerformences()const{
    return performences;
}

/**
 * @brief 
 * 
 * @return int 
 */
int Hall::getRolls()const{
    return rolls;
}

/**
 * @brief 
 * 
 * @return int 
 */
int Hall::getSeats()const{
    return seats;
}

/**
 * @brief adds performence to the Hall
 * 
 * @param performence 
 */
void Hall::addPerformence(Performance performence){
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

/**
 * @brief Finds performence by title and date.
 * 
 * @param title Title of the performence.
 * @param date  Date of the performence.
 * @return Pointer to the performence or nullptr if the performence doesnt exist.
 */
Performance* Hall::findPerformence(myString title, std::time_t date)const{
    for (int i = 0; i < performences.size(); i++){
        Performance& performence = performences.get(i);
        if(!strcmp(performence.getTitle().getChar(), title.getChar()) 
            && performence.getDate() == date){
                return &performence;
        }
    }
    return nullptr;
}

/**
 * @brief Finds all performences with the given title
 * 
 * @param title Title of the performences.
 * @return Vector<Performence*> Vector with refferences to the found performances.
 */
Vector<Performance*> Hall::findPerformence(myString title)const{
    Vector<Performance*> tmpPerformences;
    for (int i = 0; i < performences.size(); i++){
        Performance& performence = performences.get(i);
        if(!strcmp(performence.getTitle().getChar(), title.getChar())){
                tmpPerformences.push(&performence);
        }
    }
    return tmpPerformences;
}


/**
 * @brief Finds all performances with the given date.
 * 
 * @param date Date of the performences.
 * @return Vector<Performence*> Vector with refferences to the found performances.
 */
Vector<Performance*> Hall::findPerformence(std::time_t date)const{
    Vector<Performance*> tmpPerformences;
    for (int i = 0; i < performences.size(); i++){
        Performance& performence = performences.get(i);
        if(performence.getDate() == date){
                tmpPerformences.push(&performence);
        }
    }
    return tmpPerformences;
}
