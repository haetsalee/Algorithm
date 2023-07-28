#include <iostream>
using namespace std;

int gcd(int x, int y) {
    while (y != 0) {
        int r = x % y;
        x = y;
        y = r;
    }
    
    return x;
}

int main()
{
    int x1, x2, y1, y2;
    cin >> x1 >> x2 >> y1 >> y2;
    
    int total = x1 * y2 + y1 * x2;
    int total_up = x2 * y2;
    int g = gcd(total, total_up);
    
    cout << total / g << " " << total_up / g; 
}
