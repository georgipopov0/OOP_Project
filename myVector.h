#pragma once

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
    T get(int index);
    
    int size();
    int getCapacity();

    ~Vector();
    

};

#include "myVector.hxx"