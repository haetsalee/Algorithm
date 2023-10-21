#include <iostream>
using namespace std;

int main()
{
    int N, A, B;
    char comma;
    cin >> N;

    while (N--) {
        cin >> A >> comma >> B;
        cout << A+B << "\n";
    }
}