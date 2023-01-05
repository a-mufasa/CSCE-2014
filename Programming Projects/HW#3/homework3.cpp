/***************************************************************************************************

Ahmed Moustafa 
CSCE2014 Programming Foundations II
Homework Three

Synopsis: 
homework3.cpp contains the tests for the Token and Expression classes. The Token class 
is defined in Token.h and implemented in Token.cpp and the Expression Class is defined 
in Expression.h and implemented in Expression.cpp (includes the Token class through Token.h). 
These classes are both included in the homework3.cpp through Expression.h).

The Token class contains an enum, a default and 1-arg constructor, public methods, and private members.
The Token class's set method sets a token to the input string, priority to -1, and the type 
to the corresponding type from the enum (depends on the input string whether it is an ID, INT, INVALID, etc.).
The value method returns the value if type is INT, -1 if type is ID, and -2 if anything else.
The display method outputs the type (converts enum value 0-6 to their names), token, and priority.
There are 3 getter methods for each of the data members (type, token, priority) that return the 
variable. The 1-arg constructor calls the set method.

The Expression class contains an enum, a default and 1-arg constructor, public methods and 
private members. The Expression class's set method sets original to the string, postfix to empty, 
valid to false, type to ILLEGAL, and tokenized to a vector of the input string's tokens (splits the
string into tokens based on spaces and special characters as delimiters and adds them to the vector).
The display method outputs the original string, (vector of Tokens) tokenized's elements, number of tokens,
and the other data members (omitted from this lab). There are only 2 getter methods for this assignment
(get_original() and get_tokenized() returning the corresponding data members) since the other data members
are left out.

***************************************************************************************************/
#include <stdio.h>
#include <iostream>
#include "Expression.h"

using namespace std;

int main()
{
    //Token Class testing
    cout << "Token test 1:" << endl;
    Token tok1("AbCd"); //tests ID
    tok1.display();
    cout << endl;
    
    cout << "Token test 2:" << endl;
    Token tok2(""); //tests INVALID
    tok2.display();
    cout << endl;
    
    cout << "Token test 3:" << endl;
    Token tok3("342532"); //tests INT
    tok3.display();
    cout << endl;
    
    cout << "Token test 4:" << endl;
    Token tok4("A123"); //tests ID (letter followed by #s)
    tok4.display();
    cout << endl;
    
    cout << "Token test 5:" << endl;
    Token tok5("A12?3"); //tests INVALID (letter followed by non-letter/numbers)
    tok5.display();
    cout << endl;
    
    cout << "Token test 6:" << endl;
    Token tok6("12?b"); //tests INVALID (number followed by non-numbers)
    tok6.display();
    cout << endl;
    
    cout << "Token test 7:" << endl;
    Token tok7("0"); //tests INT (0 by itself)
    tok7.display();
    cout << endl;
    
    cout << "Token test 8:" << endl;
    Token tok8("0123"); //test INVALID (not integer b/c starts with 0)
    tok8.display();
    cout << endl;
    
    cout << "Token test 9:" << endl;
    Token tok9("123y"); //tests INVALID (not integer b/c number followed by non-number)
    tok9.display();
    cout << endl;
    
    cout << "Token test 10:" << endl;
    Token tok10(" "); //tests INVALID (space is not part of the enum)
    tok10.display();
    cout << endl;
    
    cout << "Token set method test:" << endl;
    tok9.set("abcd"); //tests set method
    tok9.display();
    cout << endl;
    
    //Expression Class testing
    cout << "Expression test 1:" << endl; //tests general expression (letters, parentheses, operators, numbers)
    Expression ex1("a12 = 1?ab + - a 0123 c (a + 12 3 )*(ab - (3 + 4 ))"); 
    ex1.display();
    cout << endl;
    
    cout << "Expression test 2:" << endl;
    Expression ex2(""); //tests empty expression
    ex2.display();
    cout << endl;
    
    cout << "Expression test 3:" << endl;
    Expression ex3(" "); //tests empty expression (spaces aren't counted)
    ex3.display();
    cout << endl;
    
    cout << "Expression test 4:" << endl; //tests another general expression (letters, parentheses, operators, numbers)
    Expression ex4(")  a23b+12cs-0023123  ab123((0)"); 
    ex4.display();
    cout << endl;
    
    cout << "Expression test 5:" << endl;
    Expression ex5("AbCd?2"); //tests 1 token expression (no spaces or special characters)
    ex5.display();
    cout << endl;
    
    cout << "Expression set method test:" << endl;
    ex4.set("1234"); //tests set method (checks clear functionality)
    ex4.display();
    cout << endl;
    
    return 0;
}