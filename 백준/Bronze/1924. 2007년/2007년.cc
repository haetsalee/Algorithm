#include <iostream>
#include <string>
using namespace std;

int main()
{
    int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string week[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    
    int x, y;
    cin >> x >> y;
    
    for (int i=0; i<x-1; i++) {
        y += month[i];
    }
    
    cout << week[y % 7];
}