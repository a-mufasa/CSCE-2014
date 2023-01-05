#include <iostream>
#include "Stack.h"
#include "Queue.h"
using namespace std;

int main()
{
    Stack<double> stack;
    
    for (double i = 0; i < 8; ++i){
        stack.push(i/100);
    }
    
    while (!stack.empty()){
        cout << "Stack contains: ";
        stack.print();
        cout << "Stack size: " << stack.size() << endl;
        cout << "Top: " << stack.top() << endl << endl; 
        stack.pop();
    }
    
    Queue<double> queue;
     
    for (double i = 0; i < 10; ++i){
        queue.push(i/100);
    }
    
    while (!queue.empty()){
        cout << "Queue contains: ";
        queue.print();
        cout << "Queue size: " << queue.size() << endl;
        cout << "Front: " << queue.front() << endl << endl; 
        queue.pop();
    }
}