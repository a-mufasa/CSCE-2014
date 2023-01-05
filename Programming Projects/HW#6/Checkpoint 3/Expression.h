#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <vector>
#include <stack>
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
    void evaluate(vector<Token> p) const; // calculate operations with just integers; will change in final version
    void InfixToPostfix();
    void InfixToPrefix();
    void FullyParenthesize();
    
    //Getters
    string get_original() const;
    vector<Token> get_tokenized() const;
    Exp_type get_Etype() const;
    vector<Token> get_postfix() const;
    vector<Token> get_prefix() const;
    string get_fp() const;
    
private:
    // members
    string original;
    vector<Token> tokenized;
    vector<Token> postfix;
    vector<Token> prefix;
    string fp;
    bool valid;
    Exp_type type;
};

#endif