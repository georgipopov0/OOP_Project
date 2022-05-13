#include <iostream>
#include <cstring>
#include "myString.h"
#include "myVector.h"
using namespace std;
 

void myString::Copy(const myString &s){
    int n = strlen(s.str) + 1;
    str = new char[n];
    for(int i = 0; i < n ; i++){
        this->str[i] = s.str[i];
    }
}
void myString::Erase(){
    delete[] str;
}
 
 
myString::myString() :str(nullptr){
    str = new char[1];
    str[0] = '\0';
}
myString::myString(const char* str){
    int n = strlen(str) + 1;
    this->str = new char[n];
    for(int i = 0; i < n; i++){
        this->str[i] = str[i];
    }
    
}
 
myString::myString(const myString &s){
    Copy(s);
}
 
myString::myString(myString&& string){
    this->str = string.str;
    string.str = nullptr;
}

myString& myString::operator =(const myString &s){
    if(this != &s){
        Erase();
        Copy(s);
    }
return *this;
}

myString::~myString(){
    Erase();
}
 
void myString::print(){
    cout << str << endl;
}
 
int myString::lenght(){
    return strlen(str);
}
 
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

myString myString::concat(const char *str){
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

void myString::replaceChar(char oldChar, char newChar){
    int size = this->lenght() +1;
    for (int i = 0; i < size; i++)
    {
        if(this->str[i] == oldChar){
            this->str[i] = newChar;
        }
    }
    
}

myString myString::concat(const myString &s){
    concat(s.str);
    return *this;
}

const char* myString::getChar()const{
    return this->str;
} 

