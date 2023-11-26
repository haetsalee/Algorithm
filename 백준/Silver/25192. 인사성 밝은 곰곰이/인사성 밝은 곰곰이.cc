#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){
    int N;
    cin >> N;

    set<string> s;
    int cnt = 0;
    
    for(int i=0; i<N; i++){
        string str;
        cin >> str;
        if(str == "ENTER") {
            cnt += s.size();
            s.clear();
        }
        
        else s.insert(str);
    }
    
    cnt += s.size();
    
    cout << cnt;
}