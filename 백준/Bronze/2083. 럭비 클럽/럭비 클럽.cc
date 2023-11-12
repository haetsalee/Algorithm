#include <iostream>
using namespace std;

int main()
{
    string name;
    int age, weight;
    
    while (true) {
        cin >> name >> age >> weight;
        
        if (name == "#") break;
        
        if (age > 17 || weight >= 80) {
            cout << name << " " << "Senior";
        }
        
        else cout << name << " " << "Junior";
        
        cout << "\n";
    }
}