#include <bits/stdc++.h>
using namespace std;

stack<int> s;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N, num;
	cin >> N;
	
	int cnt = 1;
	while (N--) {
		cin >> num;
		
		if (num == cnt)
		    cnt++;
		else
		    s.push(num);
		
		while(!s.empty() && s.top() == cnt) {
			s.pop();
			cnt++;
		}
	}
	
	if (s.empty())
	    cout << "Nice";
	else
	    cout << "Sad";
}