#include <iostream>
#include <string>
using namespace std;

void solve(int num) {
    string str = to_string(num);
    int w = 0;
    
    for (int i=0; i<str.length(); i++) {
        if (str[i] == '0') 
            w += 4;
            
        else if (str[i] == '1')
            w += 2;
        
        else
            w += 3;
    }
    
    cout << w + str.length() + 1 << "\n";
}

int main()
{
    int num;
    
    while (true){
        cin >> num;
        
        if (num == 0)
            break;
            
        solve(num);
    }
}