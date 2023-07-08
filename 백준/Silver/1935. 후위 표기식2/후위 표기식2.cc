#include <iostream>
#include <stack>
#include <string>
 
using namespace std;
 
int main()
{
	int N;
	string str;
	cin >> N >> str;
	double arr[26] = { 0, };
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	
	stack<double> stack;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			stack.push(arr[str[i] - 'A']);
		}
		
		else if (!stack.empty()) {
			double temp = stack.top();
			stack.pop();
			
			if (str[i] == '+') {
				temp = stack.top() + temp;
			}
			else if (str[i] == '-') {
				temp = stack.top() - temp;
			}
			else if (str[i] == '*') {
				temp = stack.top() * temp;
			}
			else if (str[i] == '/') {
				temp = stack.top() / temp;
			}
			stack.pop();
			stack.push(temp);
		}
	}
    
	cout << fixed;
	cout.precision(2);
	cout << stack.top() << "\n";
 
	return 0;
}