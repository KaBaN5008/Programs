#include <iostream>
#include <string>
#include <queue>
using namespace std;

string predictPartyVictory(string senate) {
    queue<int> radiant, dire;
    int n = senate.size();
    
    for (int i = 0; i < n; i++) {
        if (senate[i] == 'R') {
            radiant.push(i);
        } else {
            dire.push(i);
        }
    }
    
    while (!radiant.empty() && !dire.empty()) {
        int r_index = radiant.front();
        int d_index = dire.front();
        radiant.pop();
        dire.pop();
        
        if (r_index < d_index) {
            radiant.push(r_index + n);
        } else {
            dire.push(d_index + n);
        }
    }
    
    return radiant.empty() ? "Dire" : "Radiant";
}

int main() {
    // Тестирование
    string test1 = "RD";
    string test2 = "RDD";
    string test3 = "RRDDD";
    string test4 = "RDDR";
    
    cout << "Senate: " << test1 << " -> " << predictPartyVictory(test1) << endl;
    cout << "Senate: " << test2 << " -> " << predictPartyVictory(test2) << endl;
    cout << "Senate: " << test3 << " -> " << predictPartyVictory(test3) << endl;
    cout << "Senate: " << test4 << " -> " << predictPartyVictory(test4) << endl;
    
    return 0;
}
