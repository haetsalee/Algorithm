#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int W, H, X, Y, P;
    cin >> W >> H >> X >> Y >> P;
    
    int result = 0;

    for (int i = 0; i < P; i++) {
        double x, y;
        cin >> x >> y;
        
        if (y >= Y && y <= Y + H) {
            if (x >= X && x <= X + W) 
                result++;
            
            else if (pow(X - x, 2) + pow((Y + H / 2) - y, 2) <= pow(H / 2, 2))
                result++;
            
            else if (pow(X + W - x, 2) + pow((Y + H / 2) - y, 2) <= pow(H / 2, 2))
                result++;
        }
    }
    
    cout << result;
}