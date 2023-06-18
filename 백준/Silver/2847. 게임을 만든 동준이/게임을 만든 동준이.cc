#include <iostream>
using namespace std;

int main()
{
    int N;
	cin >> N;

    int arr[101] = { 0, };
	for (int i=0; i<N; i++) {
		cin >> arr[i];
	}

    int cnt = 0;
	for (int i=N-1; i>=1; i--) {
		while (arr[i] <= arr[i-1]) {
			arr[i-1]--;
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}