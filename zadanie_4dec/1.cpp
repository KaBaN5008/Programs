#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int candy(std::vector<int>& ratings) {
        int n = ratings.size();
        if (n <= 1) return n;
        
        std::vector<int> candies(n, 1);
        
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = std::max(candies[i], candies[i + 1] + 1);
            }
        }
        
        int total = 0;
        for (int candy_count : candies) {
            total += candy_count;
        }
        
        return total;
    }
};

void testCase(const std::vector<int>& ratings, int expected, const std::string& testName) {
    Solution solution;
    std::vector<int> ratingsCopy = ratings;
    int result = solution.candy(ratingsCopy);
    
    std::cout << "Тест: " << testName << std::endl;
    std::cout << "Рейтинги: [";
    for (size_t i = 0; i < ratings.size(); i++) {
        std::cout << ratings[i];
        if (i < ratings.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
    
    std::cout << "Ожидаемый результат: " << expected << std::endl;
    std::cout << "Полученный результат: " << result << std::endl;
    
    if (result == expected) {
        std::cout << "✓ ТЕСТ ПРОЙДЕН" << std::endl;
    } else {
        std::cout << "✗ ТЕСТ НЕ ПРОЙДЕН" << std::endl;
    }
    std::cout << "------------------------" << std::endl;
}

int main() {
    std::cout << "=== ТЕСТИРОВАНИЕ ЗАДАЧИ О КОНФЕТАХ ===" << std::endl;
    std::cout << std::endl;
    
    // Тест 1: Пример из условия
    testCase({1, 0, 2}, 5, "Пример 1: [1,0,2]");
    
    // Тест 2: Второй пример из условия
    testCase({1, 2, 2}, 4, "Пример 2: [1,2,2]");
    
    // Тест 3: Возрастающий рейтинг
    testCase({1, 2, 3, 4, 5}, 15, "Строго возрастающий рейтинг [1,2,3,4,5]");
    
    // Тест 4: Убывающий рейтинг
    testCase({5, 4, 3, 2, 1}, 15, "Строго убывающий рейтинг [5,4,3,2,1]");
    
    // Тест 5: Все одинаковые рейтинги
    testCase({2, 2, 2, 2}, 4, "Все одинаковые рейтинги [2,2,2,2]");
    
    // Тест 6: Пик в середине
    testCase({1, 3, 2, 1}, 7, "Пик в середине [1,3,2,1]");
    
    // Тест 7: Два пика
    testCase({1, 2, 3, 1, 2, 1}, 10, "Два пика [1,2,3,1,2,1]");
    
    // Тест 8: Один ребенок
    testCase({5}, 1, "Один ребенок [5]");
    
    // Тест 9: Два ребенка с разными рейтингами
    testCase({1, 2}, 3, "Два ребенка: возрастание [1,2]");
    
    // Тест 10: Два ребенка с одинаковыми рейтингами
    testCase({2, 2}, 2, "Два ребенка: одинаковые [2,2]");
    
    // Тест 11: Сложный случай с плато
    testCase({1, 3, 4, 5, 2}, 11, "Сложный случай [1,3,4,5,2]");
    
    return 0;
}
