#include "Mystring.h"

    // === Given in Lab6

// default constructor
Mystring::Mystring() 
{
    ptr_buffer  = new char[1];
    *ptr_buffer = '\0';
    buf_size    = 1;
    len         = 0;
}

// constructor from c-style string or "abc"
Mystring::Mystring(const char * s) 
{
    len        = strlen(s);
    buf_size   = len + 1;
    ptr_buffer = new char[buf_size];
    strcpy(ptr_buffer, s);

}

// copy constructor to be implemented
Mystring::Mystring(const Mystring& orig) 
{
    len = orig.length();
    buf_size = len + 1;
    ptr_buffer = new char[buf_size];
    strcpy(ptr_buffer, orig.ptr_buffer);
}

// some simple methods implemented for you
 Mystring::size_type Mystring::size() const 
 {
     return len;
 }
 
 Mystring::size_type Mystring::length() const
 {
     return len;
 }
 
 Mystring::size_type Mystring::capacity() const
 {
       return buf_size;
 }
 
 Mystring::size_type Mystring::max_size() const
 {
       return (int)pow(2,30) -4 ;
 }
 
// Destructor
Mystring::~Mystring() 
{
    delete [] ptr_buffer;
}

// Provided for the lab so we may cout mystring
ostream& operator<<(ostream& out, const Mystring& str) 
{
    out << str.c_str();
    return out;
}

// implemented for the lab to support the implementation of <<
const char * Mystring::c_str() const 
{
    return ptr_buffer;
}

//#############################---MY IMPLEMENTATION---####################################

    //=== Memory Related ===
    
// reserve method
void Mystring::reserve(size_type n)
{
    if(buf_size >= n){
        return;
    }
    buf_size = n;
    char *temp = ptr_buffer;
    ptr_buffer = new char[buf_size];
    strcpy(ptr_buffer, temp);
    delete[] temp;
}

// empty boolean
bool Mystring::empty() const
{
    if(*ptr_buffer == '\0' && len == 0){
        return true;
    }
    return false;
}

    //=== Overloading operators ===

// Assignment operator
Mystring& Mystring::operator=(const Mystring& orig) //obj
{
    if (this != &orig){
        delete [] ptr_buffer;
        buf_size = orig.buf_size;
        ptr_buffer = new char[buf_size];
        len = orig.len;
        strcpy(ptr_buffer, orig.ptr_buffer);
    }
    
    return *this;
}

Mystring& Mystring::operator=(const char * orig) //ptr
{
    if (ptr_buffer != orig){
        delete [] ptr_buffer;
        len        = strlen(orig);
        buf_size   = len + 1;
        ptr_buffer = new char[buf_size];
        strcpy(ptr_buffer, orig);
    }
    
    return *this;
}

// Array notation
char Mystring::operator[](size_type pos) const 
{
    if (pos < 0 || pos >= len){
        cout << "Out of Range" << endl;
    }
    else{
        return ptr_buffer[pos];
    }
}

char& Mystring::operator[](size_type pos)
{
    if (pos < 0 || pos >= len){
        cout << "Out of Range" << endl;
    }
    else{
        return ptr_buffer[pos];
    }
}

// Append
Mystring& Mystring::operator+=(const Mystring& str) //obj
{
    len += str.len;
    reserve(len+1);
    strcat(ptr_buffer, str.ptr_buffer);
    return *this;
}

Mystring& Mystring::operator+=(const char * str) //ptr
{
    len += strlen(str);
    reserve(len+1);
    strcat(ptr_buffer, str);
    return *this;
}

    //=== Methods that modifiy the string

// Clear the contents
void Mystring::clear()
{
    delete[] ptr_buffer;
    len = 0;
    buf_size = 1;
    ptr_buffer = new char[buf_size];
    *ptr_buffer = '\0';
}

// Increase string by 1 and add a character
void Mystring::push_back(char c)
{
    ptr_buffer[len] = c;
    ptr_buffer[buf_size] = '\0';
    buf_size++;
    len++;
}

// Concatenate a string to the end
Mystring& Mystring::append(const Mystring& str) //obj
{
    len += str.len;
    reserve(len+1);
    strcat(ptr_buffer, str.ptr_buffer);
    return *this;
}

