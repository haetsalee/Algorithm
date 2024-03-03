#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
	long long answer = 0;
	
	stack<int> dStack, pStack;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < deliveries[i]; j++) {
			dStack.push(i + 1);
		}
		for (int k = 0; k < pickups[i]; k++) {
			pStack.push(i + 1);
		}
	}
    
	int dMax, pMax;

	while (!dStack.empty() || !pStack.empty()) {
		dMax = pMax = 0;
        
        for (int i = 0; i < cap; i++) {
			if (!dStack.empty()) {
				if (i == 0) {
					dMax = dStack.top();
				}
				dStack.pop();
			}

			if (!pStack.empty()) {
				if (i == 0) {
					pMax = pStack.top();
				}
				pStack.pop();
			}
		}
        
		answer += max(dMax, pMax) * 2;
	}
	
	return answer;
}
