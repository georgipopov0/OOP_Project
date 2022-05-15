#pragma once

/**
 * @brief Takes care of the dinamic memory for char arrays.
 * 
 */
class myString{
private:
    char *str;
    void Copy(const myString &);
    void Erase();
 
public:
 
myString();

myString(const char*);
 
myString(const myString &);

myString(myString&&);
 
myString& operator =(const myString &);

~myString();
 
void print();
 
int lenght();
 
void pop_back();

void removeChar(char);

void replaceChar(char, char);
 
myString& concat(const char *);
 
myString& concat(const myString &);

const char* getChar()const;
};

