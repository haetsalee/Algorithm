#include <iostream>
#include <string>
using namespace std;

int main()
{
    string L, R;
    cin >> L >> R;
    
    int cnt = 0;
    
    if (L.length() == R.length()) {
        for (int i=0; i<L.length(); i++) {
            if (L[i] != R[i])
                break;
            
            if (L[i] == '8')
                cnt++;
        }
    }
    cout << cnt;
}