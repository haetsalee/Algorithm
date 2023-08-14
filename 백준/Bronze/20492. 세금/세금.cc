#include <iostream>
using namespace std;

int main()
{
    int money;
    cin >> money;
    
    int case1, case2;
    case1 = money * 0.78;
    case2 = money - (money*0.2*0.22);
    
    cout << case1 << " " << case2;
}