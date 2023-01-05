#include "Token.h"

//defualt constructor
Token::Token()
{
    type = INVALID;
    token = "";
    priority = -1;
}

//string-input argument constructor
Token::Token(string s)
{
    set(s); //call to set method
}

//methods
void Token::set(string s)
{
    if ((s[0] >= 'A' && s[0] <= 'Z') || (s[0] >= 'a' && s[0] <= 'z')){ //checks alphabet range in ASCII
        type = ID;
        
        for (int i = 1; i < s.length(); i++){ //if token has non-letters or non-integers, type is INVALID
            if (!((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[0] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))){
                type = INVALID;
            }
        }
    }
    else if (s[0] >= '1' && s[0] <= '9'){ //checks integers
        type = INT;
        
        for (int i = 1; i < s.length(); i++){ //if token has non-integers, type is INVALID
            if (!(s[i] >= '0' && s[i] <= '9')){
                type = INVALID;
            }
        }
    }
    else if ((s[0] == '0') && s.length()==1){
        type = INT;
    }
    else if (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/'){ //checks operators range in ASCII
        type = OP;
    }
    else if (s[0] == '='){
        type = EQ;
    }
    else if (s[0] == '('){
        type = OpenBrace;
    }
    else if (s[0] == ')'){
        type = CloseBrace;
    }
    else{ //if none of the other elements of enum, then invalid
        type = INVALID; 
    }
    
    if (type == OpenBrace){
        priority = 0;
    }
    else if (s[0]    == '+' || s[0] == '-'){
        priority = 1;
    }
    else if (s[0] == '*' || s[0] == '/'){
        priority = 2;
    }
    else{
        priority = -1;
    }
    
    token = s;
    
    save = value();
}
int Token::value() const
{
    if (type == INT){
        return stoi(token); //converts token string to integer
    }
    else if (type == ID){
        return -1;
    }
    else{
        return -2;
    }
}
void Token::display() const
{
    cout << "type = ";
    switch (type){ //reformats the type from 0-6 to enum elements ID-INVALID
        case ID:
            cout << "ID" << endl;
            break;
        case INT:
            cout << "INT" << endl;
            break;
        case OP:
            cout << "OP" << endl;
            break;
        case EQ:
            cout << "EQ" << endl;
            break;
        case OpenBrace:
            cout << "OpenBrace" << endl;
            break;
        case CloseBrace:
            cout << "CloseBrace" << endl;
            break;
        case INVALID:
            cout << "INVALID" << endl;
            break;
    }
    cout << "token = " << token << " (value is " << value() << ")" << endl;
    cout << "priority = " << priority << endl;
}

//getter methods
Token_type Token::get_type() const
{
    return type;
}
string Token::get_token() const
{
    return token;
}
int Token::get_priority() const
{
    return priority;
}