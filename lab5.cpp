#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>

using namespace std;

class Number {
protected:
    float value;

public:
    Number() {
        value = 0.0f;
    }
    
    Number(float val) {
        value = val;
    }
    
    Number add(const Number& other) const {
        return Number(value + other.value);
    }
    
    Number divide(const Number& other) const {
        if (other.value == 0.0f) {
            throw invalid_argument("Деление на ноль");
        }
        return Number(value / other.value);
    }
    
    string toString() const {
        return to_string(value);
    }
};

class Real : public Number {
public:
    Real() {
        value = 0.0f;
    }
    
    Real(float val) {
        value = val;
    }
    
    Real power(float exponent) const {
        return Real(pow(value, exponent));
    }
    
    Real logarithm(float base = 10.0f) const {
        return Real(log(value) / log(base));
    }
    
    string toString() const {
        return "Real(" + to_string(value) + ")";
    }
};

int main() {
    Number a(10.5f);
    Number b(2.5f);
    
    Real x(16.0f);
    Real y(4.0f);
    
    cout << "Сложение: " << a.toString() << " + " << b.toString() << " = " << a.add(b).toString() << endl;
    cout << "Деление: " << a.toString() << " / " << b.toString() << " = " << a.divide(b).toString() << endl;
    
    cout << "Степень: " << x.toString() << " ^ 2 = " << x.power(2).toString() << endl;
    cout << "Логарифм: log10(" << y.toString() << ") = " << y.logarithm().toString() << endl;
    
    return 0;
}
