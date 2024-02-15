#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;  
    map<char, int> termDays;
    
    for (auto &term : terms) {
        stringstream ss(term);
        char termType;
        int termPeriod;
        
        ss >> termType >> termPeriod;
        termDays[termType] = termPeriod * 28;
    }
    
    int yy, mm, dd;
    char temp;
    
    stringstream ss_today(today);    
    ss_today >> yy >> temp >> mm >> temp >> dd;
    
    int todays = yy * 12 * 28 + mm * 28 + dd;
    
    for(int i = 0; i < privacies.size(); i++) {
         char type;

         stringstream ss_privacy(privacies[i]);
         ss_privacy >> yy >> temp >> mm >> temp >> dd >> type;
         
         int days = yy * 12 * 28 + mm * 28 + dd;
               
         if (days + termDays[type] <= todays) {
             answer.push_back(i + 1);
         }
    }
    
    return answer;
}