Mystring& Mystring::append(const char * str) //ptr
{
    len += strlen(str);
    reserve(len+1);
    strcat(ptr_buffer, str);
    return *this;
}

// Insert character into the string
Mystring& Mystring::insert(size_type pos, const Mystring& str) //obj
{
    if (pos > len){
        cout << "Out of Range" << endl;
    }
    else{
        len += str.len;
        reserve(len+1);
        Mystring temp = ptr_buffer + pos;
        strcpy(ptr_buffer + pos, str.c_str());
        strcat(ptr_buffer, temp.ptr_buffer);
        return *this;
    }
}

Mystring& Mystring::insert(size_type pos, const char * str) //ptr
{
    if (pos > len){
        cout << "Out of Range" << endl;
    }
    else{
        len += strlen(str);
        reserve(len+1);
        Mystring temp = ptr_buffer + pos;
        strcpy(ptr_buffer + pos, str);
        strcat(ptr_buffer, temp.ptr_buffer);
        return *this;    
    }
}

// replace characters in a string
Mystring& Mystring::replace(size_type start, size_type span, const Mystring& str) //obj
{
    if (start > len || start < 0){
        cout << "Out of Range" << endl;
    }
    else{
        reserve(len);
        Mystring temp = ptr_buffer + start + span;
        strcpy(ptr_buffer + start, str.ptr_buffer);
        append(temp);
        len = strlen(ptr_buffer);
        return *this;
    }
}

Mystring& Mystring::replace(size_type start, size_type span, const char * str) //ptr
{
    if (start > len || start < 0){
        cout << "Out of Range" << endl;
    }
    else{
        reserve(len);
        Mystring temp = ptr_buffer + start + span;
        strcpy(ptr_buffer + start, str);
        append(temp);
        len = strlen(ptr_buffer);
        return *this;
    }
}

    //=== Two new methods not in lab 6 header file

Mystring::size_type Mystring::find_first_of (const char* s, size_type pos, size_type n) const
{
    if (n+pos > strlen(s)){
        for (int i = pos; ptr_buffer[i] != '\0'; i++){
            for (int j = 0; j < strlen(s); j++){
                if(ptr_buffer[i] == s[j]){
                    return i;
                }
            }
        }
        return npos;
    }
    else{
        for (int i = pos; i < n+pos; i++){
            for (int j = 0; j < strlen(s); j++){
                if(ptr_buffer[i] == s[j]){
                    return i;
                }
            }
        }
        return npos;
    }
}

Mystring::size_type Mystring::find_last_not_of (const char* s, size_type pos) const
{
    for (int i = 0; ptr_buffer[i] != '\0' && i < pos; i++){
        for (int j = 0; s[j] != '\0'; j++){
            if(ptr_buffer[i] == s[j]){
                return i-1;
            }
        }
    }
    return npos;
}

    //=== Overloading global operators for Mystring

// Equality
bool operator==(const Mystring& left, const Mystring& right) //obj and obj
{
    if (strcmp(left.c_str(), right.c_str()) == 0)
        return true;
    else
        return false;
}

bool operator==(const char *left, const Mystring& right) //ptr and ptr
{
    if (strcmp(left, right.c_str()) == 0)
        return true;
    else
        return false;
}

bool operator==(const Mystring& left, const char *right) //ptr and obj
{
    if (strcmp(left.c_str(), right) == 0)
        return true;
    else
        return false;
}

// Inequality
bool operator!=(const Mystring& left, const Mystring& right) //obj and obj
{
    if (strcmp(left.c_str(), right.c_str()) != 0)
        return true;
    else
        return false;
}

bool operator!=(const char *left, const Mystring& right) //ptr and ptr
{
    if (strcmp(left, right.c_str()) != 0)
        return true;
    else
        return false;
}

bool operator!=(const Mystring& left, const char *right) //ptr and obj
{
    if (strcmp(left.c_str(), right) != 0)
        return true;
    else
        return false;
}

// Add two strings together
Mystring operator+(const Mystring& str1, const Mystring& str2) 
{
    Mystring temp(str1);
    temp.append(str2);
    return temp;
}