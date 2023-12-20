#include <iostream>
#include <string>
using namespace std;

int main() {
    string alpha;
    cin >> alpha;

    int num = stoi(alpha, nullptr, 16);
    cout << num;

    return 0;
}