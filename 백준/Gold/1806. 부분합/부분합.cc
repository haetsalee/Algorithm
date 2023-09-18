#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int main()
{
    int N, S;
    cin >> N >> S;
    
    for (int i=0; i<N; i++) {
        cin >> arr[i];
    }
    
    int start = 0, end = 0, total = arr[0];
    int result = 987654321;
    
    while (start <= end && end <= N) {
        if (total >= S)
            result = min(result, (end-start+1));
        
        if (total < S) {
            end++;
            total += arr[end];
        }
        
        else {
            total -= arr[start];
            start++;
        }
    }
    
    if (result == 987654321)
        cout << "0";
        
    else
        cout << result;
}
