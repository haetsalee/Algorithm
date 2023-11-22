#include <iostream>
#include <deque>
using namespace std;

deque<pair<int, int>> deq;

int main()
{
    int N;
    cin >> N;
    
    for (int i=1; i<=N; i++) {
        int num;
        cin >> num;
        deq.push_back({num, i});
    }
    
	while (!deq.empty()) {
		int now = deq.front().first;
		cout << deq.front().second << " ";
		deq.pop_front();

		if (deq.empty()) break;

		if (now > 0) {
			for (int i=0; i<now-1; i++) {
				deq.push_back(deq.front());
				deq.pop_front();
			}
		}
		
		else {
			for (int i=now; i<0; i++) {
				deq.push_front(deq.back());
				deq.pop_back();
			}
		}
	}
}