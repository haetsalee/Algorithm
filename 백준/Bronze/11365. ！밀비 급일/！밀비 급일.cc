#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    while(true) {
        string str;
        getline(cin, str);
        
        if (str == "END") break;
        
        for (int i=str.length()-1; i>=0; i--)
            cout << str[i];
            
        cout << "\n";
    }
}