#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int calculateMinimumHP(std::vector<std::vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, INT_MAX));
        dp[m][n - 1] = 1;
        dp[m - 1][n] = 1;
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int minHealth = std::min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
                dp[i][j] = std::max(1, minHealth);
            }
        }
        
        return dp[0][0];
    }
};

// Тестирование
int main() {
    Solution solution;
    
    // Тест 1
    std::vector<std::vector<int>> dungeon1 = {
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5}
    };
    std::cout << "Тест 1: " << solution.calculateMinimumHP(dungeon1) << " (ожидается: 7)" << std::endl;
    
    // Тест 2
    std::vector<std::vector<int>> dungeon2 = {{0}};
    std::cout << "Тест 2: " << solution.calculateMinimumHP(dungeon2) << " (ожидается: 1)" << std::endl;
    
    // Тест 3: все положительные
    std::vector<std::vector<int>> dungeon3 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    std::cout << "Тест 3: " << solution.calculateMinimumHP(dungeon3) << " (ожидается: 1)" << std::endl;
    
    // Тест 4: все отрицательные
    std::vector<std::vector<int>> dungeon4 = {
        {-1, -2, -3},
        {-4, -5, -6},
        {-7, -8, -9}
    };
    std::cout << "Тест 4: " << solution.calculateMinimumHP(dungeon4) << std::endl;
    
    // Тест 5: путь с бонусами
    std::vector<std::vector<int>> dungeon5 = {
        {1, -3, 0},
        {-2, -4, -1},
        {2, 1, -5}
    };
    std::cout << "Тест 5: " << solution.calculateMinimumHP(dungeon5) << std::endl;
    
    return 0;
}
