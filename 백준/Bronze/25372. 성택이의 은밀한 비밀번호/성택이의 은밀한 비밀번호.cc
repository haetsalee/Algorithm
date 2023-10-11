#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;
    cin >> N;
    for (int i=0; i<N; i++) {
        string pw;
        cin >> pw;
        if (6 <= pw.length() &&  pw.length() <= 9)
            cout << "yes" << "\n";
        else
            cout << "no" << "\n";
    }
}
