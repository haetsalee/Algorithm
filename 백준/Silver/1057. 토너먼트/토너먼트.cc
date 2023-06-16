#include <iostream>
using namespace std;

int main()
{
    int N;
    int A, B;
    cin >> N >> A >> B;
    
    int cnt = 0;
    
    while(A != B)
    {
        A = (A + 1) / 2;
        B = (B + 1) / 2;
        cnt += 1;
    }

   cout << cnt;
}