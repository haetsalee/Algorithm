#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    
    while (N--) {
        string str;
        cin >> str;
        
        list<char> arr;
        auto now = arr.begin();
        
        for (auto i:str) {
            if (i == '<') {
                if (now != arr.begin())
                    now--;
            }
            
            else if (i == '>') {
                if (now != arr.end())
                    now++;
            }
            
            else if (i == '-') {
                if (now != arr.begin()) {
                    now--;
                    now = arr.erase(now);                    
                }
            }
            
            else
                arr.insert(now, i);
        }
        
        for (auto i:arr)
            cout << i;
        cout << "\n";
    }
}