#include "ReservedTicket.h"

/**
 * @brief Construct a new Reserved Ticket:: Reserved Ticket object
 * 
 * @param ticket 
 * @param arg_description 
 * @param arg_password 
 */
ReservedTicket::ReservedTicket(Ticket ticket, myString arg_description, myString arg_password)
    :Ticket(ticket), descriptin(arg_description), password(arg_password){}


/**
 * @brief 
 * 
 * @return TicketStatus 
 */
TicketStatus ReservedTicket::getStatus() const{
    return reserved;
}

/**
 * @brief 
 * 
 * @return myString 
 */
myString ReservedTicket::getPassword() const{
    return password;
}

/**
 * @brief 
 * 
 * @return myString 
 */
myString ReservedTicket::getDescription() const{
    return descriptin;
}