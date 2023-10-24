#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    stack<char> left;
    stack<char> right;
    
    string str = "";
    cin >> str;

    for (int i=0; i<str.size(); i++) 
        left.push(str[i]);
    
    int num;
    cin >> num;
    
    while (num--) {
        char temp;
        cin >> temp;
        
        if (temp == 'P') {
            char c;
            cin >> c;
            left.push(c);
        }
        
        else if (temp == 'L') {
            if (left.empty())
                continue;
            else {
                right.push(left.top());
                left.pop();
            }
        }
        
        else if (temp == 'B') {
            if (left.empty())
                continue;
            else
                left.pop();
        }
        
        else if (temp == 'D') {
            if (right.empty())
                continue;
            else {
                left.push(right.top());
                right.pop();
            }
        }
    }
    
    while (!left.empty()) {
        right.push(left.top());
        left.pop();
    }
    
    while (!right.empty()) {
        cout << right.top();
        right.pop();
    }
}