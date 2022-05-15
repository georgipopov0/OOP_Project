/**
 * @brief Adds a new element to the back of the array.
 * 
 * @tparam T 
 * @param element 
 */
template <class T>
void Vector<T>::push(T element){
    if(elemCount == capacity){
        T* tmp = new T[capacity*2];

        for (int i = 0; i < capacity; i++)
        {
            tmp[i] = elements[i];
        }
        delete[] elements;
        elements = tmp;
        capacity *=2;
    }
    elements[elemCount] = element;
    elemCount++; 
}

/**
 * @brief Copy constructor.
 * 
 * @tparam T 
 * @param vector 
 */
template <class T>
Vector<T>::Vector(Vector<T>& vector){
    this->capacity = vector.capacity;
    this->elements = new T[vector.capacity];
    this->elemCount = vector.elemCount;
    for (int i = 0; i < vector.elemCount; i++)
    {
        this->elements[i] = vector.elements[i];
    }
}

/**
 * @brief Move constructor.
 * 
 * @tparam T 
 * @param vector 
 */
template <class T>
Vector<T>::Vector(Vector<T>&& vector){
    capacity = vector.capacity;
    elemCount = vector.elemCount;
    elements = vector.elements;
    vector.elements = nullptr;
    vector.capacity = 0;
    vector.elemCount = 0;
}

/**
 * @brief Assaingment operator
 * 
 * @tparam T 
 * @param vector Vector to copy.
 * @return Vector<T>&  The current vector.
 */
template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& vector){
    delete[] this->elements;
    this->capacity = vector.capacity;
    this->elements = new T[vector.capacity];
    this->elemCount = vector.elemCount;
    for (int i = 0; i < vector.elemCount; i++)
    {
        this->elements[i] = vector.elements[i];
    }
    return *this;
}

/**
 * @brief Adds element to the given positin.
 * 
 * @tparam T 
 * @param element Element to add.
 * @param index Position
 */
template <class T>
void Vector<T>::push(T element, int index){
    if(index>capacity){
        throw "Inex out of range";
    }
    if(index==capacity){
        this->push(element);
    }
    else{
        elements[index] = element;
    }
} 

/**
 * @brief Remove last element
 * 
 * @tparam T 
 * @return T Value of the removed element.
 */
template<typename T>
T Vector<T>::pop(){
    elemCount--;
    return this->elements[elemCount];
}

/**
 * @brief Returns refference to element specified by position.
 * 
 * @tparam T 
 * @param index Position of the element.
 * @return T& The requested element.
 */
template<typename T>
T& Vector<T>::get(int index)const{
    if(index > elemCount || index < 0){
        throw "inex out of range";
    }
    return elements[index];
}

/**
 * @brief 
 * 
 * @tparam T 
 * @return int Number of elements in the vector.
 */
template<typename T>
int Vector<T>::size()const{
    return elemCount;
}

/**
 * @brief 
 * 
 * @tparam T 
 * @return int Current capacity of the vector.
 */
template<typename T>
int Vector<T>::getCapacity()const{
    return capacity;
}

/**
 * @brief Destroy the Vector< T>:: Vector object
 * 
 * @tparam T 
 */
template<typename T>
Vector<T>::~Vector(){
    delete[] elements;
    elemCount=0;
    capacity=0;
}


