#include <iostream>
#include <vector>
#include <string>

using namespace std;


void test(vector<string> msg, int i, int a)
{
    // 确保i在msg的有效索引范围内，包括末尾
    if (i < 0 || i > msg.size()) {
        std::cerr << "Index out of bounds" << std::endl;
        return;
    }

    // 将整数a转换为字符串
    std::string a_str = std::to_string(a);

    // 在索引i的位置插入字符串a
    msg.insert(msg.begin() + i, a_str);

    // 如果i不是末尾，手动移动元素
    if (i < msg.size() - 1) {
        for (int j = msg.size() - 1; j > i; --j) {
            std::swap(msg[j], msg[j - 1]); // 交换元素
        }
    }


    // 输出vector的内容
    for (const std::string &word : msg) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

}

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    msg.pop_back();
    string s = "python";
    msg.push_back(s);
    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
    int a = 10;
    if (true)
    {
        cout << "a = " << a << endl;
    }
    cout << endl;
    for (auto str : msg)
    {
        cout << str << " " ;
    }
    cout << msg.at(0) << endl;

    test(msg, 4, a);
    system("pause");
}
