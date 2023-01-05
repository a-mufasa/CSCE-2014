/* 
 * File:   main.cpp
 * Author: wingning
 *
 * Basic linked list
 */

#include <cstdlib>
#include <iostream>

using namespace std;

// Data element type, for now it is int, but we could change it to anything else
// by just changing this line
typedef int element_type;

// Basic Node structure
struct Node
{
    element_type elem;  // Data
    Node * next;        // Pointer to the next node in the chain
    Node * prev;        // Pointer to the previous node in the chain, not used for lab 7
};

// Print details about the given list, one Node per line
void show(Node* head)
{
    Node* current = head;
    
    if (current == NULL)
        cout << "It is an empty list!" << endl;
    
    int i = 0;
    while (current != NULL) 
    {
        cout << "Node " << i << "\tElem: " << '\t' << current->elem << "\tAddress: " << current << "\tNext Address: " << current->next << endl;
        current = current->next;
        i++;
    }
    
    cout << "----------------------------------------------------------------------" << endl;
}

int main() 
{
    const int size = 15;

    Node* head    = new Node();
    Node* current = head;

    // Create a linked list from the nodes
    for (int i = 0; i < size; i++)
    {
        current->elem = i;
        current->next = new Node();
        current       = current->next;
    }
    
    // Set the properties of the last Node (including setting 'next' to NULL)
    current->elem = size;
    current->next = NULL;
    show(head);

    // TODO: Your Code Here
    
    //Task 1: Delete the first element
    cout << "TASK #1:" <<endl;
    
    current = head->next;
    delete head;
    head = current;
    
    show(head);
    
    //Task 2: Delete the last element
    cout << "TASK #2:" <<endl;
    
    current = head;
    while (current->next->next != NULL){
        current = current->next;
    }
    delete current->next;
    current->next = NULL;
    
    show(head);
    
    //Task 3: Insert 10 elements at the start
    cout << "TASK #3:" <<endl;
    
    Node* begin_1;
    const int len_1 = 10;
    
    for (int i = 0; i < len_1; i++)
    {
        begin_1 = new Node();
        begin_1->elem = i;
        begin_1->next = head;
        head = begin_1;
    }
    show(head);
    
    //Task 4: Insert 10 elements after the first node w/ value 7
    cout << "TASK #4:" <<endl;
    
    current = head;
    Node* begin_2;
    const int len_2 = 10;
    const int val = 7;
    
    while (current != NULL){
        if (current->elem == val){
            for (int i = len_2-1; i >= 0; i--){
                begin_2 = new Node();
                begin_2->elem = i;
                begin_2->next = current->next;
                current->next = begin_2;
            }
            break;
        }
        current = current->next;
    }
    
    show(head);
    
    // Clean up
    current = head;
    while (current != NULL)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
    
    return 0;
}
