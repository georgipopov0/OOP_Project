#include <iostream>
#include <cstring>
#include "myString.h"
#include "myVector.h"
using namespace std;
 

/**
 * @brief Copies the content of another string 
 * 
 * @param s String to copy from.
 */
void myString::Copy(const myString &s){
    int n = strlen(s.str) + 1;
    str = new char[n];
    for(int i = 0; i < n ; i++){
        this->str[i] = s.str[i];
    }
}

/**
 * @brief Free the alocated memmory.
 * 
 */
void myString::Erase(){
    delete[] str;
}
 
 /**
  * @brief Construct a new my String::my String object
  * 
  */
myString::myString() :str(nullptr){
    str = new char[1];
    str[0] = '\0';
}

/**
 * @brief Construct a new my String::my String object.
 * 
 * @param std Char arr to copy.
 */
myString::myString(const char* str){
    int n = strlen(str) + 1;
    this->str = new char[n];
    for(int i = 0; i < n; i++){
        this->str[i] = str[i];
    }
    
}

/**
 * @brief Copy constructor
 * 
 * @param s String to coppy.
 */
myString::myString(const myString &s){
    Copy(s);
}

/**
 * @brief Move consructor
 * 
 * @param string 
 */
myString::myString(myString&& string){
    this->str = string.str;
    string.str = nullptr;
}

/**
 * @brief Assaingment operator
 * 
 * @param s String to coppy
 * @return myString& the current object
 */
myString& myString::operator =(const myString &s){
    if(this != &s){
        Erase();
        Copy(s);
    }
return *this;
}

/**
 * @brief Destroy the my String::my String object
 * 
 */
myString::~myString(){
    Erase();
}

/**
 * @brief 
 * 
 * @return int The lenth of the string
 */
int myString::lenght(){
    return strlen(str);
}
 
/**
 * @brief Remove last char
 * 
 */
void myString::pop_back(){
    int n = lenght() - 1;
    char *temp = new char[n];
    for(int i = 0; i < n; i++){
        temp[i] = this->str[i];
    }
    temp[n] = '\0';
    delete[] str;
    this->str = temp;
}

/**
 * @brief Remove all appearances of a given char.
 * 
 * @param ch Char to remove.
 */
void myString::removeChar(char ch){
    Vector<char> tmp;
    int size = lenght() +1;
    for (int i = 0; i < size; i++)
    {
        if(this->str[i] != ch){
            tmp.push(str[i]);
        }
    }
    delete this->str;
    this->str = new char[tmp.size()];
    for (int i = 0; i < tmp.size(); i++)
    {
        str[i] = tmp.get(i);
    }
}

/**
 * @brief Replacese all appearances of a char.
 * 
 * @param oldChar Char to be replaced.
 * @param newChar Char to replace with.
 */
void myString::replaceChar(char oldChar, char newChar){
    int size = this->lenght() +1;
    for (int i = 0; i < size; i++)
    {
        if(this->str[i] == oldChar){
            this->str[i] = newChar;
        }
    }
    
}

/**
 * @brief Append a string.
 * 
 * @param str String to append.
 * @return myString The resulting string.
 */
myString& myString::concat(const char *str){
    int n = strlen(this->str) + strlen(str) + 1;
    char *temp = new char[n];
    int i;
    for(i = 0; i < strlen(this->str); i++){
        temp[i] = this->str[i];
    }
    for(int j = 0; j < strlen(str); j++){
        temp[i++] = str[j];
    }
    temp[n - 1] = '\0';
    delete[] this->str;
    this->str = temp;
    return *this;
}

/**
 * @brief Append a string.
 * 
 * @param s String to append.
 * @return myString The resulting string.
 */
myString& myString::concat(const myString &s){
    concat(s.str);
    return *this;
}

/**
 * @brief Returns the char array corespondint to the string.
 * 
 * @return const char* 
 */
const char* myString::getChar()const{
    return this->str;
} 

