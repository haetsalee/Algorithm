#include <iostream>
using namespace std;

int fibo(int x) {
    if (x >= 2)
        return fibo(x - 1) + fibo(x - 2);
    
    else if (x == 1)
        return 1;
        
    return 0;
}

int main()
{
    int num;
    cin >> num;
    cout << fibo(num);
}