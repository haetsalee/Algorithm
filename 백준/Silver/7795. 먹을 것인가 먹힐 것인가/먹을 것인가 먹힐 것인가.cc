#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int T;
    cin >> T;
 
    for(int i=0; i<T; i++) {
        int N, M;
        cin >> N >> M;
 
        vector<int> v1(N);
        vector<int> v2(M);
 
        for(int x=0; x<N; x++)
            cin >> v1[x];
        for(int x=0; x<M; x++)
            cin >> v2[x];
        
        int cnt = 0;
 
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
 
        for(int j=0; j<N; j++) {
            for(int k=0; k<M; k++) {
                if(v1[j] > v2[k])
                    cnt++;
                else break;
            }
        }
        cout << cnt << "\n";
    }
}