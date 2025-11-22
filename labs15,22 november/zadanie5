#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;
string decodeString(string s) {
    stack<pair<string, int>> st; // стек для хранения (строка, число)
    string currentStr = "";
    int currentNum = 0;
    
    for (char c : s) {
        if (isdigit(c)) {
            currentNum = currentNum * 10 + (c - '0');
        } else if (c == '[') {
            // Сохраняем текущую строку и число в стек
            st.push({currentStr, currentNum});
            currentStr = "";
            currentNum = 0;
        } else if (c == ']') {
            // Извлекаем из стека предыдущую строку и число
            auto [prevStr, num] = st.top();
            st.pop();
            
            // Повторяем текущую строку num раз и добавляем к предыдущей
            string temp = "";
            for (int i = 0; i < num; i++) {
                temp += currentStr;
            }
            currentStr = prevStr + temp;
        } else {
            // Обычный символ (буква)
            currentStr += c;
        }
    }
    
    return currentStr;
}
// Альтернативная версия с двумя стеками (для лучшей читаемости)
string decodeStringTwoStacks(string s) {
    stack<string> strStack;
    stack<int> numStack;
    string currentStr = "";
    int currentNum = 0;
    
    for (char c : s) {
        if (isdigit(c)) {
            currentNum = currentNum * 10 + (c - '0');
        } else if (c == '[') {
            // Сохраняем текущую строку и число
            strStack.push(currentStr);
            numStack.push(currentNum);
            currentStr = "";
            currentNum = 0;
        } else if (c == ']') {
            // Извлекаем число и предыдущую строку
            int num = numStack.top();
            numStack.pop();
            string prevStr = strStack.top();
            strStack.pop();
            
            // Повторяем текущую строку num раз
            string temp = "";
            for (int i = 0; i < num; i++) {
                temp += currentStr;
            }
            currentStr = prevStr + temp;
        } else {
            currentStr += c;
        }
    }
    
    return currentStr;
}
int main() {
    // Тестовые случаи
    cout << decodeString("3[a]2[bc]") << endl; // "aaabcbc"
    cout << decodeString("3[a2[c]]") << endl; // "accaccacc"
    cout << decodeString("2[abc]3[cd]ef") << endl; // "abcabccdcdcdef"
    
    return 0;
}

#include <iostream>
using namespace std;
void sortColors(int nums[], int n) {
    int low = 0, mid = 0, high = n - 1;
    
    while (mid <= high) {
        if (nums[mid] == 0) {
            // Меняем местами nums[low] и nums[mid]
            int temp = nums[low];
            nums[low] = nums[mid];
            nums[mid] = temp;
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else { // nums[mid] == 2
            // Меняем местами nums[mid] и nums[high]
            int temp = nums[mid];
            nums[mid] = nums[high];
            nums[high] = temp;
            high--;
        }
    }
}
// Альтернативная версия с функцией swap
void sortColorsWithSwap(int nums[], int n) {
    int low = 0, mid = 0, high = n - 1;
    
    while (mid <= high) {
        switch (nums[mid]) {
            case 0:
                swap(nums[low], nums[mid]);
                low++;
                mid++;
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(nums[mid], nums[high]);
                high--;
                break;
        }
    }
}
// Функция для печати массива
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    // Тестовые случаи
    
    // Тест 1
    int nums1[] = {2,0,2,1,1,0};
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    sortColors(nums1, n1);
    cout << "Test 1: ";
    printArray(nums1, n1); // [0,0,1,1,2,2]
    
    // Тест 2
    int nums2[] = {2,0,1};
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    sortColors(nums2, n2);
    cout << "Test 2: ";
    printArray(nums2, n2); // [0,1,2]
    
    // Тест 3
    int nums3[] = {1,0,2,1,0,2,1,0};
    int n3 = sizeof(nums3) / sizeof(nums3[0]);
    sortColors(nums3, n3);
    cout << "Test 3: ";
    printArray(nums3, n3); // [0,0,0,1,1,1,2,2]
    
    // Тест 4 (все одинаковые)
    int nums4[] = {1,1,1,1};
    int n4 = sizeof(nums4) / sizeof(nums4[0]);
    sortColors(nums4, n4);
    cout << "Test 4: ";
    printArray(nums4, n4); // [1,1,1,1]
    
    return 0;
}
