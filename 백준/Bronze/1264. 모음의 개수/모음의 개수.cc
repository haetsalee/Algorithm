#include <iostream>
#include <string>
using namespace std;

char check[] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    string str;
    int cnt;
    
    while(true) {
        cnt = 0;
        getline(cin, str);
        
        if (str == "#") break;
        
        for (int i=0; i<str.length(); i++) {
            for (int j=0; j<10; j++) {
                if (str[i] == check[j])
                    cnt++;
            }
        }
        
        cout << cnt << "\n";
    }
}