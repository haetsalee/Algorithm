#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100001

int arr[MAX];
    
bool check(int x, int y){
    return x > y;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    
    sort(arr, arr+N, check);
 
    int total = 0;
 
    for (int i=0; i<MAX; i++) {
        if (i % 3 != 2)
            total += arr[i];
    }
 
    cout << total;
}