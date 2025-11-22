#include <iostream>
#include <string>
#include <stdexcept>

using string = std::string;
using invalid_argument = std::invalid_argument;
using cout = std::cout;
using abs = std::abs;

struct Date {
    int year;
    int month;
    int day;
};

class DateErrorEmpty {};

class DateErrorParams {
public:
    int year, month, day;
    string message;
    DateErrorParams(int y, int m, int d, const string& msg) {
        year = y;
        month = m;
        day = d;
        message = msg;
    }
};

class DateErrorInherit : public invalid_argument {
public:
    int year, month, day;
    DateErrorInherit(int y, int m, int d, const string& msg) : invalid_argument(msg) {
        year = y;
        month = m;
        day = d;
    }
};

bool isValidDate(const Date& date) {
    if (date.month < 1 || date.month > 12) return false;
    if (date.day < 1) return false;
    
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (date.year % 4 == 0 && (date.year % 100 != 0 || date.year % 400 == 0))
        daysInMonth[1] = 29;
    
    return date.day <= daysInMonth[date.month - 1];
}

int dateToDays(const Date& date) {
    int days = date.year * 365 + date.day;
    for (int i = 1; i < date.month; i++) {
        days += 30; 
    }
    days += date.year / 4 - date.year / 100 + date.year / 400;
    return days;
}

// Вариант 1: Без спецификации исключений
int diffDatesNoSpec(const Date& date1, const Date& date2) {
    if (!isValidDate(date1)) {
        throw invalid_argument("Invalid first date");
    }
    if (!isValidDate(date2)) {
        throw invalid_argument("Invalid second date");
    }
    return abs(dateToDays(date1) - dateToDays(date2));
}

// Вариант 2: Имитация пустой спецификации 
int diffDatesEmptyThrow(const Date& date1, const Date& date2) {
    if (!isValidDate(date1)) {
        throw invalid_argument("Invalid first date");
    }
    if (!isValidDate(date2)) {
        throw invalid_argument("Invalid second date");
    }
    return abs(dateToDays(date1) - dateToDays(date2));
}

// Вариант 3: Имитация спецификации со стандартным исключением
int diffDatesStdSpec(const Date& date1, const Date& date2) {
    if (!isValidDate(date1)) {
        throw invalid_argument("Invalid first date");
    }
    if (!isValidDate(date2)) {
        throw invalid_argument("Invalid second date");
    }
    return abs(dateToDays(date1) - dateToDays(date2));
}

// Вариант 4: Использование собственных исключений
int diffDatesCustom(const Date& date1, const Date& date2) {
    if (!isValidDate(date1)) {
        throw DateErrorInherit(date1.year, date1.month, date1.day, 
            "Invalid first date");
    }
    if (!isValidDate(date2)) {
        throw DateErrorParams(date2.year, date2.month, date2.day, 
            "Invalid second date");
    }
    return abs(dateToDays(date1) - dateToDays(date2));
}

int main() {
    Date date1 = {2023, 5, 15};
    Date date2 = {2023, 6, 15};
    Date invalidDate = {2023, 13, 1}; // Некорректный месяц

    try {
        // Вариант 1
        cout << "No spec: " << diffDatesNoSpec(date1, date2) << " days\n";
        cout << "No spec (invalid): " << diffDatesNoSpec(date1, invalidDate) << "\n";
    }
catch (const invalid_argument& e) {
        cout << "No spec error: " << e.what() << "\n";
    }

    try {
        // Вариант 2
        cout << "Empty throw: " << diffDatesEmptyThrow(date1, date2) << " days\n";
        cout << "Empty throw (invalid): " << diffDatesEmptyThrow(date1, invalidDate) << "\n";
    }
    catch (const invalid_argument& e) {
        cout << "Empty throw error: " << e.what() << "\n";
    }

    try {
        // Вариант 3
        cout << "Std spec: " << diffDatesStdSpec(date1, date2) << " days\n";
        cout << "Std spec (invalid): " << diffDatesStdSpec(date1, invalidDate) << "\n";
    }
    catch (const invalid_argument& e) {
        cout << "Std spec error: " << e.what() << "\n";
    }

    try {
        // Вариант 4
        cout << "Custom spec: " << diffDatesCustom(date1, date2) << " days\n";
        cout << "Custom spec (invalid): " << diffDatesCustom(date1, invalidDate) << "\n";
    }
    catch (const DateErrorEmpty& e) {
        cout << "Custom empty error caught\n";
    }
    catch (const DateErrorParams& e) {
        cout << "Custom params error: " << e.message 
             << " (Date: " << e.year << "-" << e.month << "-" << e.day << ")\n";
    }
    catch (const DateErrorInherit& e) {
        cout << "Custom inherit error: " << e.what() 
             << " (Date: " << e.year << "-" << e.month << "-" << e.day << ")\n";
    }
    catch (...) {
        cout << "Unexpected error\n";
    }

    return 0;
}
