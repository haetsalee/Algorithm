#include<iostream>
#include<string>

using namespace std;

int main() {
	string str;
	cin >> str;
	
	int arr[26] = {0, };
	
	for (int i = 0; i < str.size(); i++) {
		arr[str[i] - 97] += 1;
	}
	for (int i = 0; i < 26; i++) {
		cout << arr[i]<<" ";
	}
}