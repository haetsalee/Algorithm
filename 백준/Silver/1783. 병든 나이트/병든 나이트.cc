#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	
	if (N == 1) 
	    cout << 1;
	
	else if (N == 2) 
		cout << min(4, (M+1) / 2);
	
	else if (M <= 6)
		cout << min(4, M);
	
	else
		cout << M - 2;
}