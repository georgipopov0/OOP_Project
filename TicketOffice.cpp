#include "TicketOffice.h"
#include <cstring>
#include <stdlib.h>



TicketOffice::TicketOffice(const char * filename){
        std::ifstream in;
        in.open("savefile.txt");
        if (in.is_open())
        {
            in >> *this;
        }else{
            Hall hall1(1, Vector<Performence>(), 5, 5);
            Hall hall2(2, Vector<Performence>(), 4, 4);
            this->addHall(hall1);
            this->addHall(hall2);
        }
        in.close();        
    }

Performence& TicketOffice::findPerformence(myString title, std::time_t date) const{
for (int i = 0; i < halls.size(); i++)
    {
        Performence *performence = halls.get(i).findPerformence(title, date);
        if (performence)
        {
            return *performence;
        }
    }
    throw "Performence not found";
}

Hall& TicketOffice::findHall(int hallId) const{
    for (int i = 0; i < halls.size(); i++)
    {
        Hall& hall = halls.get(i);
        if(hall.getHallId() == hallId){
            return hall;
        }
    }
    throw "Hall not found";
}

void TicketOffice::save(const char* filename){
    std::ofstream of;
    of.open(filename);
    of << *this;
    of.close();
}


void TicketOffice::addHall(Hall hall){
    this->halls.push(hall);
    save("savefile.txt");
}


void TicketOffice::addPerformence(const char* title, time_t date, int hallId){
    Hall& hall = findHall(hallId);
    hall.addPerformence(Performence(date, myString(title)));
    save("savefile.txt");
}

const Vector<Hall>& TicketOffice::getHalls()const{
    return halls;
}

void TicketOffice::PrintTicketsWithStatusToConsole(const char* title, time_t date, TicketStatus status)const{
    // Eqivalent to ALL
    std::ofstream of;
    if(date == 0){
        int halls_size = halls.size();
        for (int i = 0; i < halls_size; i++)
        {
            try{
            Vector<Performence*> performences = halls.get(i).findPerformence(title);
            int perf_size = performences.size();
            for (int i = 0; i < perf_size; i++)
            {
                time_t time = performences.get(i)->getDate();
                //Print to console
                std::cout << "-----------------------------------" << std::endl
                        << performences.get(i)->getTitle().getChar() << " " << ctime(&time) << std::endl
                        << ": "  << performences.get(i)->getTicktesWithStatus(status);
            
            }
            }catch(char const*){
                std::cout << "wtd";
            }
        }
    }
    else if(!strcmp(title, "ALL"))
    {
        int halls_size = halls.size();
        for (int i = 0; i < halls_size; i++)
        {
            try{
            Vector<Performence*> performences = halls.get(i).findPerformence(date);
            int perf_size = performences.size();
            for (int i = 0; i < perf_size; i++)
            {
                //to console
                std::cout << "-----------------------------------" << std::endl
                        << performences.get(i)->getTitle().getChar() << std::endl
                        << ": "  << performences.get(i)->getTicktesWithStatus(status)<<std::endl;
            
            }
            }catch(char const*){
                //change that later
                std::cout << "wtf";
            }
        }
    }
    else{
        Performence& performence = findPerformence(title, date);
        Vector<Ticket*> tickets = performence.getTicktesWithStatus(status);
        
        // to console
        std::cout << tickets;

        // to file
        myString filename = myString("report-").concat(performence.getTitle()).concat("-").concat(ctime(&date));
        
    }
}

