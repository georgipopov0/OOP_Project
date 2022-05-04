#include <iostream>
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
    

    int a=1,b=2,c=3;
    a=b=c;
    std::cout<<a<<b<<c;
    return 0;
}
