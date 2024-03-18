#include <iostream>
#include <string>
int main()
{
    int a = 0;
    float f = 0.1;
    double d = 0.2;
    char c = 'c';
    std::string s = "ssss";
    bool b = true;
    long l;
    long int li;
    long long int lli;

    std::cout << "int size : " << sizeof(int) << std::endl;
    std::cout << "float size : " << sizeof(float) << std::endl;
    std::cout << "double size : " << sizeof(double) << std::endl;
    std::cout << "char size : " << sizeof(char) << std::endl;
    std::cout << "string size : " << sizeof(std::string) << std::endl;
    std::cout << "bool size : " << sizeof(bool) << std::endl;
    std::cout << "long size : " << sizeof(long) << std::endl;
    std::cout << "long int size : " << sizeof(li) << std::endl;   
    std::cout << "long long int size : " << sizeof(lli) << std::endl;   

    std::cin.get();
    return 0;
}