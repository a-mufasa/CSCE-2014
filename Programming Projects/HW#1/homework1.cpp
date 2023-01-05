/************************************************************************************

Ahmed Moustafa 
CSCE2014 Programming Foundations II
Homework One

Synopsis:
homework.cpp contains the implementation of tester functions for function 2 (testing_not)
and 3 (testing_in). Function 1, 2, and 3 are implemented in helper.cpp and included in 
homework.cpp throuh helper.h. Function 1 returns a boolean value depending on whether 
the input character is part of the set. Function 2 returns the first character in a string 
that is not part of the set. Function 3 returns the first chracter in a string that is 
also part of the set. Both function 2 and 3 use function 1 in their implementation.

************************************************************************************/
#include <stdio.h>
#include <iostream>
#include <cstring>
#include "helper.h"
using namespace std;

//Tester function for function 2
void testing_not(char* test_string, const char* test_set)
{
    cout << "calling find_first_not_in_the_set with \"" << test_string << "\" and \"" << test_set << "\"" << endl;
        
    char * p = find_first_not_in_the_set(test_string, test_set);
        
    if ( p != NULL){
        cout << "the function returns the address of " << *p << endl;
        cout << "the cstring at this address is \"" << p << "\"" << endl;
    }      
    else
        cout << "the function returns NULL" << endl;
}

//Tester function for function 3
void testing_in(char* test_string, const char* test_set)
{
    cout << "calling find_first_in_the_set with \"" << test_string << "\" and \"" << test_set << "\"" << endl;

    char * p = find_first_in_the_set(test_string, test_set);

    if ( p != NULL){
        cout << "the function returns the address of " << *p << endl;
        cout << "the cstring at this address is \"" << p << "\"" << endl;
    } 
    else
        cout << "the function returns NULL" << endl;
}

