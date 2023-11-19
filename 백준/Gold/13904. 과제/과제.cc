#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1001];
vector<pair<int, int>> v;

int main() 
{
	int N;
	cin >> N;

	for (int i=0; i<N; i++) {
	    int days, score;
		cin >> days >> score;
		v.push_back({ score, days });
	}

	sort(v.begin(), v.end(), greater<pair<int, int>>());
	
	memset(arr, 0, sizeof(arr));

	for (int i=0; i<N; i++) {
		int end = v[i].second;
		while (end >= 1) {
			if (arr[end] == 0) {
				arr[end] = v[i].first;
				break;
			}
			
			else end--;
		}
	}
	
    int result = 0;
	for (int i=1; i<=1000; i++)
		result += arr[i];

	cout << result << "\n";
}