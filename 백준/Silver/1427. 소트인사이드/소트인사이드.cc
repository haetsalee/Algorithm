#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string temp; 
    cin >> temp;
    
	sort(temp.begin(), temp.end());
	reverse(temp.begin(), temp.end());
	cout << temp; 
}