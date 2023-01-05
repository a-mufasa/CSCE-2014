/***************************************************************************************************

Ahmed Moustafa 
CSCE2014 Programming Foundations II
Homework Six Checkpoint Two

Synopsis: 
homework6CP2.cpp contains the user input section of homework 6 that checks/handles for basic error 
for unexpected inputs. For checkpoint 2, we built upon the user input menu in checkpoint 1 to find the
postfix of an input and evaluate expressions when they are only integers. We assumed that all inputs
were valid (type ASSIGNMENT or ARITHMETIC) in this checkpoint, but future HW6 will need to account
for ILLEGAL types and invalid inputs.

For this checkpoint, the Token class functions the same as it did in Homwork Three as all we did in 
this checkpoint was handle user input menu in the main and work with expressions.

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
                string Exp = "";
                
                for (int i = 0; i < input.length(); i++){
                    if (input[i] == ';'){
                        Expression a(Exp);
                        
                        if(a.get_Etype() == ARITHMETIC){
                            cout << Exp << " = ";
                            a.evaluate(a.get_postfix());
                            Exp = "";
                        }
                        else if(a.get_Etype() == ASSIGNMENT){
                            cout << "cannot evaluate " << a.get_original() << " which is not an arithmetic expression, but assignment." << endl;
                        }
                    }
                    else{
                        Exp += input[i];
                    }
                }
            } 
            else if (action == "<"){ //postfix
                string Exp = "";
                
                for (int i = 0; i < input.length(); i++){
                    if (input[i] == ';'){
                        Expression a(Exp);
                        
                        if(a.get_Etype() == ARITHMETIC){
                            vector<Token> postfix = a.get_postfix();
                            cout << "postfix of " << Exp << " is: ";
                            for (int i = 0; i < postfix.size(); i++) {
                                cout << postfix[i].get_token() << " ";
                            }
                            cout << endl;
                        
                            Exp = "";
                        }
                        else if (a.get_Etype() == ASSIGNMENT){
                            cout << "no postfix of " << a.get_original() << " which is not an arithmetic expression, but assignment." << endl;
                        }
                    }
                    else{
                        Exp += input[i];
                    }
                }
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