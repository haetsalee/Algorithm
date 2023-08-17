#include <iostream>
using namespace std;

int main()
{
    int s1, s2, s3, s4, total;
    cin >> s1 >> s2 >> s3 >> s4;
    total = s1 + s2 + s3 + s4;
    
    int x, y;
    
    x = total / 60;
    y = total % 60;
    
    cout << x << "\n" << y;
}