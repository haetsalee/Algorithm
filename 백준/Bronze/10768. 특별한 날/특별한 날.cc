#include <iostream>
using namespace std;

int main()
{
    int M, D;
    cin >> M >> D;
    
    if (M == 1 || (M == 2 && D < 18))
        cout << "Before";
    else if (M == 2 && D == 18)
        cout << "Special";
    else
        cout << "After";
}