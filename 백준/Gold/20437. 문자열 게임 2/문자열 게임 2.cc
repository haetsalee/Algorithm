#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 987654321

int main()
{
    int N;
    cin >> N;
    
    while (N--) {
        string W;
        int K;
        
        cin >> W >> K;
        
        vector<int> v[26];
        int min_value = MAX;
        int max_value = 0;
        
        for (int i=0; i<W.size(); i++) {
            int idx = W[i] - 'a';
            v[idx].push_back(i);
        }
        
        for (int i=0; i<26; i++) {
            int cnt = v[i].size();
            
            if (cnt >= K) {
                for (int j=0; j<=cnt-K; j++) {
                    int dist = v[i][j+K-1] - v[i][j] + 1;
                    min_value = min(dist, min_value);
                    max_value = max(dist, max_value);
                }
            }
        }
        
        if (min_value == MAX || max_value == 0)
            cout << -1 << "\n";
        else
            cout << min_value << " " << max_value << "\n";
    }
    
}