/* 
 * File:   main.cpp
 * Author: wingning
 *
 * Basic linked list
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

// Data element type, for now it is int, but we could change it to anything else
// by just changing this line
typedef int element_type;

// Basic Node structure
struct Node
{
    element_type elem;  // Data
    Node * next;        // Pointer to the next node in the chain
    Node * prev;        // Pointer to the previous node in the chain
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
        cout << "Node "          << setw(3) << i             << "   "
             << "Elem: "         << setw(3) << current->elem << "   "
             << "Address: "      << setw(8) << current       << "   "
             << "Next Address: " << setw(8) << current->next << "   "
             << "Prev Address: " << setw(8) << current->prev << "   "
             << endl;
        current = current->next;
        i++;
    }
    
    cout << "------------------------------------------------------------------------------------------" << endl;
}

// Print details about the given list in reverse order, one Node per line
void reverseShow(Node* tail)
{
    // TODO Implement in step 1.
    Node *current = tail;
    
    if (current ==  NULL){
        cout << "It is an empty list!" << endl;
    }
    int i = 0;
    while (current != NULL){
        cout << "Node "          << setw(3) << i             << "   "
             << "Elem: "         << setw(3) << current->elem << "   "
             << "Address: "      << setw(8) << current       << "   "
             << "Next Address: " << setw(8) << current->next << "   "
             << "Prev Address: " << setw(8) << current->prev << "   "
             << endl;
        current = current->prev;
        i++;
    }
    
    cout << "------------------------------------------------------------------------------------------" << endl;
}

int main() 
{
    const int size = 15;

    // Create the first node
    Node* head = new Node();
    head->elem = 0;
    head->prev = NULL;
    head->next = NULL;
    Node* tail = head;

    // Create a doubly linked list from the nodes
    for (int i = 1; i <= size; i++)
    {
        // Create the new node
        Node* node = new Node();
        node->elem = i;
        node->prev = tail;
        node->next = NULL;
        
        // Fold it into the list
        tail->next = node;
        
        // Move the tail
        tail = node;
    }
    show(head);
    reverseShow(tail);

    // TODO: Your code for steps 2-7 here.
    // Step #2
    Node *n = new Node();
    head -> prev = n;
    n -> next = head;
    n -> prev = NULL;
    n -> elem = 100;
    head = n;
    
    cout << "TASK #2:" << endl;
    show(head);
    reverseShow(tail);
    
    // Step #3
    n = new Node();
    tail -> next = n;
    n -> prev = tail;
    n -> next = NULL;
    n -> elem = -99;
    tail = n;
    
    cout << "TASK #3:" << endl;
    show(head);
    reverseShow(tail);
    
    // Step #4
    head = head -> next;
    delete head -> prev;
    head -> prev = NULL;
    
    cout << "TASK #4:" << endl;
    show(head);
    reverseShow(tail);
    
    // Step #5
    tail = tail -> prev;
    delete tail -> next;
    tail -> next = NULL;
    
    cout << "TASK #5:" << endl;
    show(head);
    reverseShow(tail);
    
    // Step #6
    int k = 3; //kth node from the tail
    if (tail == NULL || k < 0 || k > size){
        return 0;
    }
    Node *tmp = tail;
    
    for (int i = 1; i <= k && tmp != NULL; i++){
        tmp = tmp -> prev;
    }
    
    cout << "TASK #6:" << endl;
    show(head);
    reverseShow(tail);
    
    // Step #7
    if (tail == tmp){ //if trying to delete the tail, move tail back 1
        tail = tmp -> prev;
    }
    if (head == tmp){ //if trying to delete the head, move head forward 1
        head = tmp -> next;
    }
    if (tmp -> next != NULL){ //if tmp is NOT the last value
        tmp -> next -> prev = tmp -> prev; //the value before tmp goes to the location of tmp
    }
    if (tmp -> prev != NULL){ //if tmp is NOT the first value
        tmp -> prev -> next = tmp -> next; //the value after tmp goes to location of tmp
    }
    free(tmp); //prevents a memory leak
    
    cout << "TASK #7:" << endl;
    show(head);
    reverseShow(tail);
    
    // Clean up
    Node* current = head;
    while (current != NULL)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
    tail = NULL;
    
    return 0;
}

