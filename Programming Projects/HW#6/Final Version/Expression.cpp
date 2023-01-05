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
    
    type = set_Etype();
    
    if (type != ILLEGAL){
        valid = true;
    }
    else{
        valid = false;
    }
    
    if (type == ARITHMETIC){
        InfixToPostfix(); //set postfix
        InfixToPrefix(); //set prefix
        FullyParenthesize(); //set fp
        
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
    stack<string> s;
    for (Token T : postfix) {
        if (T.value() > -2){
            s.push(T.get_token());
        }
        else {
            string s2 = s.top();
            s.pop();
            string s1 = s.top();
            s.pop();
            s.push(T.get_token() + " " + s1 + " " + s2);
        }
    }
    while (s.size() > 0) {
        prefix.push_back(s.top());
        s.pop();
    }
}
void Expression::FullyParenthesize()
{
    fp = "";
    stack<string> s;
    for (Token T : postfix) {
        if (T.value() > -2){
            s.push(T.get_token());
        }
        else{
            string s2 = s.top();
            s.pop();
            string s1 = s.top();
            s.pop();
            s.push("(" + s1 + T.get_token() + s2 + ")");
        }
    }
    fp = s.top();
}
void Expression::evaluate(vector<Expression> total) const { //use postfix to calculate result
    stack<int> values;
    for (Token T : postfix) {
        if (T.get_type() == INT) {
            values.push(stoi(T.get_token()));
        } 
        else if (T.get_type() == ID) {
            int define = 0;
            for (int i = total.size()-1; i >= 0; i--) {
                if (total[i].get_Etype() == ASSIGNMENT && total[i].get_tokenized()[0].get_token() == T.get_token()) {
                    values.push(total[i].get_tokenized()[2].value());
                    define++;
                    break;
                }
            }
            if (define < 1) {
                cout << "no result, some variable has undefined value" << endl;
                return;
            }
        } 
        else {
            int num2 = values.top();
            values.pop();
            int num1 = values.top();
            values.pop();
            if (T.get_token() == "*") {
                values.push(num1 * num2);
            } 
            else if (T.get_token() == "/") {
                if(num2 == 0){
                    cout << "no result, divide by 0 error!" << endl;
                    return;
                }
                else{
                    values.push(num1 / num2);
                }
            }
            else if (T.get_token() == "+") {
                values.push(num1 + num2);
            } 
            else if (T.get_token() == "-") {
                values.push(num1 - num2);
            } 
        }
    }
    cout << values.top() << endl;
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

Exp_type Expression::set_Etype() const {
    if (tokenized.size() == 0 || tokenized.size() == 2 || tokenized[0].get_type() == OP || tokenized[tokenized.size()-1].get_type() == OP) {
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
    if (op != cp) {
        return ILLEGAL;
    }
    return ARITHMETIC;
}
Exp_type Expression::get_Etype() const{
    return type;
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
