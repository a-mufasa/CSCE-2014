bool is_char_in_the_set(char c, const char *set) //return True if char c is in the set, else return False
{
    bool in_set = false;
    int k = 0;
    
    for (int i = 0; *(i + set) != '\0'; i++){
        if (*(i + set) == c){ //*(i+set) is the same as set[i]
           in_set = true;
        }
        k++;
   }
    if(*(k + set) == c){
        in_set = true;
    }
    return in_set;
}

char *find_first_not_in_the_set(char *str, const char *set) //return address of first character in str that does not appear in set
{
    for (int i = 0; *(i + str) != '\0'; i++){
        if (!is_char_in_the_set(*(i+str), set)){ //*(i+str) is the same as str[i]
            return (i+str);
        }
    }
   return nullptr;
}

char *find_first_in_the_set(char *str, const char *set) //return address of first character in str that appears in set
{
    for (int i = 0; *(i + str) != '\0'; i++){
        if (is_char_in_the_set(*(i+str), set)){ //*(i+str) is the same as str[i]
            return (i+str);
        }
    }
  return nullptr;
}
