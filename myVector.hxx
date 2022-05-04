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

template <class T>
Vector<T>::Vector(Vector<T>&& vector){
    capacity = vector.capacity;
    elemCount = vector.elemCount;
    elements = vector.elements;
    vector.elements = nullptr;
    vector.capacity = 0;
    vector.elemCount = 0;
}

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

template<typename T>
T Vector<T>::pop(){
    elemCount--;
}

template<typename T>
T Vector<T>::get(int index){
    if(index > elemCount || index < 0){
        throw "inex out of range";
    }
    return elements[index];
}


template<typename T>
int Vector<T>::size(){
    return elemCount;
}

template<typename T>
int Vector<T>::getCapacity(){
    return capacity;
}

template<typename T>
Vector<T>::~Vector(){
    delete[] elements;
    elemCount=0;
    capacity=0;
}

