#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <vector>
#include "Token.h"
using namespace std;

//declare the enum we will use
enum Exp_type {ASSIGNMENT, ARITHMETIC, ILLEGAL};

class Expression
{
public:
    // Constructors
    Expression();
    Expression(const string& s);
   
    // Methods
    void set(const string& s);
    void display() const;
    
    //Getters
    string get_original() const;
    vector<Token> get_tokenized() const;
    
private:
    // members
    string original;
    vector<Token> tokenized;
    vector<Token> postfix;
    bool valid;
    Exp_type type;
};

#endif