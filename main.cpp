#include <iostream>
#include <ctime>
#include "myVector.h"


int main(int argc, char const *argv[])
{
    Vector<int> vector;
    for (int i = 0; i < 20; i++)
    {
        vector.push(i);
    }
    
    for (int j = 0; j < 20; j++)
    {
        std::cout << vector.get(j) << std::endl;
    }
    
    std::tm tm{};
    tm.tm_year = 2020-1900; // 2020
    tm.tm_mon = 2-1; // February
    tm.tm_mday = 15; // 15th
    tm.tm_hour = 10;
    tm.tm_min = 15;
    tm.tm_isdst = 0; // Not daylight saving
    std::time_t t = std::mktime(&tm);

    int a=1,b=2,c=3;
    a=b=c;
    std::cout<<a<<b<<c;
    return 0;
}
