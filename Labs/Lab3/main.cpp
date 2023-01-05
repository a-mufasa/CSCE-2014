#include <iostream>
#include <cstring>
#include "mystrlen.h"
#include "mystrcat.h"
using namespace std;

int main()
{
    char line[] = "ls -l -a | wc -c >> myfile";
    size_t len;

    len = strlen(line);
    cout << "The length is " << len << endl;

    char* strArray[10];
    char temp[] = {'\0'};
    for (int i = 0; i < 10; i++)
    {
        strArray[i] = &temp[0];
    }

    int pieces = 0;
    char* ptr;
    ptr = strtok(line, " ");

    while (ptr != NULL) 
    {
        strArray[pieces] = ptr;
        ptr = strtok(NULL, " ");
        cout << "strArray" << pieces << " = " << strArray[pieces] << endl;
        pieces++;
    }

    size_t size = 0;
    for (int i = 0; i < pieces; i++)
    {
        size += strlen(strArray[i]);
    }

    cout << "The size is " << size << endl;

    size_t numBlanks = len - size;
    cout << "numBlanks = " << numBlanks << endl;

    char* result = new char[size+1];
    result[0] = '\0';

    for (int i = 0; i < pieces; i++)
    {
        strcat(result, strArray[i]);
    }

    cout << "The concatenation of all strings in strArray is: " << result << endl;
    delete[] result;

    return 0;
}