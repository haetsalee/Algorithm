#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> v;
int maxEnergy = 0;

void solve(int energy) {
    if (v.size() == 2) {
        maxEnergy = max(maxEnergy, energy);
        return;
    }
    
    for (int i=1; i < v.size() - 1; i++) {
        int nextEnergy = energy + v[i-1] * v[i+1];
        int temp = v[i];
        v.erase(v.begin() + i);
        solve(nextEnergy);
        v.insert(v.begin() + i, temp);
    }
}

int main() {
    cin >> N;
    v = vector<int>(N);
    
    for (int i=0; i<N; i++) {
        cin >> v[i];
    }
    
    solve(0);
    
    cout << maxEnergy << endl;
    
    return 0;
}