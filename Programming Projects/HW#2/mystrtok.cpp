#include "mystrtok.h"

char *mystrtok(char *str, const char *delim)
{
    static char* prev_token; //static char pointer holds the previous location so we can call mystrtok more than once
    
    //if str IS null, the prev_token would be maintained from last iteration
    if (str != nullptr){
        prev_token = str;
    }
    
    if (prev_token == '\0'){
        return nullptr;
    }
    
    char* start = find_first_not_in_the_set(prev_token, delim); //start location of toekn
    
    if (start == nullptr){
        return nullptr;
    }
    
    char* end = find_first_in_the_set(start, delim); //end location of token
   
    if (end != nullptr){
        *end = '\0'; //replace delimiter with null character
        prev_token = end + 1; //move forward one in the static placeholder
    }
    else{
        prev_token = end; //if end is null, placeholder set to the end of token
    }
    
    return start;
}
