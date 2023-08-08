#include <iostream>
using namespace std;

int N, num;
int arr[21] = {0, };
int cnt;

void dfs(int now, int total) {
    if (now == N)
        return;
    
    if (total+arr[now] == num)
        cnt++;
    
    dfs(now + 1, total);
    dfs(now + 1, total + arr[now]);
}

int main() {
	cin >> N >> num;
	for (int i=0; i<N; i++) {
		cin >> arr[i];
	}
    
	dfs(0, 0);
    
	cout << cnt;
}