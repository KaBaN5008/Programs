#include <iostream>
#include <cstring>

using namespace std;

class Number {
public:
    virtual void print() const = 0;
    virtual ~Number() {};
};

class Hex : public Number {
private:
    unsigned char digits[100];
    int length;
    
public:
    Hex() {
        length = 0;
        memset(digits, 0, sizeof(digits));
    }
    
    Hex(const char* hexStr) {
        length = 0;
        memset(digits, 0, sizeof(digits));
        int len = strlen(hexStr);
        for (int i = len - 1, j = 0; i >= 0 && j < 100; i--, j++) {
            char c = hexStr[i];
            if (c >= '0' && c <= '9') {
                digits[j] = c - '0';
            } else if (c >= 'A' && c <= 'F') {
                digits[j] = c - 'A' + 10;
            } else if (c >= 'a' && c <= 'f') {
                digits[j] = c - 'a' + 10;
            }
            length++;
        }
    }
    
    void print() const {
        if (length == 0) {
            cout << "0";
            return;
        }
        
        for (int i = length - 1; i >= 0; i--) {
            if (digits[i] < 10) {
                cout << char(digits[i] + '0');
            } else {
                cout << char(digits[i] - 10 + 'A');
            }
        }
    }
};

class BitString : public Number {
private:
    unsigned char bits[100];
    int bitCount;
    
public:
    BitString() {
        bitCount = 0;
        memset(bits, 0, sizeof(bits));
    }
    
    BitString(const char* bitStr) {
        bitCount = 0;
        memset(bits, 0, sizeof(bits));
        int len = strlen(bitStr);
        for (int i = len - 1, j = 0; i >= 0 && j < 100; i--, j++) {
            if (bitStr[i] == '1') {
                bits[j] = 1;
            } else if (bitStr[i] == '0') {
                bits[j] = 0;
            }
            bitCount++;
        }
    }
    
    void print() const {
        if (bitCount == 0) {
            cout << "0";
            return;
        }
        
        for (int i = bitCount - 1; i >= 0; i--) {
            cout << char(bits[i] + '0');
        }
    }
};

int main() {
    Number* numbers[2];
    
    numbers[0] = new Hex("1A3F");
    
    numbers[1] = new BitString("110101");
    
    for (int i = 0; i < 2; i++) {
        numbers[i]->print();
        cout << endl;
    }
    
    for (int i = 0; i < 2; i++) {
        delete numbers[i];
    }
    
    return 0;
}
