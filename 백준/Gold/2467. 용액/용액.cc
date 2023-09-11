#include <iostream>
#include <vector> 
#include <algorithm> 
using namespace std;

vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    
    for (int i=0; i<N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    
    int left = 0, right = N-1;
    int minValue = 2147483647;
    
    pair<int, int> result;
    
    while (left < right) {
        int x = v[left];
        int y = v[right];
        
        int total = abs(x + y);
        
        if (total < minValue) {
            minValue = total;
            result = { x, y };
        }
        
        if (x + y < 0)
            left++;
        else
            right--;
    }
    
    cout << result.first << " " << result.second;
}