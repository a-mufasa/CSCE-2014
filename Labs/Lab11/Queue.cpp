#include "Queue.h"
using namespace std;

Queue::Queue()
{
    head = new Node();
    tail = head;
    numElements = 0;
}
Queue::~Queue()
{
    Node* current = head;
    while (current != NULL){
        Node* link = current->next;
        delete current;
        current = link;
    }
}
bool Queue::empty() const
{
    return numElements == 0;
}
unsigned int Queue::size() const
{
    return numElements;
}
int& Queue::front()
{
    return head -> elem;
}
const int& Queue::front() const
{
    return head -> elem;
}
int& Queue::back()
{
    return tail -> elem;
}
const int& Queue::back() const
{
    return tail -> elem;
}
void Queue::push(const int& x)
{
    numElements++;
 
    if(numElements == 1){
     head -> elem = x;
     tail = head;
     tail -> next = NULL;
    }
    else{
     Node* a = new Node();
     a -> elem = x;
    
     tail -> next = a;
     tail = a;
     tail -> next = NULL;
    }
}
void Queue::pop()
{
    numElements --;
    head = head -> next;
}
void Queue::print()
{
    cout << "[ ";
    for (Node* cur = head; cur != NULL; cur = cur -> next){
        cout << cur -> elem << " ";
    }
    cout << "]" << endl;
}