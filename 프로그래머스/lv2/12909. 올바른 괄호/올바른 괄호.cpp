#include <string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> arr;
    
    for (int i=0; i<s.length(); i++) {
        if (s[i] == '(')
            arr.push('(');
        else {
            if (arr.empty()) 
                return false;
            else
                arr.pop();
        }
    }
    
    if (arr.empty())
        answer = true;
    else
        answer = false;

    return answer;
}