void TicketOffice::PrintTicketsWithStatusToFile(const char* title, time_t date, TicketStatus status)const{
    // Eqivalent to ALL
    std::ofstream of;
    if(date == 0){
        int halls_size = halls.size();
        for (int i = 0; i < halls_size; i++)
        {
            try{
            Vector<Performence*> performences = halls.get(i).findPerformence(title);
            int perf_size = performences.size();
            for (int i = 0; i < perf_size; i++)
            {
                time_t time = performences.get(i)->getDate();
                myString filename = myString("report-").concat(performences.get(i)->getTitle()).concat("-").concat(ctime(&date));
                filename.pop_back();
                filename.concat(".txt");
                filename.replaceChar(' ', '_');
                filename.replaceChar(':', ';');
                
                of.open(filename.getChar());
                of << performences.get(i)->getTicktesWithStatus(status);
                of.close();

            }
            }catch(char const*){
                std::cout << "wtd";
            }
        }
    }
    else if(!strcmp(title, "ALL"))
    {
        int halls_size = halls.size();
        for (int i = 0; i < halls_size; i++)
        {
            try{
            Vector<Performence*> performences = halls.get(i).findPerformence(date);
            int perf_size = performences.size();
            for (int i = 0; i < perf_size; i++)
            {
                // to file
                myString filename = myString("report-").concat(performences.get(i)->getTitle()).concat("-").concat(ctime(&date));
                filename.pop_back();
                filename.concat(".txt");
                filename.replaceChar(' ', '_');
                filename.replaceChar(':', ';');

                of.open(filename.getChar());
                of << performences.get(i)->getTicktesWithStatus(status);
                of.close();
            }
            }catch(char const*){
                //change that later
                std::cout << "wtf";
            }
        }
    }
    else{
        Performence& performence = findPerformence(title, date);
        Vector<Ticket*> tickets = performence.getTicktesWithStatus(status);
        // to file
        myString filename = myString("report-").concat(performence.getTitle()).concat("-").concat(ctime(&date));
        filename.pop_back();
        filename.concat(".txt");
        filename.replaceChar(' ', '_');
        filename.replaceChar(':', ';');
        of.open(filename.getChar(), std::ofstream::out);
        of << tickets;
        of.close();
    }
}

void TicketOffice::PrintBouthTicketsForHall(int hallId)const{
    // Equal to ALL
    if(hallId = -1){
        int halls_size = halls.size();
        for (int i = 0; i < halls_size; i++)
        {
            Hall& hall = halls.get(i);
            const Vector<Performence>& perf = hall.getPerformences();
            int perf_size = perf.size();
            std::cout << "----------------------------" << std::endl 
                << "Hall number " << hall.getHallId() << std::endl;
            for (int i = 0; i < perf_size; i++)
            {
                time_t time = perf.get(i).getDate();
                std::cout << perf.get(i).getTitle().getChar() << " " << ctime(&time)
                    << " | " << "Sold: " << perf.get(i).getTicktesWithStatus(bought).size() << std::endl;
            }
        }
    }
    else{
        Hall hall = this->findHall(hallId);
        const Vector<Performence>& perf = hall.getPerformences();
        int perf_size = perf.size();
        std::cout << "----------------------------" << std::endl 
            << "Hall number " << hall.getHallId() << std::endl;
        for (int i = 0; i < perf_size; i++)
        {
            time_t time = perf.get(i).getDate();
            std::cout << perf.get(i).getTitle().getChar() << " " << ctime(&time)
                << " | " << "Sold: " << perf.get(i).getTicktesWithStatus(bought).size();
        }
    }
}

// Pretty shure some lambda
// magic can be used here ...
void TicketOffice::ReservTicket(const char* title, time_t date, int roll, int seat, myString pass, myString description = myString()){
    this->findPerformence(title,date).ReserveTicket(roll, seat, pass, description);
    save("savefile.txt");
}

void TicketOffice::CancelReservation(const char* title, time_t date, int roll, int seat){
    this->findPerformence(title, date).CancelReservation(roll, seat);
    save("savefile.txt");
}

void TicketOffice::BuyTicket(const char* title, time_t date, int roll, int seat){
    this->findPerformence(title, date).BuyTicket(roll, seat);
    save("savefile.txt");
}

