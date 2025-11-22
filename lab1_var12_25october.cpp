#include <iostream>

// Шаблонная функция для вставки элемента в массив
template <typename T>
int insertElement(T* arr, int size, T element, int index) {
    if (index < 0 || index > size) {
        std::cout << "Ошибка: некорректный индекс" << std::endl;
        return size;
    }

    for (int i = size; i > index; i--) {
        arr[i] = arr[i-1];
    }

    arr[index] = element;
    
    return size + 1;
}

int main() {
    int arr[100] = {1, 2, 3, 4, 5};
    int size = 5;
    
    std::cout << "Исходный массив: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    size = insertElement(arr, size, 10, 2);
    
    std::cout << "Массив после вставки: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    double arr2[100] = {1.1, 2.2, 3.3};
    int size2 = 3;
    
    std::cout << "\nИсходный массив (double): ";
    for (int i = 0; i < size2; i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;
    
    size2 = insertElement(arr2, size2, 5.5, 1);
    
    std::cout << "Массив после вставки (double): ";
    for (int i = 0; i < size2; i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
