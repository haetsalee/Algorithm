#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    if (!N) {
        cout << 0;
        return 0;
    }

    int arr[N];
    
    for (int i=0; i<N; i++)
        cin >> arr[i];
        
    sort(arr, arr + N);
    
    int temp = round((float)(N * 3) / 20);

    int sum = 0;
    for (int i=temp; i + temp < N; i++)
        sum += arr[i];
        
    int reuslt = round((float)sum / (N - temp * 2));
    
    cout << reuslt;
}