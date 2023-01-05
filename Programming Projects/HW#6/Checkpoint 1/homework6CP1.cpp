/***************************************************************************************************

Ahmed Moustafa 
CSCE2014 Programming Foundations II
Homework Six Checkpoint One

Synopsis: 
homework6CP1.cpp contains the user input section of homework 6 that checks/handles for basic error 
for unexpected inputs. For checkpoint 1, this main only tests for user input errors in the action
string because the executable file on Turing did not check for errors that were related to the
expression sequence until after running the specified action (which we have not been asked to 
code for in this checkpoint).

For this checkpoint, the Token and Expression class function the same as they did in Homwork Three
as all we did in this checkpoint was handle user input menu in the main.

***************************************************************************************************/
#include <stdio.h>
#include <iostream>
#include <string>
#include "Expression.h"

using namespace std;

void menu() //takes in user input and check for errors in the action requested
{
    string action = "";
    string input = "";
    string temp = "";
    
    while (action != "q")
    {
        action = "";
        cout << "input:";
        getline(cin, temp);
        input += temp;
        cout << "action:";
        getline(cin, action);
        while ( action != "=" && action != "<" && action != ">" && action != "f" && action != "F" 
                && action != "q" && action != "Q" && action != "c" && action != "C" && action != "s" 
                && action != "S")
        {
            cout << "Wrong input for the action! Please type one of =, <, >, f(F), q(Q), c(C), s(S)" << endl;
            cout << "action:"; 
            getline(cin, action);
        }
        while (action == "=" || action == "<" || action == ">" || action == "f" || action == "F")
        {
            if (action == "="){ //equal
                cout << "equal placeholder" << endl; 
            } 
            else if (action == "<"){ //postfix
                cout << "postfix placeholder" << endl; //prefix
            } 
            else if (action == ">"){
                cout << "prefix placeholder" << endl;
            } 
            else if (action == "f" || action == "F"){ //fully parenthesize
                cout << "fully parenthesize placeholder" << endl;
            } 
            
            cout << "action:";
            getline(cin, action);
            
            while ( action != "=" && action != "<" && action != ">" && action != "f" && action != "F" 
                    && action != "q" && action != "Q" && action != "c" && action != "C" && action != "s" 
                    && action != "S")
            {
                cout << "Wrong input for the action! Please type one of =, <, >, f(F), q(Q), c(C), s(S)" << endl;
                cout << "action:";
                getline(cin, action);
            }
        }
        if (action == "s" || action == "S"){
            input = "";
        }
        else if ((action == "c" || action == "C") && input.at(input.length()-1) != ';'){
            input += ";";
        }
        
    }
}

int main()
{
    cout << "=== expression evaluation program starts ===" << endl;
    menu();
    cout << "=== expression evaluation program ends ===" << endl;
    return 0;
}

/*int main() //HW3 Testing
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
}*/