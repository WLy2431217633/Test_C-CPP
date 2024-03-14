#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string filepath = "1.txt";
    fstream f(filepath, ios::out | ios::trunc);
    if (!f.is_open()) {
        cerr << "Failed to open file for writing." << endl;
        return -1;
    }
    for(int i = 0; i < 100; i++)
    {
        if(i % 10 == 0 && i != 0)
        {
            f << endl;
            // cout << endl;
        }
        f << i << " ";
        // cout << i << " ";
    }
    f.close();
    cout << "File has been written successfully." << endl;
    system("pause");
    return 0;
}