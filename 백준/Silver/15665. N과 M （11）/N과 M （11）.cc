#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> v;
int arr[10];

void dfs(int cnt)
{
	if (cnt == M) {
		for (int i=0; i<M; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	
	int temp = -1;

	for (int i=0; i<N; i++) {
		if(temp == v[i]) continue;
		
		temp = v[i];
		arr[cnt] = v[i];
		dfs(cnt + 1);
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
	    int num;
	    cin >> num;
		v.push_back(num);
	}
    
	sort(v.begin(), v.end());
    
	dfs(0);
}
