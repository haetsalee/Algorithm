#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int l, a, b, c, d, result;

	cin >> l >> a >> b >> c >> d;
	
	if (a % c == 0)
		result = a / c;
	else
		result = (a / c) + 1;

	if (b % d == 0)
		result = max(result, b / d);
	else
		result = max(result, (b / d) + 1);

	cout << l - result << "\n";
}