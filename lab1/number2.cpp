#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

// 1. Класс Complex для работы с комплексными числами
class Complex {
private:
    double real;
    double imag;

public:
    // Конструкторы
    Complex() : real(0), imag(0) {}
    Complex(double r, double i) : real(r), imag(i) {}
    
    // Ввод с клавиатуры
    void read() {
        cout << "Введите действительную часть: ";
        cin >> real;
        cout << "Введите мнимую часть: ";
        cin >> imag;
    }
    
    // Вывод на экран
    void display() const {
        if (imag >= 0)
            cout << real << " + " << imag << "i";
        else
            cout << real << " - " << -imag << "i";
    }
    
    // Преобразование в строку
    string toString() const {
        if (imag >= 0)
            return to_string(real) + " + " + to_string(imag) + "i";
        else
            return to_string(real) + " - " + to_string(-imag) + "i";
    }
    
    // Операции
    Complex add(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
    
    Complex sub(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }
    
    Complex mul(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag, 
                      real * other.imag + imag * other.real);
    }
    
    Complex div(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        return Complex((real * other.real + imag * other.imag) / denominator,
                      (imag * other.real - real * other.imag) / denominator);
    }
    
    bool equ(const Complex& other) const {
        return real == other.real && imag == other.imag;
    }
    
    Complex conj() const {
        return Complex(real, -imag);
    }
};

// 2. Класс vector3D для работы с 3D векторами
class vector3D {
private:
    double x, y, z;

public:
    vector3D() : x(0), y(0), z(0) {}
    vector3D(double x, double y, double z) : x(x), y(y), z(z) {}
    
    void read() {
        cout << "Введите координату x: ";
        cin >> x;
        cout << "Введите координату y: ";
        cin >> y;
        cout << "Введите координату z: ";
        cin >> z;
    }
    
    void display() const {
        cout << "(" << x << ", " << y << ", " << z << ")";
    }
    
    string toString() const {
        return "(" + to_string(x) + ", " + to_string(y) + ", " + to_string(z) + ")";
    }
    
    vector3D add(const vector3D& other) const {
        return vector3D(x + other.x, y + other.y, z + other.z);
    }
    
    vector3D sub(const vector3D& other) const {
        return vector3D(x - other.x, y - other.y, z - other.z);
    }
    
    double dot(const vector3D& other) const { // скалярное произведение
        return x * other.x + y * other.y + z * other.z;
    }
    
    vector3D mul(double scalar) const { // умножение на скаляр
        return vector3D(x * scalar, y * scalar, z * scalar);
    }
    
    bool equ(const vector3D& other) const {
        return x == other.x && y == other.y && z == other.z;
    }
    
    double length() const {
        return sqrt(x*x + y*y + z*z);
    }
    
    bool compareLength(const vector3D& other) const {
        return length() == other.length();
    }
};

// 3. Класс ModelWindow для работы с моделями окон
class ModelWindow {
private:
    string title;
    int x, y; // координаты левого верхнего угла
    int width, height;
    string color;
    bool visible;
    bool framed;
    const int screenWidth = 1920;
    const int screenHeight = 1080;

public:
    ModelWindow() : title(""), x(0), y(0), width(100), height(100), 
                   color("white"), visible(true), framed(true) {}
    
    ModelWindow(string t, int x, int y, int w, int h, string c, bool v, bool f)
        : title(t), x(x), y(y), width(w), height(h), color(c), visible(v), framed(f) {}
    
    void read() {
        cout << "Заголовок: ";
        cin.ignore();
        getline(cin, title);
        cout << "Координата X: ";
cin >> x;
        cout << "Координата Y: ";
        cin >> y;
        cout << "Ширина: ";
        cin >> width;
        cout << "Высота: ";
        cin >> height;
        cout << "Цвет: ";
        cin >> color;
        cout << "Видимое (1/0): ";
        cin >> visible;
        cout << "С рамкой (1/0): ";
        cin >> framed;
    }
    
    void display() const {
        cout << "Окно '" << title << "': " << x << "," << y << " " 
             << width << "x" << height << " цвет: " << color
             << " видимое: " << (visible ? "да" : "нет")
             << " рамка: " << (framed ? "да" : "нет");
    }
    
    string toString() const {
        return "Окно '" + title + "': " + to_string(x) + "," + to_string(y) + " " +
               to_string(width) + "x" + to_string(height) + " цвет: " + color +
               " видимое: " + (visible ? "да" : "нет") +
               " рамка: " + (framed ? "да" : "нет");
    }
    
    void moveHorizontal(int dx) {
        if (x + dx >= 0 && x + dx + width <= screenWidth) {
            x += dx;
        }
    }
    
    void moveVertical(int dy) {
        if (y + dy >= 0 && y + dy + height <= screenHeight) {
            y += dy;
        }
    }
    
    void resize(int newWidth, int newHeight) {
        if (newWidth > 0 && newHeight > 0 && 
            x + newWidth <= screenWidth && y + newHeight <= screenHeight) {
            width = newWidth;
            height = newHeight;
        }
    }
    
    void setColor(string newColor) {
        color = newColor;
    }
    
    void setVisible(bool isVisible) {
        visible = isVisible;
    }
    
    void setFramed(bool isFramed) {
        framed = isFramed;
    }
    
    bool isVisible() const { return visible; }
    bool isFramed() const { return framed; }
};

// 4. Класс Money для работы с денежными суммами
class Money {
private:
    long rubles;
    unsigned char kopecks;

    void normalize() {
        if (kopecks >= 100) {
            rubles += kopecks / 100;
            kopecks %= 100;
        }
    }

public:
    Money() : rubles(0), kopecks(0) {}
    Money(long r, unsigned char k) : rubles(r), kopecks(k) {
        normalize();
    }
    
    void read() {
        cout << "Рубли: ";
        cin >> rubles;
        int k;
        cout << "Копейки: ";
        cin >> k;
        kopecks = k;
        normalize();
    }
    
    void display() const {
        cout << rubles << "," << (kopecks < 10 ? "0" : "") << (int)kopecks;
    }
    
    string toString() const {
        return to_string(rubles) + "," + (kopecks < 10 ? "0" : "") + to_string((int)kopecks);
    }
    
    Money add(const Money& other) const {
        long totalKopecks = rubles * 100 + kopecks + other.rubles * 100 + other.kopecks;
        return Money(totalKopecks / 100, totalKopecks % 100);
    }
    
    Money sub(const Money& other) const {
        long totalKopecks = rubles * 100 + kopecks - (other.rubles * 100 + other.kopecks);
        if (totalKopecks < 0) totalKopecks = 0;
        return Money(totalKopecks / 100, totalKopecks % 100);
    }
    
    Money div(const Money& other) const {
        if (other.rubles == 0 && other.kopecks == 0) return Money();
        double thisTotal = rubles + kopecks / 100.0;
        double otherTotal = other.rubles + other.kopecks / 100.0;
        double result = thisTotal / otherTotal;
        return Money(result, (result - (long)result) * 100);
    }
    
    Money div(double divisor) const {
        if (divisor == 0) return Money();
        double total = rubles + kopecks / 100.0;
        double result = total / divisor;
        return Money(result, (result - (long)result) * 100);
    }
    
    Money mul(double multiplier) const {
        double total = rubles + kopecks / 100.0;
        double result = total * multiplier;
        return Money(result, (result - (long)result) * 100);
    }
    
    bool equ(const Money& other) const {
        return rubles == other.rubles && kopecks == other.kopecks;
    }
};
