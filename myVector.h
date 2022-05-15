#pragma once
#include <iostream>
#include "Ticket.h"


/**
 * @brief Dynamic array.
 * 
 * @tparam T
 */
template <typename T>
class Vector{
    T* elements; /** Pointer to the dynamic array. */
    int capacity; /** Size of the array. */
    int elemCount; /** Amount of elements in the array. */

    public:
    /**
     * @brief Construct a new Vector object
     * 
     */
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

    friend std::ostream& operator<<(std::ostream&, const Vector<Ticket*>&);
    
    ~Vector();
    

};

#include "myVector.hxx"