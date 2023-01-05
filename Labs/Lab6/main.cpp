/* 
 * File:   main.cpp
 * Author: wingning
 *
 * Created on October 1, 2010, 11:04 AM
 * Modified on January 18, 2016
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "Mystring.h"

#define string Mystring

using namespace std;

/*
 * Check function from the previous lab
 */
void check (const string s, const string name)
{
    cout << "checking " << name << endl;
    cout << name << " contains " << s << endl;
    cout << name << " capacity() is " << s.capacity() << endl;
    cout << name << " length() is " << s.length() << endl;
    cout << name << " size() is " << s.size() << endl;
    cout << name << " max_size() is " << s.max_size() << endl << endl;
}

int main() 
{
    cout << "This is Lab 6" << endl;
    string s1 = "Hello, World!";
    string s1name = "s1";
    check(s1, s1name);
    check(s1, s1name);
    cout<< "Lab 6 ends" << endl;
    
    return 0;
}
