#include <iostream>
using namespace std;

class printData
{
    public:
    void print(int n);
    void print(double d);

    friend void externalFunction(printData obj); // 访问私有

    int n;
    double d;
    char c;

    private:
    void print(char c);


};

void printData::print(int n)
{
    // cout << "print : " << n <<  endl;
    printf("print : %d\n", n);
}

void printData::print(double d)
{
    // cout << "print : " << d <<  endl;
    printf("print : %.3f\n", d);
}

void printData::print(char c)
{
    // cout << "print : " << d <<  endl;
    printf("print : %c\n", c);
}

void externalFunction(printData obj)
{
    obj.print(obj.c);
}


void print(int n)
{
    // cout << "print : " << n <<  endl;
    printf("print : %d\n", n);
}

void print(double d)
{
    // cout << "print : " << d <<  endl;
    printf("print : %.3f\n", d);
}

int main()
{
    int n = 1;
    print(n);

    double d = 1.1;
    print(d);

    printData pd;
    pd.n = 2;
    pd.d = 2.2;

    pd.print(pd.n);
    pd.print(pd.d);

    pd.c = 'c';
    externalFunction(pd);  // 传输对象调用
    
    pd.print(int(pd.c));  // 字符转ascii int数字


    cin.get();
    system("pause");
    return 0;

}