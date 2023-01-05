#include "Linkedlist.h"

Linkedlist::Linkedlist()
{
    head = NULL;
    tail = head;
    size = 0;
}
Linkedlist::~Linkedlist()
{
    clear();
}
bool Linkedlist::empty() const
{
    return (head == NULL && tail == head);
}
void Linkedlist::clear()
{
    Node * current = head;
    while (current != NULL){
        Node * temp = current -> next;
        delete current;
        current = temp;
    }
    head = NULL;
    tail = NULL;
    size = 0;
}
Linkedlist::reference Linkedlist::back()
{
    return tail->elem;
}
Linkedlist::const_reference Linkedlist::back() const
{
    return tail->elem;
}
Linkedlist::reference Linkedlist::front()
{
    return head->elem;
}
Linkedlist::const_reference Linkedlist::front() const
{
    return head->elem;
}
Linkedlist& Linkedlist::operator=(const Linkedlist& l)
{
    Node * current = l.head;
    if (this != &l){
        clear();
        while(current != NULL){
            push_back(current->elem);
            current = current -> next;
        }
    }
}
void Linkedlist::pop_back()
{
    if (tail != NULL){
        if (tail -> prev != NULL){
            tail = tail->prev;
	        tail->next = NULL;
	        size--;
        }
	    else{
	        clear();
	    }
    }
}
void Linkedlist::pop_front()
{
    if (head != NULL){
        if (head -> next != NULL){
            head = head->next;
	        head->prev = NULL;
	        size--;
        }
        else{
            clear();
        }
    }
}
void Linkedlist::push_back(const element_type& x)
{
    Node *new_tail = new Node();
    new_tail->elem = x;
    new_tail->next = NULL;
    if (head == NULL) {
	    head = new_tail;
    }
    if (tail != NULL){
	    tail->next = new_tail;
    }
    new_tail->prev = tail;
    tail = new_tail;
    size++;
}
void Linkedlist::push_front(const element_type& x)
{
    Node *new_head = new Node();
    new_head->elem = x;
    new_head->prev = NULL;
    if (tail == NULL) {
	    tail = new_head;
    }
    if (head != NULL) {
	    head->prev = new_head;
    }
    new_head->next = head;
    head = new_head;
    size++;
}
void Linkedlist::sort() 
{
    Node* current = head;
    if (current == NULL || current -> next == NULL){ 
        return; 
    }
    while (current->next != NULL){ 
        if (current->elem > current->next->elem){  
            int temp = current -> elem;
            current -> elem = current -> next -> elem;
            current -> next -> elem = temp;
        } 
        current = current->next; 
    } 
    int end = tail->elem;
    this->pop_back();
    sort();
    this->push_back(end);


}
Linkedlist::Linkedlist(unsigned int n)
{
    head = NULL;
    tail = head;
    size = 0;
    for(int i = 0; i < n; i++){
        push_back(i);
    }
}
void Linkedlist::check() const
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
    cout << "----------------------------------------------------------------------" << endl;
}
void Linkedlist::rcheck() const
{
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
    cout << "----------------------------------------------------------------------" << endl;
}
void Linkedlist::insert(unsigned int pos, const element_type& x)
{
    Node *current = head;
    for (int i = 1; i < pos && current != NULL; i++){
        current = current -> next;
    }
    if (current == NULL){
        push_back(x);
    }
    else if (pos == 0){
        push_front(x);
    }
    else{
        Node* add = new Node();
        add->elem = x;
        add->prev = current;
        add->next = current->next;
        current->next->prev = add;
        current->next = add;
        size++;
    }
}
void Linkedlist::erase(unsigned int pos)
{
    if (head == NULL){
	    return;
    }
    Node *current = head;
    for (int i = 0; i < pos && current != NULL; i++){
        current = current->next;
    }
    if (current == NULL){
        pop_back();
    } 
    else{
        if (current->next != NULL){
	    (current->next)->prev = current->prev;
        }
        if (current->prev != NULL){
	    (current->prev)->next = current->next;
        }
        size--;
    }
}