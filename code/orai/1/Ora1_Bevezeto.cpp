#include <iostream>

using namespace std;

void beolvas(int *x, int *y)
{
    cin >> *x >> *y;
}

void beolvas(int &x, int &y)
{
    cin >> x >> y;
}

void kiirIdozejelesen(const string &s)
{
    cout << "\"" << s << "\"";
}

int main()
{
    // int a=54;
    // double valami = 302.34332;
    // //cout << "Hello World: " << a << " " << valami << endl;
    // // cout << "Hello World: " << a;
    // // cout << " " << valami << endl;
    // cout << "Hello World: " << a
    //      << " " << valami << endl;
    // cin >> a >> valami;
    // cout << a << " " << valami << endl;

    // int tomb[10];
    // for (int i=0; i<10; i++)
    //     cin >> tomb[i];
    // for (int i=0; i<10; i++)
    // {
    //     cout << (i+1) << ". elem: " << tomb[i] << endl;
    // }

    // string varosnev;
    // cin >> varosnev;
    // cout << varosnev << endl;
    // // getline(cin, varosnev);
    // // cout << varosnev << endl;

    // bool logikai;
    // logikai = true;
    // logikai = false;
    // cout << logikai << endl;
    // if (logikai) // if (logikai==true)
    // {
    //     //...
    // }
    // if (!logikai) // if (logikai==false)
    // {
    //     //...
    // }

    int a = 5; // változó
    int *p = &a; // mutató
    int &r = a; // referencia
    int b = 9;

    cout << a << endl;
    cout << *p << endl;
    cout << r << endl;
    cout << endl;
    cout << &a << endl;
    cout << p << endl;
    cout << &p << endl;
    cout << &r << endl;

    *p = b;
    p = &b;
    r = b; // a = b;

    //beolvas(&a, &b);
    beolvas(a, b);
    cout << a << " " << b << endl;

    //int &r2 = fvg();


    const double d = 5.6;
    // //d= 5.67;
    // {
    //     const int &aref = a;
    //     aref = 2;
    // }

    // const int *pc = &a;
    // *pc = 5;
    // pc = &b;
    // int * const pc2 = &a;
    // *pc2 = 453;
    // pc2 = &b;

    const double *pd = &d;
    const double &rd = d;




    return 0;
}
