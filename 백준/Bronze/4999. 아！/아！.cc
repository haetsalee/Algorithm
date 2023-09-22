#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    
    if (str1.size() < str2.size())
        cout << "no";
    else
        cout << "go";
}