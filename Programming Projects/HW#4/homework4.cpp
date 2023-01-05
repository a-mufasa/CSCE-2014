/***************************************************************************************************

Ahmed Moustafa 
CSCE2014 Programming Foundations II
Homework Four

Synopsis: 
homework4.cpp contains the tests for the Mystring class. The Mystring class 
is defined in Mystring.h and implemented in Mystring.cpp (both homework4.cpp and Mystring.cpp
include Mystring.h). 

Mystring.cpp contains the implementation of all the member functions, operators, as well as non-member
operators, declared in Mystring.h. The cpp file contains code from the Lab06 cpp file in which some
of the operators and functions from Mystring.h were previously implemented. In this HW assignment,
we had to build upon the previous implementation, implementing the memory-related reserve method and empty 
method. Next, we overload operators for both Mystring object inputs and c-string inputs (=, [], +=).
Next, we implement string modifying methods clear, push_back, append, insert, and replace. Two new methods
that were implemented that were not in Lab6 were find_first_of and find_last_not_of. Finally, we overload
global operators ==, !=, and +. Since the helper file includes <cstring>, we were able to use cstring 
functions such as strcat, strlen, strcpy, and strcmp in our implementation.

***************************************************************************************************/
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
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
    cout << "This is Homework 4\n";
    string s1("Hello, World!");
    string s1name("s1");
    check (s1, s1name);
    
    cout << "---Testing assignment operator---\n\n";
    string s2;
    s2=s1; //sets them equal to each other
    string s2name("s2");
    check(s2,s2name); //compares to s1
    check(s1,s1name); //compares to s2
    
    cout << "---Testing append operator---\n\n";
    s2+=s1; //appends s1 to s2
    check(s2,s2name);
    s2+=":-)"; //appends :-) to s2
    check(s2,s1name);
    
    cout << "---Testing push_back---\n\n";
    s2.push_back('H'); //adds 'H' to the end
    s2.push_back('i'); //adds 'i' to the end
    s2.push_back('!'); //adds '!' to the end
    check(s2,s2name);
    
    cout << "---Testing append---\n\n";
    string s3("ABC");
    string s3name("s3");
    s1.append(s3); //append s3 to s1
    check(s1,s1name);
    s1.append("DEF"); //append DEF to s1
    check(s1,s1name);
    
    cout << "---Testing insert---\n\n"; 
    s1.insert(5,s3); //inserts s3 at index 5
    check(s1,s1name);
    s1.insert(5,"DEF"); //inserts DEF at index 4
    check(s1,s1name);
    
    cout << "---Testing replace---\n\n"; 
    s1.replace(5,3,s2); //replace 3 characters of s1 at index 5 with s2
    check(s1,s1name);
    s1.replace(8,3,"lo!l"); //replace 3 characters of s1 at index 8 with lo!l
    check(s1,s1name);
    
    cout << "---Testing find_first_of---\n\n"; 
    cout << "The first comma is at pos " << s1.find_first_of(",",0,25) << "\n"; //finds the first comma
    check(s1,s1name);
    cout << "The first e is at pos " << s1.find_first_of("e",0,25) << "\n"; //finds the first e
    check(s1,s1name);
     
    cout << "---Testing last_not_of and [] operator---\n\n"; 
    cout << "The last thing not a comma is at pos " << s1.find_last_not_of(",") << "\n"; //find the last character that isnt a comma
    cout << s1[s1.find_last_not_of(",")] << endl; //output the value of that last character
    check(s1,s1name);
    cout << "The last thing not l is at pos " << s1.find_last_not_of("l") << "\n"; //find the last character that isnt an l
    cout << s1[s1.find_last_not_of("l")] << endl; //output the value of that last character
    check(s1,s1name);
     
    cout << "---Testing equivalence == ---\n\n";
    string s4(s3);
    string s4name("s4"); 
    if (s3 == s4)
        cout << "s3 == s4 \n";
    check(s3,s3name);
    check(s4,s4name);
    if (s4 == "ABC")
        cout << "s4 == ABC\n";
    if ("ABC" == s4)
        cout << "ABC == s4\n\n";
     
    cout << "---Testing clear and empty---\n\n";
    s4.clear();
    if (s4.empty())
        cout << "s4 is empty\n";
    else
        cout << "s4 is not empty\n";
    check(s4,s4name);
     
    cout << "---Testing nonequivalence != ---\n\n";
    if (s3 != s4)
       cout << "s3 != s4 \n";   
    if (s4 != "ABC")
       cout << "s4 != ABC\n";
    if ("ABC" != s4)
       cout << "ABC != s4\n";
    check(s3,s3name);
    check(s4,s4name);

    cout << "---Testing + operator---\n\n";
    cout<<"before:\n";
    check(s2,s2name);
    check(s3,s3name);
    check(s4,s4name);

    s4 = s2 + s3; //add s2 to s3
    cout<<"after:\n";
    
    check(s2,s2name);
    check(s3,s3name);
    check(s4,s4name);
    
    cout << "---Testing replace special cases---\n\n";
    //s5 should be "Hddo"
    string s5("Hello");
    s5.replace(1, 3, "dd"); //replaces 3 characters of Hello starting at index 1 with string "dd"
    check(s5,"s5");
    
    //s6 should be the same as s7 "Dips"
    string s6("Dog");
    s6.replace(1, 2, "ips"); //replaces 2 characters of Dog starting at index 1 with string "ips"
    check(s6,"s6");
    
    string s7("Dog");
    s7.replace(1, 3, "ips"); //replaces 3 characters of Dog starting at index 1 with string "ips"
    check(s7,"s7");
    
    //s8 should be "Ahobama"
    string s8("Ahmed");
    s8.replace(2, 5, "obama"); //replaces 5 characters of Ahmed starting at index 2 with string "obama"
    check(s8,"s8");
    
    //s9 should be "poapples"
    string s9("potato");
    s9.replace(2, 5, "apples"); //replaces 5 characters of potato starting at index 2 with string "apples"
    check(s9,"s9");
    
    cout << "HW4 end\n";        

    return 0;
}

