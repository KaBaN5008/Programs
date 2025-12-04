#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int findMinStep(string board, string hand) {
        sort(hand.begin(), hand.end());
        
        queue<State> q;
        q.push({board, hand, 0});
        
        unordered_set<string> visited;
        visited.insert(board + "#" + hand);
        
        while (!q.empty()) {
            State current = q.front();
            q.pop();
            
            string currBoard = current.board;
            string currHand = current.hand;
            int steps = current.steps;
            
            if (currBoard.empty()) {
                return steps;
            }
            
            if (currHand.empty()) {
                continue;
            }
            
            for (int i = 0; i < currHand.length(); i++) {
                if (i > 0 && currHand[i] == currHand[i - 1]) {
                    continue;
                }
                
                char ball = currHand[i];
                
                string newHand = currHand.substr(0, i) + currHand.substr(i + 1);
                
                for (int j = 0; j <= currBoard.length(); j++) {
                    if (j > 0 && j < currBoard.length() && 
                        currBoard[j - 1] == ball && ball == currBoard[j]) {
                        continue;
                    }
                    
                    string newBoard = currBoard.substr(0, j) + ball + currBoard.substr(j);

                    newBoard = removeConsecutive(newBoard);

                    string key = newBoard + "#" + newHand;

                    if (visited.find(key) == visited.end()) {
                        visited.insert(key);
                        q.push({newBoard, newHand, steps + 1});
                    }
                }
            }
        }
        
        return -1; 
    }

private:
    struct State {
        string board;
        string hand;
        int steps;
    };

    string removeConsecutive(string board) {
        bool found = true;
        
        while (found) {
            found = false;
            int n = board.length();
            
            for (int i = 0; i < n; ) {
                int j = i;
                while (j < n && board[j] == board[i]) {
                    j++;
                }

                if (j - i >= 3) {
                    board = board.substr(0, i) + board.substr(j);
                    found = true;
                    break;
                }
                
                i = j;
            }
        }
        
        return board;
    }
};

// Тестирование
int main() {
    Solution solution;
    
    // Тест 1
    cout << "Тест 1: " << solution.findMinStep("WRRBBW", "RB") 
         << " (ожидается: -1)" << endl;
    
    // Тест 2
cout << "Тест 2: " << solution.findMinStep("WWRRBBWW", "WRBRW") 
         << " (ожидается: 2)" << endl;
    
    // Тест 3
    cout << "Тест 3: " << solution.findMinStep("G", "GGGGG") 
         << " (ожидается: 2)" << endl;
    
    // Тест 4
    cout << "Тест 4: " << solution.findMinStep("RBYYBBRRB", "YRBGB") 
         << " (ожидается: 3)" << endl;
    
    // Тест 5: пустая доска
    cout << "Тест 5: " << solution.findMinStep("", "RGB") 
         << " (ожидается: 0)" << endl;
    
    return 0;
}