int main()
{
    //Initial SAMPLE TEST
    cout << "INITIAL SAMPLE TEST:" << endl; 
    
    char test_string[50]; //set array size up to 30 for the string
    char test_set[50]; //set array size up to 30 for the set

    char *p; // pointer to the return character
    strcpy(test_string, "Hi Everyone!");
    strcpy(test_set, "e");

    char x = 'h';
    
    if (is_char_in_the_set(x, test_string))
        cout << x << " appears in the following string: " << test_string << endl;
    else
        cout << x << " does not appear in the following string: " << test_string << endl;
    //the output is h does not appear in the following string: Hi Everyone!
    
    p = find_first_in_the_set(test_string, test_set);
        cout << *p << endl; // the  output should be e and *(p-1) is v and *(p+1) is r
        
    p = find_first_not_in_the_set(test_string, test_set);
        cout << *p << endl; // the output should be H
        cout <<endl;
    
    //MY TESTS
    cout << "MY TESTS:" << endl;
    
    strcpy(test_string, "Corona virus?");
    strcpy(test_set, "covid-19");
    testing_not(test_string, test_set); //output should be C
    cout << endl;
    testing_in(test_string, test_set); //output should be o
    cout << endl;
    
    strcpy(test_string, "Ahmed");
    strcpy(test_set, "Ahmed");
    testing_not(test_string, test_set); //output should be NULL
    cout << endl;
    testing_in(test_string, test_set); //output should be A
    cout << endl;
    
    strcpy(test_string, "1 29 )&@ 721 =-92!3**#&");
    strcpy(test_set, "@#)_(* *&^5 7 -- 75 (((001000");
    testing_not(test_string, test_set); //output should be 2
    cout << endl;
    testing_in(test_string, test_set); //output should be 1
    cout << endl;
    
    //SAMPLE TESTING of first function - bool is_char_in_the_set (char ch, const char * set):
    cout << "INDIVIDUAL SAMPLE TESTING OF FIRST FUNCTION:" << endl;
    
    strcpy(test_set, "abcd");
    
    x = 'a'; 
    if (is_char_in_the_set(x, test_set))
        cout << x << " appears in the following string: " << test_set << endl;
    else
         cout << x << " does not appear in the following string: " << test_set << endl;
    //output should be "a appears in the following string: abcd"
 
    x = 'd';
    if (is_char_in_the_set(x, test_set))
         cout << x << " appears in the following string: " << test_set << endl;
    else
        cout << x << " does not appear in the following string: " << test_set << endl;
    //output should be "d appears in the following string: abcd"
 
    x = '#'; 
     if (is_char_in_the_set(x, test_set))
         cout << x << " appears in the following string: " << test_set << endl;
     else
         cout << x << " does not appear in the following string: " << test_set << endl;
    //output should be "# does not appear in the following string: abcd"
 
    x = '\0'; 
    if (is_char_in_the_set(x, test_set))
         cout << x << " appears in the following string: " << test_set << endl;
     else
        cout << x << " does not appear in the following string: " << test_set << endl;
    //output should be " appears in the following string: abcd"
 
    test_set[0] = '\0';
    
    x = 'a'; 
    if (is_char_in_the_set(x, test_set))
        cout << x << " appears in the following string: " << test_set << endl;
    else
        cout << x << " does not appear in the following string: " << test_set << endl;
    //output should be "a does not appear in the following string:"

    x = '\0'; 
    if (is_char_in_the_set(x, test_set))
         cout << x << " appears in the following string: " << test_set << endl;
    else
         cout << x << " does not appear in the following string: " << test_set << endl;
    //output should be " appears in the following string:"
    
    //SAMPLE TESTING of 2nd function - char * find_first_not_in_the_set(char * str, const char * set):
    cout << "\nINDIVIDUAL SAMPLE TESTING OF SECOND FUNCTION:" << endl;
    
    strcpy(test_string, "ls -l -a | wc -c >> myfile");
    strcpy(test_set, "c");
    testing_not(test_string, test_set); //output should be address of l and cstring "ls -l -a | wc -c >> myfile"
    cout << endl;
    
    strcpy(test_string, "ls -l -a | wc -c >> myfile");
    strcpy(test_set, "sl -c");
    testing_not(test_string, test_set); //output should be address of a and cstring "a | wc -c >> myfile"
    cout << endl;
    
    strcpy(test_string, "-- // --- -");
    strcpy(test_set, " -/");
    testing_not(test_string, test_set); //output should be NULL
    cout << endl;
    
    strcpy(test_string, "-- // --- -");
    strcpy(test_set, "abc");
    testing_not(test_string, test_set); //output should be address of - and cstring "-- // --- -"
    cout << endl;
    
    strcpy(test_string, "ls -l -a | wc -c >> myfile");
    strcpy(test_set, "ls-l-a|wc-c>>myfile");
    testing_not(test_string, test_set); //output should be address of  and cstring " -l -a | wc -c >> myfile"
    cout << endl;
    
    strcpy(test_string, "ls -l -a | wc -c >> myfile");
    strcpy(test_set, "ls -l -a | wc -c >> myfilE");
    testing_not(test_string, test_set); //output should be address of e and cstring "e"
    cout << endl;
    
    strcpy(test_string, "ls-l-a|wc-c>>myfile");
    strcpy(test_set, "");
    testing_not(test_string, test_set); //output should be address of l and cstring "ls-l-a|wc-c>>myfile"
    cout << endl;
    
    strcpy(test_string, "");
    strcpy(test_set, " xze");
    testing_not(test_string, test_set); //output should be NULL
    
    //SAMPLE TESTING of 3rd function - char * find_first_in_the_set(char * str, const char * set):
    cout << "\nINDIVIDUAL SAMPLE TESTING OF THIRD FUNCTION:" << endl;
    
    strcpy(test_string, "ls -l -a | wc -c >> myfile");
    strcpy(test_set, "c");
    testing_in(test_string, test_set); //output should be address of c and cstring "c -c >> myfile"
    cout << endl;
    
    strcpy(test_string, "ls -l -a | wc -c >> myfile");
    strcpy(test_set, "sl -c");
    testing_in(test_string, test_set); //output should be address of l and cstring "ls -l -a | wc -c >> myfile"
    cout << endl;
    
    strcpy(test_string, "-- // --- -");
    strcpy(test_set, " -/");
    testing_in(test_string, test_set); //output should be address of - and cstring "-- // --- -"
    cout << endl;
    
    strcpy(test_string, "-- // --- -");
    strcpy(test_set, "abc");
    testing_in(test_string, test_set); //output should be NULL
    cout << endl;
    
    strcpy(test_string, "ls -l -a | wc -c >> myfile");
    strcpy(test_set, "bdgEe");
    testing_in(test_string, test_set); //output should be address of e and cstring "e"
    cout << endl;
    
    strcpy(test_string, "ls-l-a|wc-c>>myfile");
    strcpy(test_set, "");
    testing_in(test_string, test_set); //output should be NULL
    cout << endl;
    
    strcpy(test_string, "");
    strcpy(test_set, " xze");
    testing_in(test_string, test_set); //output should be NULL
}
