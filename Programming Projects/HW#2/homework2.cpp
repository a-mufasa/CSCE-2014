/************************************************************************************

Ahmed Moustafa 
CSCE2014 Programming Foundations II
Homework Two

Synopsis: 
homework2.cpp contains the test cases for the mystrtok function. The mystrtok function
is implemented in mystrtok.cpp and included in homework2.cpp through "mystrtok.h". 
The mystrtok function uses both function 2 (find_first_not_in_the_set) and function 3 
(find_first_in_the_set) from homework1 in its implementation (function 2 and 3 
implementation are explained in the second paragraph). The mystrtok function returns the
address of the token separated by the a delimiter in a string, and can be run for the total
number of tokens for each string (until mystrtok outputs null).

Function 1, 2, and 3 are implemented in helper.cpp and included in mystrtok.cpp through
helper.h (mystrtok.cpp includes mystrtok.h which includes helper.h). Function 1 returns a 
boolean value depending on whether the input character is part of the set. Function 2 
returns the first character in a string that is not part of the set. Function 3 returns 
the first chracter in a string that is also part of the set. Both function 2 and 3 use 
function 1 in their implementation.

************************************************************************************/
#include <stdio.h>
#include <iostream>
#include <cstring>
#include "mystrtok.h"
using namespace std;

int main()
{
    //Lab 3 Test Case: single character delimiter 
    //(output should be the string w/o spaces)
    cout<<"Lab 3 Test Case:" <<endl;
    char test[] = "ls -l -a | wc -c >> myfile"; //Lab3 Test Case
    char* ptr = mystrtok(test, " ");
    while (ptr != nullptr) 
    {
        cout << ptr;
        ptr = mystrtok(nullptr, " ");
    }
    cout << "\n" << endl;
   
    //Test Case 1: null string input 
    //(output should be null)
    cout<<"Test 1:" <<endl;
    char test1[] = "";                          //Test 1
    ptr = mystrtok(test1, " ");
    while (ptr != NULL) 
    {
        cout << ptr;
        ptr = mystrtok(NULL, " ");
    }
    cout << "\n" << endl;
    
    //Test Case 2: empty delimiter 
    //(output should be string)
    cout<<"Test 2:" <<endl;
    char test2[] = "banana bread";              //Test 2
    ptr = mystrtok(test2, "");
    while (ptr != NULL) 
    {
        cout << ptr;
        ptr = mystrtok(NULL, "");
    }
    cout << "\n" << endl;
    
    //Test Case 3: multiple character delimiter 
    //(output should be string w/o spaces, commas, periods, and -)
    cout<<"Test 3:" <<endl;
    char test3[] = "- This, a sample string.";  //Test 3
    ptr = mystrtok(test3, " ,.-");
    while (ptr != NULL) 
    {
        cout << ptr;
        ptr = mystrtok(NULL, " ,.-");
    }
    cout << "\n" << endl;
    
    //Test Case 4: delimiter is the same as the string 
    //(output should be an empty string)
    cout<<"Test 4:" <<endl;
    char test4[] = "Zheng Hu";                  //Test 4
    ptr = mystrtok(test4, "Zheng Hu");
    while (ptr != NULL) 
    {
        cout << ptr;
        ptr = mystrtok(NULL, "Zheng Hu");
    }
    cout << "\n" << endl;
    
    //Test Case 5: string and delimiter have no similar characters
    //(output should be the string)
    cout<<"Test 5:" <<endl;
    char test5[] = "Presidential";              //Test 5
    ptr = mystrtok(test5, "=#");
    while (ptr != NULL) 
    {
        cout << ptr;
        ptr = mystrtok(NULL, "=#");
    }
    cout << "\n" << endl;

    return 0;
}

