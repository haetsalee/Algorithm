#include <iostream>
using namespace std;

int N, M;
string name[100001];
int power[100001];

int binarySearch (int p) {
    int mid = 0, left = 0, right = N-1;
    
    while (left <= right) {
        mid = (left + right) / 2;
        
        if(p <= power[mid])
            right = mid-1;
        else
            left = mid+1;
    }
    
    if (p > power[mid])
        return mid+1;
    else
        return mid;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    
    for(int i=0; i<N; i++)
        cin >> name[i] >> power[i];
        
    for(int i=0; i<M; i++) {
        int p;
        cin >> p;
        cout << name[binarySearch(p)] << "\n";
    }
}