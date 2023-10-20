#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;

    for (int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    
    sort(v.begin(), v.end());
    
    int total = 1;
    for (int i=0; i<N; i++) {
        if (v[i] > total)
            break;
            
        total += v[i];
    }
    
    cout << total;
} 