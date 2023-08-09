#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int H, W;
    cin >> H >> W;
    
    for (int i=0; i<W; i++) {
        int height;
        cin >> height;
        v.push_back(height);
    }

    int cnt = 0;
    
    for(int i=1; i<v.size()-1; i++){
        int l=0, r=0;
        
        for(int j=i-1; j>=0 ; j--)
            l = max(l, v[j]);
        
        for(int j=i+1; j<v.size(); j++)
            r = max(r, v[j]);
        
        int mid = min(l, r) - v[i];
        
        if (mid >= 0)
            cnt += mid;
    }
    
    cout << cnt;
}