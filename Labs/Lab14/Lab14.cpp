#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

size_t find_char_val(char c)
{
    if (c >= 48 && c <= 57){ //0-9
        return c-48;
    }
    if (c >= 65 && c <= 90){ //A-Z
        return c-55;
    }
    if (c >= 97 && c <= 122){ //a-z
        return c-61;
    }
    if (c == 45){ //_
        return 62;
    }
    if (c == 95){
        return 63;
    }
    return -1;
}

size_t dmHash(string key, size_t tableSize)
{
    size_t len = key.length();
    size_t x = 64;
    size_t value = 0;
    
    for (size_t i = 0; i < len; i++){
        value = ((value*x) + find_char_val(key.at(i))) % tableSize;
    }
    return value;
}

size_t mmHash(string key, size_t tableSize)
{
    size_t len = key.length();
    unsigned int n = 0;
    
    for (size_t i = 0; i < len; i++){
        n = (n*64) + find_char_val(key.at(i));
    }
    
    double d = n * 0.61803398875;
    double f = d - (unsigned int)d;
    int index = f * tableSize;
    return index;
}

string randomKey(unsigned int min, unsigned int max)
{
    const int SIZE = 64;
    const char alphabet[SIZE]={'0','1','2','3','4','5','6','7','8','9',
    'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p',
    'q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G',
    'H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X',
    'Y','Z','-','_'};
 
    // simple error handling
    if (min == 0)
        min = 1;
    if (max < min)
        max = min;
 
    // pick a length between min and max
    int lenRange = max - min + 1;    
    int len      = rand() % lenRange;
    len          = len + min;
 
    // len is one of min, min+1,...max
    string s;
    for (int i = 0; i < len; i++)
        s.push_back(alphabet[rand() % SIZE]);
    
    return s;
}

bool search(string s, string a[], int size) 
{
    int i = 0;
    while (i < size && a[i] != s) {
        i++;
    }
    return (i == size);
}

int main()
{
    //cout << dmHash("a9B34uvwXYZ1234500", 103981) << endl; // prints 40643. 
    //cout << mmHash("a9B34uvwXYZ1234500", 103981) << endl; // prints 90101. 
    //cout << dmHash("zyxwvutsrqpo", 103981) << endl; // prints 79631. 
    //cout << mmHash("zyxwvutsrqpo", 103981) << endl; // prints 53532. 
    
    int a = 50000;
    string s[a];
    for (int i = 0; i < a; i++) {
        string temp = randomKey(12,12);
        if (search(temp, s, a)){
            s[i] = temp;   
        }
        else{
            i--;
        }
    }
    int Dhash_arr[103981] = { };
    int Mhash_arr[103981] = { };
    
    for (int i = 0; i < a; i++){
        Dhash_arr[dmHash(s[i], 103981)]++;
        Mhash_arr[mmHash(s[i], 103981)]++;
    }
    
    int Dhash_count = 0;
    int Mhash_count = 0;
    int Dcollision_count = 0;
    int Dkey_collisions = 0;
    int Mcollision_count = 0;
    int Mkey_collisions = 0;
    int D_max_len = 0;
    int M_max_len = 0;
    
    for (int i = 0; i < 103981; i++){
        if (Dhash_arr[i] == 1){ //checks hash array positions to see if a key is hashed
            Dhash_count++;
        }
        if (Mhash_arr[i] == 1){ //checks hash array positions to see if a key is hashed
            Mhash_count++;
        }
        if (Dhash_arr[i] > 1){ //checks hash array positions to see if there is a collision (more than one key with the same hash)
            Dcollision_count++;
            Dkey_collisions += Dhash_arr[i];
        }
        if (Mhash_arr[i] > 1){ //checks hash array positions to see if there is a collision (more than one key with the same hash)
            Mcollision_count++;
            Mkey_collisions += Mhash_arr[i];
        }
        if (Dhash_arr[i] > D_max_len){
            D_max_len = Dhash_arr[i];
        }
        if (Mhash_arr[i] > M_max_len){
            M_max_len = Mhash_arr[i];
        }
    }
    cout << "Number of DM hash indexes with a key: " << Dhash_count << endl;
    cout << "Number of MM hash indexes with a key: " << Mhash_count << endl;
    cout << "Number of keys resulting in collisions (DM): " << Dkey_collisions << endl;
    cout << "Number of keys resulting in collisions (MM): " << Mkey_collisions << endl;
    cout << "Number of collisions (DM): " << Dcollision_count << endl;
    cout << "Number of collisions (MM): " << Mcollision_count << endl;
    cout << "Max length of linked list for DM: " << D_max_len << endl;
    cout << "Max length of linked list for MM: " << M_max_len << endl;
    
    return 0;
}

