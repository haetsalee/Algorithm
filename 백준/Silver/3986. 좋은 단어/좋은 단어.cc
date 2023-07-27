#include <iostream>
#include <stack>
using namespace std;

int main(){
    int N;
    cin >> N;
    
    int result = 0;
    
    for (int i=0; i<N; i++) {
        string word;
        cin >> word;
        
        stack <char> s;
        
        for(int i=0; i < word.size(); i++){
            if(!s.size())
                s.push(word[i]);
            else {
                if(s.top()!=word[i])
                    s.push(word[i]);
                else
                    s.pop();
            }
        }
        
        if(s.empty())
            result++;
    }
    cout << result << "\n";
}