#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    
    long result = 1;
    
    if (N > 0) {
        for (int i=1; i<=N; i++) 
            result *= i;
    }
    
    cout << result;
}
