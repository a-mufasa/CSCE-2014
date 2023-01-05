/******************************************************************************************************************

Ahmed Moustafa 
CSCE2014 Programming Foundations II
Homework Five

Synopsis: 
homework5.cpp contains the tests for the Linkedlist class. The Linkedlist class 
is defined in Linkedlist.h and implemented in Linkedlist.cpp (both homework5.cpp and Linkedlist.cpp include Mystring.h). 

Linkedlist.cpp contains the implementation of all the member functions and operators declared in Mystring.h. 
In this HW assignment, we had to build the Linkedlist class from scratch, with some functions in the header file
matching previous implementations from Lab7 and Lab8. In Linkedlist.cpp we had to implement a default constructor,
a destructor, an explicit constructor, a = operator and many methods. These methods were empty() which checks if the 
list is empty, clear() which empties a list, back() which returns the last element, front() which returns the first 
element, pop_back() which removes the last element, pop_front() which removes the first element, push_back() which
adds an element to the end of the list, push_front() which adds an element to the beginning of the list, sort() which
re-orders the list to be ascending, check() which prints out the list, rcheck() which prints out the list in reverse,
insert() which adds a new element to the list at a position, and erase() which removes an element at a position.

********************************************************************************************************************/
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <list>
#include "Linkedlist.h"

using namespace std;

/*
 * detailed points allocation removed.
 * but if your program pass all the test cases here
 * you will get 70/80 points allocated for correctness, efficiecy, 
 * design, and testing.
 *
 */
int main(int argc, char** argv) { //given test cases

    cout  << "1. ---Testing constructor and check function \n";
    Linkedlist list(4);
    list.check();
    list.rcheck();
    cout << "--------------------------------------\n\n" ;

//
    cout  << "2. ---Testing push front 7  \n";
    cout << "before push front: " << endl;
    list.check();
    list.push_front(7);
    list.check();
    list.rcheck();
    cout << "--------------------------------------\n\n" ;

    cout  << "3. ---Testing push back  -1 \n";
    cout << "before push back: " << endl;
    list.check();
    list.push_back(-1);
    list.check();
    list.rcheck();
    cout << "--------------------------------------\n\n" ;

    cout  << "4. ---Testing insert 5 at position 2  \n";
    cout << "before insert: " << endl;
    list.check();
    list.insert(2, 5);
    list.check();
    list.rcheck();
    cout << "--------------------------------------\n\n" ;

    cout  << "5. ---Testing front  \n";
    cout << list.front() << endl;
    list.front() = 1234;
    cout << list.front() << endl;

    cout << "--------------------------------------\n\n" ;

    cout  << "6. ---Testing back  \n";
    cout << list.back() << endl;
    list.back()  = 5678;
    cout << list.back() << endl;

    cout << "--------------------------------------\n\n" ;

    cout  << "7. ---Testing sort  \n";
    cout << "before sort: " << endl;
    list.check();
    list.sort();
    list.check();
    list.rcheck();
    cout << "--------------------------------------\n\n" ;
    
    return 0;
}

/*int main() //my test cases
{
    Linkedlist list1(10); //list with size of 10; tests explicit constructor
    Linkedlist list2; //empty list; tests default constructor
   
    list1.check();
    list1.rcheck();
   
    list2.check(); //should be empty
    list2.rcheck(); //should be empty
 
    cout << list1.empty() << endl; //tests empty function; should output 0
    cout << list2.empty() << endl; //tests empty function; should output 1
   
    list1.clear(); //empties the list a
   
    list1.check();  //should be empty
    list1.rcheck(); //should be empty
   
    cout << list1.empty() << endl; //tests empty function; should output 1
    cout << list2.empty() << endl; //tests empty function; should output 1
    cout << "--------------------------------------\n\n";
   
    Linkedlist list3(8); //list with size of 8; tests explicit constructor
    Linkedlist list4(5); //list with size of 5; tests explicit constructor
   
    list3.check();
    list4.check();
   
    list3 = list4; //sets list 3 equal to list 4; list 3 should now be the same as 4
   
    list3.check();
    list3.rcheck();
   
    list3.pop_back(); //remove the last element
   
    list3.check();
    list3.rcheck();
   
    list3.pop_front(); //remove the first element
  
    list3.check();
    list3.rcheck();
   
    list3.push_back(337); //add the element 100 to the end of the list
   
    list3.check();
    list3.rcheck();
   
    list3.push_front(666); //add the element 199 to the front of the list
   
    list3.check();
    list3.rcheck();
   
    cout << "--------------------------------------\n\n";
   
    Linkedlist list5; //empty list; tests default constructor
    cout << list5.empty() << endl; //tests empty function; should output 1
   
    for(int i = 0; i < 10; i++){
        list5.push_front(i); //list should go from 9 to 0
    }
    
    cout << list5.empty() << endl; //tests empty function; should output 0
  
    list5.check();
  
    list5.sort(); //tests sort function; list should now go from 0 to 9
  
    list5.check();
  
    list5.insert(5,1234); //tests insert function; adds a new element at position 5 with a value of 1234 to the list
  
    list5.check();
    list5.rcheck();
  
    list5.erase(5); //tests erase function; removes the node at position 5 that we added from the list
  
    list5.check();
    list5.rcheck();
   
    return 0;
}*/