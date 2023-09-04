#include <iostream>
#include <algorithm>
using namespace std;
 
int main()
{
	int N;
	cin >> N;
 
	while (1) {
		if (N == 1) {
			break;
		}
 
		for (int i=2; i<=N; i++) {
			if (N % i == 0) {
				cout << i << "\n";
				N /= i;
				break;
			}
		}
	}
}