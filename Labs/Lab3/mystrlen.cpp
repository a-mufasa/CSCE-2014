#include <iostream>

size_t mystrlen(const char* a)
{
   const char* b = a;
   
   while(*b++ != 0); //null statement
   
   return b - a - 1;
}