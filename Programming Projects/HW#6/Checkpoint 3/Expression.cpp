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
    
    if (type != ILLEGAL){
        valid = true;
    }
    else{
        valid = false;
    }
    
    if (type == ARITHMETIC){
        InfixToPostfix(); //set postfix
        InfixToPrefix(); //set prefix
        FullyParenthesize(); //set fully parenthesize
    }
    else{
        postfix.clear();
        prefix.clear();
        fp = "";
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
void Expression::InfixToPrefix()
{
    prefix.clear();
    stack<string> ops;
    for (Token T : postfix) {
        if (T.value() > -2){
            ops.push(T.get_token());
        }
        else {
            string s2 = ops.top();
            ops.pop();
            string s1 = ops.top();
            ops.pop();
            ops.push(T.get_token() + " " + s1 + " " + s2);
        }
    }
    while (ops.size() > 0) {
        prefix.push_back(ops.top());
        ops.pop();
    }
}
void Expression::FullyParenthesize()
{
    fp = "";
    stack<string> ops;
    for (Token T : postfix) {
        if (T.value() > -2){
            ops.push(T.get_token());
        }
        else{
            string s2 = ops.top();
            ops.pop();
            string s1 = ops.top();
            ops.pop();
            ops.push("(" + s1 + T.get_token() + s2 + ")");
        }
    }
    fp = ops.top();
}
void Expression::evaluate(vector<Token> post) const { //use postfix to calculate result
    int i = 0;
    vector<Token> p = post; //temp vector b/c const cannot modify the input (which is postfix)
    
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
    if (tokenized.size() == 0 || tokenized.size() == 2) {
        return ILLEGAL;
    } 
    else if (tokenized.size() == 3 && (tokenized[0].get_type() == ID && tokenized[1].get_type() == EQ && tokenized[2].get_type() == INT)) {
        return ASSIGNMENT;
    }
    int op = 0;
    int cp = 0;
    for (int i = 0; i < tokenized.size(); i++) {
        if (tokenized[i].get_type() == EQ || tokenized[i].get_type() == INVALID || cp > op) {
            return ILLEGAL;
        } 
        else if ((i < tokenized.size()-1) && ((tokenized[i].get_type() == OpenBrace || tokenized[i].get_type() == OP) && 
                    (tokenized[i+1].get_type() == OP || tokenized[i+1].get_type() == CloseBrace))) {
            return ILLEGAL;
        } 
        else if ((i < tokenized.size()-1) && ((tokenized[i].value() > -2 && tokenized[i+1].get_type() == OpenBrace) || 
                    (tokenized[i].get_type() == CloseBrace && tokenized[i+1].value() > -2))) {
            return ILLEGAL;
        } 
        else if (tokenized[i].get_type() == OpenBrace) {
            op++;
        } 
        else if (tokenized[i].get_type() == CloseBrace) {
            cp++;
        }
    }
    if (op != cp || tokenized[0].get_type() == OP || tokenized[tokenized.size()-1].get_type() == OP) {
        return ILLEGAL;
    }
    return ARITHMETIC;
}
vector<Token> Expression::get_postfix() const
{
    return postfix;
}
vector<Token> Expression::get_prefix() const
{
    return prefix;
}
string Expression::get_fp() const {
    return fp;
}
