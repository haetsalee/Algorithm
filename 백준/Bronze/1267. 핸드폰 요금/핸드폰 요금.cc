#include <iostream>
using namespace std;
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	int N;
	cin >> N;
    
    int m = 0, y = 0;
	for (int i=0; i<N; i++) {
	    int temp;
		cin >> temp;
		y += (temp / 30 + 1) * 10;
		m += (temp / 60 + 1) * 15;
	}
	
	if (m < y)
	    cout << "M " << m;
	else if (m > y)
	    cout << "Y " << y;
	else if (m == y)
	    cout << "Y M " << m;
}