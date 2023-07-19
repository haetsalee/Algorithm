#include <iostream>
#include <algorithm>
using namespace std;

long long arr[1000000] = {0, };

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
	
	int N;
	cin >> N;
	for (int i=0; i<N; i++) {
	    cin >> arr[i];
	}
		
	sort(arr, arr + N);

	int cnt = 1, idx = 0, maxValue = 0;
	
	for (int i=0; i<N-1; i++) {
		if (arr[i] == arr[i + 1]) {
			cnt++;
			
			if (cnt > maxValue) {
				maxValue = cnt;
				idx = i;
			}
		}
		else
			cnt = 1;
	}
	cout << arr[idx] << "\n";	
}