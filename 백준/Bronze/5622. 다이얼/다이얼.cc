#include <iostream>
#include <string>
using namespace std;

int main() 
{
	string str;
	cin >> str;

	int arr[26] = {3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10};

	int total = 0;
	for (int i = 0; i < str.size(); i++) {
		total += arr[str[i]-65];
	}

	cout << total;

	return 0;
}