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
void Reference(double d)
{
    // declaration some simple variable
    int i;


    // declaration some reference variable
    int &ii = i;
    double &dd = d;

    i = 5;
    cout << "Reference Value of i = " << i << endl;
    cout << "Reference Value of i reference = " << ii << endl;

    d = 0.5;
    cout << "Reference Value of d = " << d << endl;
    cout << "Reference Value of d reference = " << dd << endl;

}

void Reference2(double &dd)
{
    double d = 0.5;
    dd = d;
    cout << "Reference2 Value of d = " << d << endl;
    cout << "Reference2 Value of d reference = " << dd << endl;
}

int main()
{
    double dd;
    Point();

    Reference2(dd);
    cout << "main Value of d reference = " << dd << endl;
    Reference(dd);
    cout << "main Value of d reference = " << dd << endl;
    system("pause");
    return 0;
}