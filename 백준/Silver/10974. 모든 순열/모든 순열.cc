#include <iostream>
using namespace std;

int N;
int num[9] = { 0, };
int visited[9] = { 0, };

void perm(int now) 
{
	if (now == N) {
		for (int i = 0; i < N; i++) {
			cout << num[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i] == 1) continue;
		
		visited[i] = true;
		num[now] = i + 1;
		perm(now + 1);
		visited[i] = 0;
	}
}

int main() {
	cin >> N;
	perm(0);
}