#include <iostream>
#include <set>
using namespace std;

#define MOD 42
set<int> s;

int main()
{
    int N = 10;
    while (N--) {
        int num;
        cin >> num;
        
        s.insert(num % MOD);
    }
    
    cout << s.size();
    
    return 0;
}