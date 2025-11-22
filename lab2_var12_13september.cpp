#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

// ===== РЕАЛИЗАЦИЯ ЧЕРЕЗ СТРУКТУРУ =====

struct TimeStruct {
    int hours;
    int minutes;
    int seconds;
};

void init(TimeStruct& time, int h, int m, int s) {
    time.hours = h;
    time.minutes = m;
    time.seconds = s;
    normalizeTime(time);
}

void read(TimeStruct& time) {
    cout << "Введите часы: ";
    cin >> time.hours;
    cout << "Введите минуты: ";
    cin >> time.minutes;
    cout << "Введите секунды: ";
    cin >> time.seconds;
    normalizeTime(time);
}

void display(const TimeStruct& time) {
    cout << "Время: " 
         << setw(2) << setfill('0') << time.hours << ":"
         << setw(2) << setfill('0') << time.minutes << ":"
         << setw(2) << setfill('0') << time.seconds << endl;
}

string toString(const TimeStruct& time) {
    stringstream ss;
    ss << setw(2) << setfill('0') << time.hours << ":"
       << setw(2) << setfill('0') << time.minutes << ":"
       << setw(2) << setfill('0') << time.seconds;
    return ss.str();
}

void normalizeTime(TimeStruct& time) {
    time.minutes += time.seconds / 60;
    time.seconds %= 60;
    if (time.seconds < 0) {
        time.seconds += 60;
        time.minutes--;
    }
    
    time.hours += time.minutes / 60;
    time.minutes %= 60;
    if (time.minutes < 0) {
        time.minutes += 60;
        time.hours--;
    }
    
    time.hours %= 24;
    if (time.hours < 0) {
        time.hours += 24;
    }
}

void addSeconds(TimeStruct& time, int seconds) {
    time.seconds += seconds;
    normalizeTime(time);
}

void subtractSeconds(TimeStruct& time, int seconds) {
    time.seconds -= seconds;
    normalizeTime(time);
}

int differenceInSeconds(const TimeStruct& time1, const TimeStruct& time2) {
    int total1 = time1.hours * 3600 + time1.minutes * 60 + time1.seconds;
    int total2 = time2.hours * 3600 + time2.minutes * 60 + time2.seconds;
    return abs(total1 - total2);
}

bool isValidTime(const TimeStruct& time) {
    return time.hours >= 0 && time.hours < 24 &&
           time.minutes >= 0 && time.minutes < 60 &&
           time.seconds >= 0 && time.seconds < 60;
}

// ===== РЕАЛИЗАЦИЯ ЧЕРЕЗ КЛАСС =====

class TimeClass {
private:
    int hours;
    int minutes;
    int seconds;

    void normalize() {
        minutes += seconds / 60;
        seconds %= 60;
        if (seconds < 0) {
            seconds += 60;
            minutes--;
        }
        
        hours += minutes / 60;
        minutes %= 60;
        if (minutes < 0) {
            minutes += 60;
            hours--;
        }
        
        hours %= 24;
        if (hours < 0) {
            hours += 24;
        }
    }

public:
    TimeClass() : hours(0), minutes(0), seconds(0) {}
    TimeClass(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
        normalize();
    }

    void init(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
        normalize();
    }

    void read() {
        cout << "Введите часы: ";
        cin >> hours;
        cout << "Введите минуты: ";
        cin >> minutes;
        cout << "Введите секунды: ";
        cin >> seconds;
        normalize();
    }

    void display() const {
        cout << "Время: " 
             << setw(2) << setfill('0') << hours << ":"
             << setw(2) << setfill('0') << minutes << ":"
             << setw(2) << setfill('0') << seconds << endl;
    }

    string toString() const {
        stringstream ss;
        ss << setw(2) << setfill('0') << hours << ":"
<< setw(2) << setfill('0') << minutes << ":"
           << setw(2) << setfill('0') << seconds;
        return ss.str();
    }

    void addSeconds(int sec) {
        seconds += sec;
        normalize();
    }

    void subtractSeconds(int sec) {
        seconds -= sec;
        normalize();
    }

    int differenceInSeconds(const TimeClass& other) const {
        int total1 = hours * 3600 + minutes * 60 + seconds;
        int total2 = other.hours * 3600 + other.minutes * 60 + other.seconds;
        return abs(total1 - total2);
    }

    bool isValid() const {
        return hours >= 0 && hours < 24 &&
               minutes >= 0 && minutes < 60 &&
               seconds >= 0 && seconds < 60;
    }

    int getHours() const { return hours; }
    int getMinutes() const { return minutes; }
    int getSeconds() const { return seconds; }
};


int main() {
    cout << "=== ЛАБОРАТОРНАЯ РАБОТА №2. СТРУКТУРЫ И КЛАССЫ ===" << endl << endl;

    // Демонстрация работы со структурой
    cout << "1. РАБОТА СО СТРУКТУРОЙ (внешние функции):" << endl;
    cout << "=============================================" << endl;

    TimeStruct time1;
    init(time1, 14, 30, 45);
    cout << "Инициализированное время: ";
    display(time1);
    cout << "Строковое представление: " << toString(time1) << endl;

    cout << endl << "Введите новое время:" << endl;
    read(time1);
    cout << "Введенное время: ";
    display(time1);

    // Операции со структурой
    addSeconds(time1, 90);
    cout << "После добавления 90 секунд: ";
    display(time1);

    subtractSeconds(time1, 45);
    cout << "После вычитания 45 секунд: ";
    display(time1);

    TimeStruct time2;
    init(time2, 15, 0, 0);
    cout << "Второе время: ";
    display(time2);
    cout << "Разница в секундах: " << differenceInSeconds(time1, time2) << endl;
    cout << "Корректное время: " << (isValidTime(time1) ? "Да" : "Нет") << endl;

    cout << endl << "2. РАБОТА С КЛАССОМ (методы класса):" << endl;
    cout << "========================================" << endl;

    TimeClass time3(23, 59, 30);
    cout << "Инициализированное время: ";
    time3.display();
    cout << "Строковое представление: " << time3.toString() << endl;

    cout << endl << "Введите новое время:" << endl;
    TimeClass time4;
    time4.read();
    cout << "Введенное время: ";
    time4.display();

    // Операции с классом
    time4.addSeconds(120);
    cout << "После добавления 120 секунд: ";
    time4.display();

    time4.subtractSeconds(60);
    cout << "После вычитания 60 секунд: ";
    time4.display();

    TimeClass time5(12, 0, 0);
    cout << "Второе время: ";
    time5.display();
    cout << "Разница в секундах: " << time4.differenceInSeconds(time5) << endl;
    cout << "Корректное время: " << (time4.isValid() ? "Да" : "Нет") << endl;

    // Демонстрация пограничных случаев
    cout << endl << "3. ДЕМОНСТРАЦИЯ ПОГРАНИЧНЫХ СЛУЧАЕВ:" << endl;
    cout << "========================================" << endl;

    TimeClass edgeCase(23, 59, 59);
    cout << "Начальное время: ";
    edgeCase.display();
    
    edgeCase.addSeconds(2);
    cout << "После добавления 2 секунд: ";
    edgeCase.display();

    edgeCase.subtractSeconds(3600);
    cout << "После вычитания 3600 секунд: ";
    edgeCase.display();

    return 0;
}
