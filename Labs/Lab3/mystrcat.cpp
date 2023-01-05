#include <iostream>

char* mystrcat(char* dest, const char* src)
{
    int a,b;

	for (a = 0; dest[a] != '\0'; a++); //find null character in dest
    
    b=0;
	while (src[b] != '\0' )
	{
	    dest[a] = src[b]; //copy 1st src to location a
	    a++; 
	    b++; 
	}

	dest[a] = '\0'; //terminates at null character

	return dest;
}