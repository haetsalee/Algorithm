#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

	int N, K;
	cin >> N >> K;
	int a[10001];
	int cnt = 0;
	
	for (int i = 2; i <= N; i++) {
		a[i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 1; i * j <= N; j++) {
			if (a[i * j] == 1) {
				a[i * j] = 0;
				cnt++;
				
				if (cnt == K) {
					cout << i * j << "\n";
					return 0;
				}
			}
		}
	}
}