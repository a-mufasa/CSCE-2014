/*****************

Lab 09 Code
CSCE 2014
Ahmed Moustafa

******************/

#include <stdio.h>
#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 1){
        return 1;
    }
    return n*factorial(n-1);
}

int fibonacci(int n)
{
    if (n == 0 || n == 1){
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

void sort (int * seq, int size)
{
    if (size == 0 || size == 1) {
        return;
    }
    
    int smallest = seq[0];
    int a = 0;
    
    for (int i = 1; i < size; i++){
        if (seq[i] < smallest){
            smallest = seq[i];
            a = i;
        }
    }
    
    seq[a] = seq[0];
    seq[0] = smallest;
    
    sort(seq+1, size-1);
}

void display(int * seq, int size)
{
    for (int i = 0; i < size; i++){
        if (i == size-1)
            cout << seq[i];
        else
            cout << seq[i] << ",";
    }
    cout << endl;
}

int main()
{
    cout << "Testing Factorial:" << endl; //Factorial Function
    
    cout << factorial(5) << endl << endl; //5
    cout << factorial(9) << endl << endl; //9
    
    
    cout << "Testing Fibonacci:" << endl; //Fibonacci Function
    
    for (int i = 0; i < 5; i++){ //5
        cout << fibonacci(i) << endl;
    } 
    cout << endl;
    
    for (int i = 0; i < 12; i++){ //12
        cout << fibonacci(i) << endl;
    } 
    cout << endl;
    
    cout << "Testing Sort and Display:" << endl; //Sort + Display Function
    
    int seq1[] = {144, 25, 21, 69, 17};
    sort(seq1, 5);
    display(seq1, 5);
    cout << endl;
    
    int seq2[] = {1337};
    sort(seq2, 1);
    display(seq2, 1);
    cout << endl;
    
    int seq3[] = {};
    sort(seq3, 0);
    display(seq3, 0);
    cout << endl;

    return 0;
}

