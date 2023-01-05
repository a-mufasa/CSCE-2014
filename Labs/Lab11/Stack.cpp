#include "Stack.h"
using namespace std;

Stack::Stack()
{
    buffer = new int[100];
    numElements = 0;
    topIndex = -1;
}
Stack::~Stack()
{
    delete[] buffer;
}
bool Stack::empty() const
{
    return numElements == 0;
}
unsigned int Stack::size() const
{
    return numElements;
}
int& Stack::top()
{
    return buffer[topIndex];
}
const int& Stack::top() const
{
    return buffer[topIndex];
}
void Stack::push(const int& x) //Implement
{
    numElements++;
    topIndex++;
    buffer[topIndex] = x;
}
void Stack::pop() //Implement
{
    numElements--;
    topIndex--;
}
void Stack::print()
{
    cout << "[ ";
    for (int i = 0; i < numElements; ++i){
        cout << buffer[i] << " ";
    }
    cout << "]" << endl;
}
