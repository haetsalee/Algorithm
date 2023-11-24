#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[10001];

int binarySearch (int end) {
    int start = 0, mid = 0, total = 0;
    
    while (start <= end) {
        total = 0;
        mid = (start + end) / 2;
        
        for (int i=0; i<N; i++) {
            if (arr[i] < mid)
                total += arr[i];
            else
                total += mid;
        }
        
        if (total <= M)
            start = mid + 1;
        else
            end = mid - 1;
    }
    
    return end;
}

int main() {
    cin >> N;
    
    for(int i=0; i<N; i++) 
        cin >> arr[i];
    
    cin >> M;

    sort(arr, arr + N);
    
    cout << binarySearch(arr[N-1]);
}