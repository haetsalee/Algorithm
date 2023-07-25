#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int binary_search(int x, int n, vector<int> &v){
    int l = 0;
    int r = n-1;
    int flag = 0;
    
    while(l <= r) {
        int mid = (l+r)/2;
        if(v[mid] > x)
            r = mid - 1;
        else if(v[mid] < x)
            l = mid + 1;
        else {
            flag = 1;
            break;
        }
    }
    
    return flag;
}

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0);
    
    int T;
    cin >> T; 
    for (int i=0; i<T; i++) {
        int N, M, temp;
        vector <int> v;
        
        cin >> N;
        for(int i=0; i<N; i++) {
            cin >> temp;
            v.push_back(temp);
        }
        sort(v.begin(), v.end());
        
        cin >> M;
        
        for(int i=0; i<M; i++){
            cin >> temp;
            cout << binary_search(temp, N, v) << "\n";
        }
    }
}