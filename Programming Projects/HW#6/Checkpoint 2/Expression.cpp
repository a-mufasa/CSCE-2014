#include <string.h>
#include "Expression.h"
using namespace std;

//defualt constructor
Expression::Expression()
{
    original = "";
    tokenized; //empty vector
    postfix;
    valid = false;
    type = ILLEGAL;
}

//string-input argument constructor
Expression::Expression(const string& s)
{
    set(s); //call to set method
}

//methods
void Expression::set(const string& s)
{
    tokenized.clear(); //resets the vector for future set() calls
    original = s;
    
    string temp;
    for (int i = 0; i < s.length(); i++){
        if (!((s[i] == '+') || (s[i] == '-') || (s[i] == '*') || //if not special character or space
                (s[i] == '/') || (s[i] == '=') || (s[i] == '(') ||
                (s[i] == ')') || (s[i] == ' ')))
        {
            temp.append(s,i,1);
        }
        else if ((s[i] == '+') || (s[i] == '-') || (s[i] == '*') || //if special character
                (s[i] == '/') || (s[i] == '=') || (s[i] == '(') ||
                (s[i] == ')'))
        {
            if (temp != ""){ //if string is not empty (between two special characters)
                Token tok(temp);
                tokenized.push_back(tok);
                temp.clear();
            }
            temp.append(s,i,1);
            Token tok(temp);
            tokenized.push_back(tok);
            temp.clear();
        }
        else if (s[i] == ' '){ //if space
            if (temp != ""){ //if string is not empty
                Token tok(temp);
                tokenized.push_back(tok);
                temp.clear();
            }
        }
    }
    if (temp != ""){ //if temp string comes out of for loop with values, add to vector
        Token tok(temp);
        tokenized.push_back(tok);
        temp.clear();
    }
    
    type = get_Etype();
    
    valid = true;
    
    if (type == ARITHMETIC){
        InfixToPostfix();
    }
    else{
        postfix.clear();
    }
}
void Expression::display() const
{
    cout << "original = " << original << endl;
    
    cout << "tokenized = ";
    for (int i = 0; i < tokenized.size(); i++){
        cout << tokenized[i].get_token() << ";";
    }
    cout << endl;
    
    cout << "number of tokens = " << tokenized.size() << endl;
    
    cout << "postfix = " ;
    
    for (int i = 0; i < postfix.size(); i++) {
        cout << postfix[i].get_token() << " ";
    }
    cout << endl;
    
    cout << "valid = ";
    switch (valid){ //reformats valid from 0-1 to FALSE/TRUE
        case false:
            cout << "false" << endl;
            break;
        case true:
            cout << "true" << endl;
    }
    cout << "type = ";
    switch (type){ //reformats the type from 0-2 to enum elements ID-INVALID
        case ASSIGNMENT:
            cout << "ASSIGNMENT" << endl;
            break;
        case ARITHMETIC:
            cout << "ARITHMETIC" << endl;
            break;
        case ILLEGAL:
            cout << "ILLEGAL" << endl;
            break;
    }
}
void Expression::InfixToPostfix() 
{
    postfix.clear();
    stack<Token> ops;
    for (Token T : tokenized) {
        if (T.value() > -2) {
            postfix.push_back(T);
        } else if (T.get_type() == OpenBrace) {
            ops.push(T);
        } else if (T.get_type() == CloseBrace) {
            while (ops.top().get_type() != OpenBrace) {
                postfix.push_back(ops.top());
                ops.pop();
            }
            ops.pop();
        } else {
            while (ops.size() > 0 && (ops.top().get_priority() >= T.get_priority())) {
                postfix.push_back(ops.top());
                ops.pop();
            }
            ops.push(T);
        }
    }
    while (ops.size() > 0) {
        postfix.push_back(ops.top());
        ops.pop();
    }
}
void Expression::evaluate(vector<Token> a) const {
    int i = 0;
    vector<Token> p = a; //temp vector b/c const cannot modify
    
    while (p.size() > 2) {
        if (p[i].get_type() == INT && p[i+1].get_type() == INT && p[i+2].get_type() == OP) {
            if (p[i+2].get_token() == "*"){
                p[i].save = p[i].save * p[i+1].save;
            }
            else if (p[i+2].get_token() == "/"){
                p[i].save = p[i].save / p[i+1].save;
            }
            else if (p[i+2].get_token() == "+") {
                p[i].save = p[i].save + p[i+1].save;
            } 
            else {
                p[i].save = p[i].save - p[i+1].save;;
            }
            p.erase(p.begin()+i+1,p.begin()+i+3);
            i=0;
        }
        else{
            i++;  
        }
    }
    cout << p[0].save << endl;
}

//getter methods
string Expression::get_original() const
{
    return original;
}

vector<Token> Expression::get_tokenized() const
{
    return tokenized;
}

Exp_type Expression::get_Etype() const {
    if (tokenized.size() == 3 && (tokenized[0].get_type() == ID && tokenized[1].get_type() == EQ && tokenized[2].get_type() == INT)) {
        return ASSIGNMENT;
    }
    else{
        return ARITHMETIC;
    }
}
vector<Token> Expression::get_postfix() const
{
    return postfix;
}
