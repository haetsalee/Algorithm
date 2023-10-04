#include <iostream>
using namespace std;

int main()
{
	int ax, ay, az, bx, by, bz, cx, cy, cz;
	
	cin >> ax >> ay >> az >> cx >> cy >> cz;

	cout << cx - az << " " << cy / ay << " " << cz - ax;
}