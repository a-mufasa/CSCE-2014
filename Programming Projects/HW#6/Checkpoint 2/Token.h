#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
using namespace std;

//declare the enum we will use
enum Token_type {ID, INT, OP, EQ, OpenBrace, CloseBrace, INVALID};

class Token
{
public:
    // Constructors
    Token();
    Token(string s);
   
    // Methods
    void set(string s);
    int value() const;
    void display() const;
    
    //Getters
    Token_type get_type() const;
    string get_token() const;
    int get_priority() const;
    
    //members
    int save;
    
private:
    // members
    Token_type type;
    string token;
    int priority;
};

#endif