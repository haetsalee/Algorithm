#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
bool check[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	check[1] = true;
	
	for (int i=2; i<=500000; i++) {
		for (int j=i * 2; j<=1000000; j+=i) {
			check[j] = true;
		}
	}
	for (int i = 2; i <= 1000000; i++) {
		if (!check[i])v.push_back(i);
	}
	
	int N;
	
	while (true) {
		cin >> N;
		if (N == 0) break;
		
		bool flag = false;
		
		for (int i=0; i<v.size() && v[i] < N; i++) {
			if (!check[N - v[i]]) {
				cout << N << " = " << v[i] << " + " << N - v[i]<<"\n";
				flag = true;
				break;
			}
		}
		
		if (!flag)
		    cout << "Goldbach's conjecture is wrong." << "\n";
	}
}