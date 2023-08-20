#include<iostream>
#include<algorithm>
using namespace std;

int arr[1001] = {0, };
	
int main(void)
{
	int N;
	cin >> N;
	for (int i=0; i<N; i++)
		cin >> arr[i];

	sort(arr, arr + N);
	
	int total = 0;
	for (int i=0; i<N; i++) {
		arr[i+1] += arr[i];
		total += arr[i];
	}
	
	cout << total;
}