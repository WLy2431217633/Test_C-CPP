#include <iostream>
using namespace std;

// About Point
void Point()
{
    int *p;
    int var = 20;
    cout << "var = " << var << endl;
    cout << "p = " << p << endl;
    // cout << "p = " << *p << endl;
    p = &var;
    cout << "after var's address in p address = " << p << endl;
    cout << "after var's address in p variable = " << *p << endl;    

}

// we can think it is a Nickname
void Reference()
{
    // declaration some simple variable
    int i;
    double d;

    // declaration some reference variable
    int &ii = i;
    double &dd = d;

    i = 5;
    cout << "Value of i = " << i << endl;
    cout << "Value of i reference = " << ii << endl;

    d = 0.5;
    cout << "Value of d = " << d << endl;
    cout << "Value of d reference = " << dd << endl;

}

int main()
{
    Point();
    Reference();
    system("pause");
    return 0;
}