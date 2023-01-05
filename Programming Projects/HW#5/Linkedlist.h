#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
using namespace std;

class Linkedlist
{
    public:
        typedef int element_type; //
        typedef element_type& reference; //
        typedef const element_type& const_reference; //
        
        Linkedlist();   
        ~Linkedlist();  
        bool empty() const;  
        void clear();  
      
        reference back();  
        const_reference back() const;  
        reference front();  
        const_reference front() const;  
        
        Linkedlist& operator=(const Linkedlist& l);  
        void pop_back();  
        void pop_front();  
        void push_back(const element_type& x);  
        void push_front(const element_type& x);  
        void sort();  
        explicit Linkedlist(unsigned int n); 
        void check() const;  
        void rcheck() const;  
        void insert(unsigned int pos, const element_type& x);  
        void erase(unsigned int pos); 
        
    private:
        struct Node
        {
            element_type elem;
            Node * next;
            Node * prev;
        };
        Node * head = new Node();
        Node * tail = new Node();
        int size;
};

#endif