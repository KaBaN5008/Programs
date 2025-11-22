#include <iostream>
using namespace std;

class Array {
protected:
    static const int MAX_SIZE = 100;
    unsigned char data[MAX_SIZE];
    int size;

public:
    Array(int numElements = 0, unsigned char value = 0) : size(numElements) {
        for (int i = 0; i < MAX_SIZE; i++) {
            data[i] = (i < size) ? value : 0;
        }
    }
    
    virtual ~Array() {}
    
    unsigned char& operator[](int index) {
        return data[index];
    }
    
    int getSize() const { return size; }
    
    virtual Array* add(Array& other) {
        Array* result = new Array(size);
        for (int i = 0; i < size; i++) {
            (*result)[i] = data[i] + other[i];
        }
        return result;
    }
    
    virtual void print() {
        cout << "Array: ";
        for (int i = 0; i < size; i++) {
            cout << (int)data[i] << " ";
        }
        cout << endl;
    }
};

class Hex : public Array {
public:
    Hex(int numElements = 0, unsigned char value = 0) : Array(numElements, value) {}
    
    Array* add(Array& other) override {
        Hex* result = new Hex(size);
        int carry = 0;
        
        for (int i = 0; i < size; i++) {
            int sum = data[i] + other[i] + carry;
            carry = sum / 16;
            (*result)[i] = sum % 16;
        }
        return result;
    }
    
    void print() override {
        cout << "Hex: ";
        for (int i = size - 1; i >= 0; i--) {
            if (data[i] < 10) cout << (char)('0' + data[i]);
            else cout << (char)('A' + data[i] - 10);
        }
        cout << endl;
    }
};

class Octal : public Array {
public:
    Octal(int numElements = 0, unsigned char value = 0) : Array(numElements, value) {}
    
    Array* add(Array& other) override {
        Octal* result = new Octal(size);
        int carry = 0;
        
        for (int i = 0; i < size; i++) {
            int sum = data[i] + other[i] + carry;
            carry = sum / 8;
            (*result)[i] = sum % 8;
        }
        return result;
    }
    
    void print() override {
        cout << "Octal: ";
        for (int i = size - 1; i >= 0; i--) {
            cout << (int)data[i];
        }
        cout << endl;
    }
};

int main() {
    // Простой тест
    Hex h1(3), h2(3);
    h1[0] = 5; h1[1] = 10; h1[2] = 15;
    h2[0] = 10; h2[1] = 15; h2[2] = 5;
    
    cout << "Hex numbers:" << endl;
    h1.print();
    h2.print();
    
    Array* r1 = h1.add(h2);
    cout << "Sum: ";
    r1->print();
    delete r1;
    
    Octal o1(3), o2(3);
    o1[0] = 5; o1[1] = 7; o1[2] = 3;
    o2[0] = 2; o2[1] = 6; o2[2] = 1;
    
    cout << "\nOctal numbers:" << endl;
    o1.print();
    o2.print();
    
    Array* r2 = o1.add(o2);
    cout << "Sum: ";
    r2->print();
    delete r2;
    
    return 0;
}
