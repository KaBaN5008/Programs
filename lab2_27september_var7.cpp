#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Point {
private:
    double x;
    double y;

public:
    Point() {
        x = 0.0;
        y = 0.0;
    }
    
    Point(double xCoord, double yCoord) {
        x = xCoord;
        y = yCoord;
    }
    
    Point(const Point& other) {
        x = other.x;
        y = other.y;
    }
    
    // Метод для перемещения по оси X
    void moveX(double delta) {
        x += delta;
    }
    
    // Метод для перемещения по оси Y
    void moveY(double delta) {
        y += delta;
    }
    
    // Метод для определения расстояния до начала координат
    double distanceToOrigin() const {
        return sqrt(x * x + y * y);
    }
    
    // Метод для определения расстояния между двумя точками
    double distanceTo(const Point& other) const {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
    }
    
    // Метод для преобразования в полярные координаты
    void toPolar(double& radius, double& angle) const {
        radius = distanceToOrigin();
        angle = atan2(y, x) * 180.0 / M_PI; // угол в градусах
        if (angle < 0) angle += 360.0; // нормализация угла
    }
    
    double getX() const { return x; }
    double getY() const { return y; }
    
    void setX(double newX) { x = newX; }
    void setY(double newY) { y = newY; }
    
    void displayInfo() const {
        cout << "Точка (" << fixed << setprecision(2) << x << ", " << y << ")" << endl;
    }
    
    // ПЕРЕГРУЗКИ ОПЕРАТОРОВ:
    
    // 1
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
    
    // 2
    bool operator!=(const Point& other) const {
        return !(*this == other);
    }
    
    // 3
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }
    
    // 4
    Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y);
    }
    
    // 5
    friend ostream& operator<<(ostream& os, const Point& p) {
        os << "(" << fixed << setprecision(2) << p.x << ", " << p.y << ")";
        return os;
    }
};

int main() {
    cout << "=== Демонстрация работы класса Point ===" << endl << endl;
    
    cout << "1. Создание точки с помощью конструктора инициализации:" << endl;
    Point point1(3.0, 4.0);
    point1.displayInfo();
    cout << endl;

    cout << "2. Создание точки с помощью конструктора без аргументов:" << endl;
    Point point2;
    point2.displayInfo();
    cout << endl;
    
    cout << "3. Создание точки с помощью конструктора копирования:" << endl;
    Point point3(point1);
    point3.displayInfo();
    cout << endl;
    
    cout << "4. Создание массива точек:" << endl;
    Point points[3] = {
        Point(1.0, 2.0),
        Point(5.0, -3.0),
        Point(-2.0, -4.0)
    };
    
    for (int i = 0; i < 3; i++) {
        cout << "Точка " << i + 1 << ": ";
        points[i].displayInfo();
    }
    cout << endl;
    
    cout << "5. Демонстрация всех методов:" << endl;
    Point demoPoint(3.0, 4.0);
    
    cout << "Исходное состояние: ";
    demoPoint.displayInfo();
    cout << endl;
    
    cout << "После перемещения по X на +2.5: ";
    demoPoint.moveX(2.5);
    demoPoint.displayInfo();
    
    cout << "После перемещения по Y на -1.5: ";
    demoPoint.moveY(-1.5);
demoPoint.displayInfo();
    cout << endl;
    
    cout << "Расстояние до начала координат: " 
         << fixed << setprecision(2) << demoPoint.distanceToOrigin() << endl;
    
    Point otherPoint(1.0, 1.0);
    cout << "Расстояние до точки " << otherPoint << ": " 
         << demoPoint.distanceTo(otherPoint) << endl;
    cout << endl;
    
    double radius, angle;
    demoPoint.toPolar(radius, angle);
    cout << "Полярные координаты: радиус = " << radius 
         << ", угол = " << angle << "°" << endl;
    cout << endl;

    cout << "6. Демонстрация для разных точек:" << endl;
    Point test1(0.0, 5.0);
    Point test2(5.0, 0.0);
    Point test3(-3.0, -4.0);
    
    test1.toPolar(radius, angle);
    cout << "Точка " << test1 << ": расстояние = " << test1.distanceToOrigin() 
         << ", полярные координаты: (" << radius << ", " << angle << "°)" << endl;
    
    test2.toPolar(radius, angle);
    cout << "Точка " << test2 << ": расстояние = " << test2.distanceToOrigin() 
         << ", полярные координаты: (" << radius << ", " << angle << "°)" << endl;
    
    test3.toPolar(radius, angle);
    cout << "Точка " << test3 << ": расстояние = " << test3.distanceToOrigin() 
         << ", полярные координаты: (" << radius << ", " << angle << "°)" << endl;
    cout << endl;
    
    // 7. ДЕМОНСТРАЦИЯ ПЕРЕГРУЗОК ОПЕРАТОРОВ
    cout << "=== Демонстрация перегруженных операторов ===" << endl;
    
    Point p1(2.0, 3.0);
    Point p2(1.0, 1.0);
    Point p3(2.0, 3.0);
    
    cout << "Исходные точки:" << endl;
    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
    cout << "p3 = " << p3 << endl << endl;
    
    // Перегрузка ==
    cout << "p1 == p2: " << (p1 == p2 ? "true" : "false") << endl;
    cout << "p1 == p3: " << (p1 == p3 ? "true" : "false") << endl;
    
    // Перегрузка !=
    cout << "p1 != p2: " << (p1 != p2 ? "true" : "false") << endl;
    cout << "p1 != p3: " << (p1 != p3 ? "true" : "false") << endl << endl;
    
    // Перегрузка +
    cout << "p1 + p2 = " << (p1 + p2) << endl;
    
    // Перегрузка -
    cout << "p1 - p2 = " << (p1 - p2) << endl << endl;
    
    // Перегрузка << (уже используется выше)
    cout << "Использование оператора << для вывода: p1 = " << p1 << endl;
    
    // Дополнительная демонстрация арифметических операций
    cout << "\nДополнительные операции:" << endl;
    Point result = p1 + p2 - p3;
    cout << "p1 + p2 - p3 = " << result << endl;
    
    // Демонстрация цепочки операций
    Point p4(0.0, 0.0);
    cout << "Исходная p4 = " << p4 << endl;
    p4 = p4 + Point(1.0, 2.0) + Point(3.0, 4.0);
    cout << "После p4 = p4 + Point(1,2) + Point(3,4) = " << p4 << endl;
    
    return 0;
}
