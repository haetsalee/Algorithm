#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
    int N, M;
    cin >> N >> M;
    
    int arr[150001] = {0, };
    
    for (int i=0; i<N; i++) {
        cin >> arr[i];
    }
    
    int cnt = 0;
    
    if (M > 200000)
        cout << 0;
    else {
        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                if (arr[i] + arr[j] == M)
                    cnt++;
            }
        }
        cout << cnt;
    }
}