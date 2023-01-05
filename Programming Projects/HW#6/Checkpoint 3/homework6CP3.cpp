/***************************************************************************************************

Ahmed Moustafa 
CSCE2014 Programming Foundations II
Homework Six Checkpoint Three

Synopsis: 
homework6CP3.cpp contains the user input section of homework 6 that checks/handles for basic error 
for unexpected inputs. For checkpoint 3, we built upon the checkpoint 2 to create the illegal syntax checks
using a expanded get_type method in the Expression class. We also finished prefix and fully parenthesize.

For this checkpoint, the Token class functions the same as it did in Homework Three; there was a new global
variable made in the Token class set function to save the value of a token for the evaluate method to account
for errors with negative numbers.

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
            if (input[input.length()-1] != ';'){
                cout << "missing ; at the end error!" << endl;
            }
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
                            Exp = "";
                        }
                        else{
                            cout << "cannot evaluate " << a.get_original() << " which is an invalid expression." << endl;
                            Exp = "";
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
                            Exp = "";
                        }
                        else{
                            cout << "no postfix of " << a.get_original() << " which is an invalid expression." << endl;
                            Exp = "";
                        }
                    }
                    else{
                        Exp += input[i];
                    }
                }
            } 
            else if (action == ">"){
                string Exp = "";
                
                for (int i = 0; i < input.length(); i++){
                    if (input[i] == ';'){
                        Expression a(Exp);
                        
                        if(a.get_Etype() == ARITHMETIC){
                            vector<Token> prefix = a.get_prefix();
                            cout << "prefix of " << Exp << " is: ";
                            for (int i = 0; i < prefix.size(); i++) {
                                cout << prefix[i].get_token() << " ";
                            }
                            cout << endl;
                        
                            Exp = "";
                        }
                        else if (a.get_Etype() == ASSIGNMENT){
                            cout << "no prefix of " << a.get_original() << " which is not an arithmetic expression, but assignment." << endl;
                            Exp = "";
                        }
                        else{
                            cout << "no prefix of " << a.get_original() << " which is an invalid expression." << endl;
                            Exp = "";
                        }
                    }
                    else{
                        Exp += input[i];
                    }
                }
            } 
            else if (action == "f" || action == "F"){ //fully parenthesize
                string Exp = "";
                
                for (int i = 0; i < input.length(); i++){
                    if (input[i] == ';'){
                        Expression a(Exp);
                        
                        if(a.get_Etype() == ARITHMETIC){
                            string fp = a.get_fp();
                            cout << "fully parenthesizing " << Exp << " is: " << fp << endl;
                            
                            Exp = "";
                        }
                        else if (a.get_Etype() == ASSIGNMENT){
                            cout << "no fully parenthesizing of " << a.get_original() << " which is not an arithmetic expression, but assignment." << endl;
                            Exp = "";
                        }
                        else{
                            cout << "no fully parenthesizing of " << a.get_original() << " which is an invalid expression." << endl;
                            Exp = "";
                        }
                    }
                    else{
                        Exp += input[i];
                    }
                }
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