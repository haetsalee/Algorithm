#include<iostream>
#include <algorithm>
using namespace std;

int arr[100001] = {0, };

int main()
{
	int N, num;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	
	sort(arr, arr+N);
	
	cin >> num;
	
	int left = 0;
	int right = N-1;
	int cnt = 0;

	while(left < right) {
	    if (arr[left] + arr[right] == num) {
	        cnt++;
	        right--;
	    }
	        
	    else if (arr[left] + arr[right] > num)
	        right--;
	        
	    else
	        left++;
	}

	cout << cnt;

	return 0;
}