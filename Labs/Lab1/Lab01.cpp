// Lab One

#include <iostream>

#include <string>



using namespace std;



void f(int x[]) 

{

    for (int i = 0; i < 5; i++)

        x[i] = 2 * (i + 1);

}



void g(int* y)

{

    for (int i = 0; i < 5; i++)

        y[i] = 2 * i + 1;

}



void show(int x[])

{

    int y = 0;

    while (y < 5)

    {

        cout << x[y] << " ";

        y++;

    }

    cout<< endl;

}



void print(int* y)

{

    int x = 0;

    while (x < 5)

    {

        cout << y[x] << " ";

        x++;

    }

    cout<< endl;

}



int main()

{

    string name;

    cout << "What is your name? ";

    getline (cin, name);

    cout << "Hello, " << name << "!\n";



    int a[5];

    int b[6];

    int* p;

    int x;



    f(a);

    g(b);

    show(a);

    print(b);



    p = a;

    //b = p; 

    g(p);

    //g(x);

    //g(a[0]);

    show(a);



    for (int i = 0; i < 5; i++)

    {

        int tmp = 0;

        for(int k = 0; k <= i; k++)

            tmp = tmp + a[k];

        a[i] = tmp;

    }



    show(a);

    return 0;

}