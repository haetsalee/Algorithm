#include <iostream>
using namespace std;

int main()
{
    int goal;
    cin >> goal;
    
    int cnt = 0;
    while (goal >= 0) {
        if (goal % 5 == 0) {
            cnt += (goal / 5);
            cout << cnt;
            return 0;
        }
        
        goal -= 3;
        cnt ++;
    }
    
    cout << -1;
}