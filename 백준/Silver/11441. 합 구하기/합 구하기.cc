#include <iostream>
using namespace std;

int arr[100001];

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
	int N, M;
	cin >> N;
	
	for (int i=1; i<=N; i++) {
		int num;
		cin >> num;
		arr[i] = arr[i-1] + num;
	}

    cin >> M;
	for (int i=0; i < M; i++) {
		int x, y;
        cin >> x >> y;
		cout << arr[y] - arr[x-1] << "\n";
	}

	return 0;
}