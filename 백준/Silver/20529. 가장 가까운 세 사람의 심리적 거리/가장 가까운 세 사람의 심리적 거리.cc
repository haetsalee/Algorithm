#include <iostream>
#include <vector>
using namespace std;

int solve(string a, string b) {
	int distance = 0;
	for (int i=0; i<4; i++) {
		if (a[i] != b[i])
			distance++;
	}
	
	return distance;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	
	while (T--) {
		vector<string> v;
		int N;
		cin >> N;
		for (int i=0; i<N; i++) {
			string mbti;
			cin >> mbti;
			v.push_back(mbti);
		}
		
		if (N > 32) 
			cout << 0 << "\n";
		
		else {
			int result = 987654321;
			for (int i=0; i<N - 2; i++) {
				for (int j=i + 1; j<N - 1; j++) {
					for (int k=j + 1; k<N; k++)
						result = min(result, solve(v[i], v[j]) + solve(v[j], v[k]) + solve(v[i], v[k]));
				}
			}
			
			cout << result << "\n"; 
		}
	}
}