// The hardcode is real
// (had to put it here or the linker gets angry)
std::ostream& operator<<(std::ostream& os, const Vector<Ticket*>& vec){
    int size = vec.size();
    for (int i = 0; i < size; i++)
    {
        os << "(" << vec.get(i)->getRoll() << "," << vec.get(i)->getSeat() << ")" <<std::endl;
    }
    return os;
}

std::ofstream & operator <<(std::ofstream & output, TicketOffice const& ticketOffice){
    int hall_count = ticketOffice.halls.size();
    for (int i = 0; i < hall_count; i++)
    {
        Hall& hall = ticketOffice.halls.get(i);
        output<<hall.getHallId()<<','<<hall.getRolls()<<','<<hall.getSeats();
        int performences_size = hall.getPerformences().size();
        for (int j = 0; j < performences_size; j++)
        {
            Performence& performence = hall.getPerformences().get(j);
            output <<'('<<performence.getTitle().getChar()<<','<<performence.getDate();
            int tickets_size = performence.getTickets().size();
            for (int k = 0; k < tickets_size; k++)
            {
                Ticket* ticket = performence.getTickets().get(k);
                output<<'(';
                if(ticket->getStatus() == reserved){
                    output  << ticket->getStatus() << "," 
                            << ticket->getRoll() << ","
                            << ticket->getSeat() << ","
                            << ((ReservedTicket*)(ticket))->getPassword().getChar() << ","
                            << ((ReservedTicket*)(ticket))->getDescription().getChar();
                }else{
                    output  << ticket->getStatus() << "," 
                            << ticket->getRoll() << ","
                            << ticket->getSeat();
                }
                output<<')';
            }
            output << ')';
            
        }
    output<<std::endl;
    }
    return output;  
}

std::ifstream& operator >>(std::ifstream& is, TicketOffice& office){
    office = TicketOffice();
    Vector<Hall> halls;
    while(is){
        char hallid[8];
        is.getline(hallid, 8, ',');
        if(hallid[0] == '\0'){
            break;
        }
        char rolls[8];
        is.getline(rolls, 8, ',');
        char seats[8];
        is.getline(seats, 8, '(');
        Hall hall(std::atoi(hallid), Vector<Performence>() ,std::atoi(rolls), std::atoi(seats));
        if(is){
            break;
        }
        while(is){
            if(is.peek()=='\n'){
                is.get();
                break;
            }
            if(is.peek()=='('){
                is.get();
            }
            char title[256];
            is.getline(title, 256, ',');
            char date[256];
            is.getline(date, 256, '(');
            Performence tmpPerformence(std::atoi(date), title);
            hall.addPerformence(tmpPerformence);
            Performence* performence = hall.findPerformence(title, tmpPerformence.getDate());
            Vector<Ticket*> tmpTickets;
            while (true)
            {
                if(is.peek()=='(' || is.peek()=='\n'){
                    break;
                }
                char status;
                status = is.get();
                is.get();
                char roll[8];
                is.getline(roll,8,',');
                char seat[8];
                if(status=='1'){
                    is.getline(seat,8,')');
                    tmpTickets.push(new Ticket(std::atoi(roll), std::atoi(seat)));
                }
                else if (status=='2')
                {
                    is.getline(seat,8,')');
                    tmpTickets.push((Ticket*)(new BoughtTicket(Ticket(std::atoi(roll), std::atoi(seat)))));
                }
                else if(status=='3'){
                    is.getline(seat,8,',');
                    char pass[64];
                    is.getline(pass,64,',');
                    char desc[256];
                    is.getline(desc,256,')');
                    tmpTickets.push((Ticket*)(new ReservedTicket(Ticket(std::atoi(roll),std::atoi(seat)),pass,desc)));
                }
                is.get();
            }
        }
        halls.push(hall);
    }
    for (int i = 0; i < halls.size(); i++)
    {
        office.addHall(halls.get(i));
    }
    return is;
    
}
