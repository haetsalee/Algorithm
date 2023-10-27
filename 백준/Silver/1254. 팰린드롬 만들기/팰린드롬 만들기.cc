#include <iostream>
using namespace std;

bool check (string s) {
    int cnt = s.size()/2;
    for (int i=0; i<cnt; i++) {
        if (s[i] != s[s.size() -1 - i])
            return false;
    }
    
    return true;
}

int main()
{
    string str;
    cin >> str;
    
    int result = 0;
    result = str.size()*2 - 1;
    
    for (int i=0; i<str.size(); i++) {
        string temp = str.substr(i, str.size()-i);
        if (check(temp)) {
            result = str.size() + i;
            break;
        }
    }
    
    cout << result << "\n";
}