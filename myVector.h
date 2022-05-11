#pragma once
#include <iostream>
#include "Ticket.h"

template <typename T>
class Vector{
    T* elements;
    int capacity;
    int elemCount;

    public:
    Vector():elements(new T[1]),capacity(1),elemCount(0){}
    Vector(Vector& vecotr);
    Vector(Vector&& vector);
    Vector& operator=(const Vector &);
    ///Vector(T *array)

    void push(T element);
    void push(T element, int index);
    T pop();
    T& get(int index) const;
    
    int size()const;
    int getCapacity() const;

    friend std::ostream& operator<<(std::ostream&, const Vector<Ticket*>);
    
    ~Vector();
    

};

#include "myVector.hxx"