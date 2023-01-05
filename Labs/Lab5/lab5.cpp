#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void check (const string& s, const string& name)
{
    cout << "checking " << name << endl;
    cout << name << " contains " << s << endl;
    cout << name << " capacity() is " << s.capacity() << endl;
    cout << name << " length() is " << s.length() << endl;
    cout << name << " size() is " << s.size() << endl;
    cout << name << " max_size() is " << s.max_size() << "\n" << endl;
}

int main()
{
    //Step 1
    string s0, s2;

    //Step 2
    if (s0.empty()){
        cout << "s0 is empty\n" << endl;
    }
    else{
        cout << "s0 is not empty\n" << endl;
    }

    //Step 3
    string s1("Hello, World!");

    //Step 4
    s2 = s1;

    //Step 5
    s2.push_back('!');
    check(s2, "s2");

    //Step 6
    s1 += s2;
    check(s1, "s1");

    //Step 7
    s1.insert(13, " ");
    check(s1, "s1");

    //Step 8
    s0 = s1 + " " + s2;
    check(s0, "s0");
    
    //Step 9
    s0.reserve(50);
    check(s0, "s0");
    
    //Step 10
    char c = s0[12];
    cout << "c = " << c << endl;
    check(s0, "s0");
    
    //Step 11
    s2.append(s2);
    check(s2, "s2");
    
    //Step 12
    s2.replace(12, 1, "=");
    check(s2, "s2");
    
    //Step 13
    const char * p;
    p = s2.c_str();
    cout << "p = " << p << endl;
    check(p, "p");
    
    //Step 14
    if (p == s2){
        cout << "p is the same as s2" << endl;
    }
    else{
        cout << "p is not the same as 2" << endl;
    }
    check(p, "p");
    check(s2, "s2");
    
    //Step 15
    s2[12] = s0[12];
    check(s2, "s2");
    
    //Step 16
    s0.clear();
    check(s0, "s0");
    
    //Step 17
    s2.clear();
    check(s2, "s2");
    
    //Step 18
    cout << "p = " << p;
    check(p, "p");

    return 0;
}
