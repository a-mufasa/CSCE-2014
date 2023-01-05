/***************************************************************************************************

Ahmed Moustafa 
CSCE2014 Programming Foundations II
Homework Six Final Version

Synopsis: 
homework6.cpp contains the user input section of homework 6 that checks/handles for basic error 
for unexpected inputs. In HW6, we split the work up into separate checkpoints where we completed HW3
methods and then added methods for user input, error testing, postfix & prefix notation, fully 
parenthesizing, and expression evaluation. The token class remains unchanged while the Expression class
includes new function using the stack data structure to store and modify user inputs.

***************************************************************************************************/
#include <stdio.h>
#include <iostream>
#include <string>
#include "Expression.h"

using namespace std;

string remove_spaces(string s){
    string temp_save = "";
    for (int i = 0; i < s.length(); i++){
        if (s[i] != ' '){
            temp_save += s[i];
        }
    }
    return temp_save;
}

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
            string save = "";
            vector<Expression> total;
            for (int i = 0; i < input.length(); i++){
                if (input[i] == ';'){
                    Expression e(save);
                    total.push_back(e);
                    save = "";
                }
                else{
                    save += input[i];
                }
            }
            
            if (remove_spaces(save) != ""){
                cout << "missing ; at the end error!" << endl;
            }
            if (action == "="){ //equal
                for (int i = 0; i < total.size(); i++){
                    Expression a = total[i];
                    if(a.get_Etype() == ARITHMETIC){
                        cout << a.get_original() << " = ";
                        a.evaluate(total);
                    }
                    else if(a.get_Etype() == ASSIGNMENT){
                        cout << "cannot evaluate " << a.get_original() << " which is not an arithmetic expression, but assignment." << endl;
                    }
                    else{
                        cout << "cannot evaluate " << a.get_original() << " which is an invalid expression." << endl;
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