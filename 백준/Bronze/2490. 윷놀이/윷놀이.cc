#include <iostream>
using namespace std;

int main()
{
    int num;
    int N = 3;
    
    while(N--) {
        int cnt = 0;
        for (int i=0; i<4; i++) {
            cin >> num;
            if (num == 0) cnt++;
        }

        if (cnt == 1) cout << "A";
        else if (cnt == 2) cout << "B";
        else if (cnt == 3) cout << "C";
        else if (cnt == 4) cout << "D";
        else cout << "E";
            
        cout << "\n";
    }
}