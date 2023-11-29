#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string treename;
    double cnt = 0;

    while (getline(cin, treename)) {
        cnt++;
        if (m.find(treename) != m.end())
            m[treename]++;
        else
            m.insert({ treename, 1 });
    }

    cout << fixed;
    cout.precision(4);

    for (auto iter = m.begin(); iter != m.end(); iter++) {
        cout << iter->first << " " << iter->second / cnt * 100 << "\n";
    }
}