/*int main() 
{
    string s1("Hello, World!");
    string s1name("s1");
    check(s1, s1name);    
    
    cout << "---Testing assignment operator and == operator---\n";    
    string s2;
    s2=s1 ;
    string s2name("s2");
    check(s2,s2name);
    if(s1== s2)
        cout << "s1 and s2 are same string" << endl;
   
    string s3("Hi");
    check(s3,"s3");
    s3 = "Hey";
    check(s3,"s3");
    cout << s3 << endl; 
    if(s3 != "Hey")
        cout << "your assignment operator is wrong" << endl;
    else
        cout << "assignment operator is correct" << endl;
    cout << "--------------------------------------\n\n" ;  
    
    
    cout << "---Testing array notation---\n";
    cout << "second char of s1: "<< s1[1] << endl;
    cout << "--------------------------------------\n\n" ;  
    
     
    cout << "---Testing += operator ---\n";
    s2 += s1;
    cout << "s2 after += s1: "<< s2 << endl;
    s3 += " you";
    cout << s3 << endl;           
    cout << "--------------------------------------\n\n" ;  
    
    
    cout << "---Testing append ---\n";
    s2.append("??");
    cout << "s2 after append s1: "<< s2 << endl;
    check(s2,"s2");
    cout << "--------------------------------------\n\n" ; 
    
    
    cout << "---Testing insert ---\n";
    s2.insert(6, "c++");
    cout << "s2 after insert: "<< s2 << endl;
    cout << "--------------------------------------\n\n" ;   
     
    
    cout << "---Testing replace ---\n";
    s2.replace(6, 7, "code");
    cout << "s2 after replace: "<< s2 << endl;
    cout << "--------------------------------------\n\n" ;

    cout << "---Testing find_first_of ---\n";
    cout << "s2 find first of aeiou after index 2: " << s2.find_first_of("aeiou", 2, 9);
    cout << "--------------------------------------\n\n" ;
    
    
    cout << "---Testing find_last_not_of ---\n";
    cout << "s1: " << s1.length() << endl;
    cout << "s1 find find_last_not_of !? after index 2: " << s1.find_last_not_of("!?");
    cout << "--------------------------------------\n\n" ;
    
    
    cout << "---Testing + ---\n";
    s3 = s1 + s2;
    cout << s3 << endl;
    cout << "--------------------------------------\n\n" ;
    
//    myfile.close();
          
    return 0;
}*/

