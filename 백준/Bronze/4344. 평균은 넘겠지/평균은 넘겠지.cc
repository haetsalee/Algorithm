#include <iostream>
using namespace std;

int main() {
	int T, N, avg;
	int score[1000] = { 0, };
	double result;

	cin >> T;
	for (int i = 0; i < T; i++) {
		int total = 0;
		cin >> N;

		for (int j = 0; j < N; j++) {
			cin >> score[j];
			total += score[j];
		}
		
		avg = total / N;
	
	    double cnt = 0;
	    
		for (int j = 0; j < N; j++) {
			if (score[j] > avg)
				cnt++;
		}
		
		result = (cnt / N) * 100;

		cout << fixed;
		cout.precision(3);
		cout << result << "%" << "\n";
	}
}