#include <iostream>
using namespace std;

int main()
{
   int num;
   cin >> num;
   
   int cnt = 0;
   for (int i=0; i<5; i++) {
       int temp;
       cin >> temp;
       if (temp == num) cnt++;
   }
   
   cout << cnt;
}