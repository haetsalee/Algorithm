#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    
    while (T--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int N;
        cin >> N;
        
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            int cx, cy, r;
            bool in1, in2;

            cin >> cx >> cy >> r;
            
            int d1 = (cx - x1) * (cx - x1) + (cy - y1) * (cy - y1);
            in1 = d1 > r * r ? false : true;
            
            int d2 = (cx - x2) * (cx - x2) + (cy - y2) * (cy - y2);
            in2 = d2 > r * r ? false : true;
            
            if(in1 != in2) cnt++;
        }
        cout << cnt << "\n";
    }

    return 0;
}