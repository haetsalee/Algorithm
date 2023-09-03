#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int N, K;
vector<int> v;
set<string> s;

int main()
{
    cin >> N >> K;
    
    for (int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    
    sort(v.begin(), v.end());
    
    do {
        string str;
        for (int i=0; i<K; i++) {
            str += to_string(v[i]);
        }
        s.insert(str);
    } while (next_permutation(v.begin(), v.end()));
    
    cout << s.size();
}