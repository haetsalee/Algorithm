#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int main()
{
    int num, total = 0;
    
    for (int i=0; i<5; i++) {
        cin >> num;
        total += num;
        v.push_back(num);
    }
    
    sort(v.begin(), v.end());
    cout << total / 5 << "\n" << v[2];
}