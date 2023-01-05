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

    postfix;
    valid = false;
    type = ILLEGAL;
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
    
    //Below is ommitted from this lab
    cout << "postfix = " << endl;
    cout << "valid = " << valid << endl;
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

//getter methods
string Expression::get_original() const
{
    return original;
}

vector<Token> Expression::get_tokenized() const
{
    return tokenized;
}