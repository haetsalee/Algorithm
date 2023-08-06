#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
int arr[1001] = {0, };
 
int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    
    int N, L;
    cin >> N >> L;
 
    for (int i=0; i<N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    
    sort(v.begin(), v.end());
 
    int cnt = 0;
    for (int i=0; i<v.size(); i++) {
        int temp = v[i];
 
        if (arr[temp] == 0) {
            for (int j=temp; j<temp+L; j++) {
                if (j > 1000) break;
                
                arr[j] = 1;
            }
            cnt++;
        }
    }
    cout << cnt;
}