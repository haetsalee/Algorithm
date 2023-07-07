#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    int N;
    cin >> N;
 
    int temp = 1000 - N;
 
    vector<int> v = {500, 100, 50, 10, 5, 1};
    int cnt = 0;
 
    for(int i=0; i<v.size(); i++){
        while(temp - v[i] >= 0){
            cnt++;
            temp -= v[i];
        }
    }
 
    cout<<cnt;
    return 0;
}
