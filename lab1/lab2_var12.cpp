#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;

// Структура Account
struct Account {
    string ownerSurname;
    long accountNumber;
    double interestRate;
    double balance;
};

// Метод инициализации
void init(Account& acc, const string& surname, long number, double rate, double initialBalance) {
    acc.ownerSurname = surname;
    acc.accountNumber = number;
    acc.interestRate = rate;
    acc.balance = initialBalance;
}

// Ввод с клавиатуры
void read(Account& acc) {
    cout << "Введите фамилию владельца: ";
    cin >> acc.ownerSurname;
    cout << "Введите номер счета: ";
    cin >> acc.accountNumber;
    cout << "Введите процент начисления: ";
    cin >> acc.interestRate;
    cout << "Введите начальный баланс: ";
    cin >> acc.balance;
}

// Вывод на экран
void display(const Account& acc) {
    cout << "Владелец: " << acc.ownerSurname << endl;
    cout << "Номер счета: " << acc.accountNumber << endl;
    cout << "Процентная ставка: " << acc.interestRate << "%" << endl;
    cout << "Баланс: " << fixed << setprecision(2) << acc.balance << " руб." << endl;
}

// Преобразование в строку
string toString(const Account& acc) {
    stringstream ss;
    ss << "Владелец: " << acc.ownerSurname 
       << ", Счет: " << acc.accountNumber 
       << ", Ставка: " << acc.interestRate << "%"
       << ", Баланс: " << fixed << setprecision(2) << acc.balance << " руб.";
    return ss.str();
}

// Сменить владельца счета
void changeOwner(Account& acc, const string& newSurname) {
    acc.ownerSurname = newSurname;
}

// Снять деньги со счета
bool withdraw(Account& acc, double amount) {
    if (amount > 0 && amount <= acc.balance) {
        acc.balance -= amount;
        return true;
    }
    return false;
}

// Положить деньги на счет
void deposit(Account& acc, double amount) {
    if (amount > 0) {
        acc.balance += amount;
    }
}

// Начислить проценты
void addInterest(Account& acc) {
    acc.balance += acc.balance * (acc.interestRate / 100);
}

// Перевести в доллары (курс приблизительный)
double toDollars(const Account& acc, double exchangeRate = 90.0) {
    return acc.balance / exchangeRate;
}

// Перевести в евро (курс приблизительный)
double toEuros(const Account& acc, double exchangeRate = 100.0) {
    return acc.balance / exchangeRate;
}

// Получить сумму прописью (упрощенная версия)
string amountInWords(double amount) {
    int rubles = static_cast<int>(amount);
    int kopecks = static_cast<int>((amount - rubles) * 100);
    
    string units[] = {"", "один", "два", "три", "четыре", "пять", "шесть", "семь", "восемь", "девять"};
    string teens[] = {"десять", "одиннадцать", "двенадцать", "тринадцать", "четырнадцать", "пятнадцать", 
                     "шестнадцать", "семнадцать", "восемнадцать", "девятнадцать"};
    string tens[] = {"", "десять", "двадцать", "тридцать", "сорок", "пятьдесят", 
                    "шестьдесят", "семьдесят", "восемьдесят", "девяносто"};
    string hundreds[] = {"", "сто", "двести", "триста", "четыреста", "пятьсот", 
                        "шестьсот", "семьсот", "восемьсот", "девятьсот"};
    
    string result;
    
    // Обрабатываем рубли
    if (rubles == 0) {
        result = "ноль рублей ";
    } else {
        // Тысячи
        int thousands = rubles / 1000;
        if (thousands > 0) {
            // Упрощенная обработка тысяч
            result += to_string(thousands) + " тысяч ";
            rubles %= 1000;
        }
        
        // Сотни
        int hundred = rubles / 100;
        if (hundred > 0) {
            result += hundreds[hundred] + " ";
            rubles %= 100;
        }
        
        // Десятки и единицы
        if (rubles >= 10 && rubles < 20) {
            result += teens[rubles - 10] + " ";
        } else {
            int ten = rubles / 10;
            if (ten > 0) {
                result += tens[ten] + " ";
            }
            int unit = rubles % 10;
            if (unit > 0) {
                result += units[unit] + " ";
            }
        }
// Правильное окончание для рублей
        int lastDigit = rubles % 10;
        if (lastDigit == 1 && rubles != 11) {
            result += "рубль ";
        } else if (lastDigit >= 2 && lastDigit <= 4 && (rubles < 10 || rubles > 20)) {
            result += "рубля ";
        } else {
            result += "рублей ";
        }
    }
    
    // Копейки
    result += to_string(kopecks) + " копеек";
    
    return result;
}

// Демонстрация работы со структурой
void demoStruct() {
    cout << "=== РЕАЛИЗАЦИЯ ЧЕРЕЗ СТРУКТУРУ ===" << endl;
    
    Account myAccount;
    init(myAccount, "Иванов", 1234567890, 5.0, 10000.0);
    
    cout << "Исходный счет:" << endl;
    display(myAccount);
    cout << endl;
    
    // Операции со счетом
    changeOwner(myAccount, "Петров");
    deposit(myAccount, 5000.0);
    withdraw(myAccount, 2000.0);
    addInterest(myAccount);
    cout << "После операций:" << endl;
    display(myAccount);
    cout << endl;
    cout << "В долларах: " << toDollars(myAccount) << " USD" << endl;
    cout << "В евро: " << toEuros(myAccount) << " EUR" << endl;
    cout << "Сумма прописью: " << amountInWords(myAccount.balance) << endl;
    cout << "Строковое представление: " << toString(myAccount) << endl;}
    
class AccountClass {
private:
    string ownerSurname;
    long accountNumber;
    double interestRate;
    double balance;

public:
    // Конструктор инициализации
    AccountClass(const string& surname = "", long number = 0, 
                double rate = 0.0, double initialBalance = 0.0) {
        ownerSurname = surname;
        accountNumber = number;
        interestRate = rate;
        balance = initialBalance;
    }

    // Ввод с клавиатуры
    void read() {
        cout << "Введите фамилию владельца: ";
        cin >> ownerSurname;
        cout << "Введите номер счета: ";
        cin >> accountNumber;
        cout << "Введите процент начисления: ";
        cin >> interestRate;
        cout << "Введите начальный баланс: ";
        cin >> balance;
    }

    // Вывод на экран
    void display() const {
        cout << "Владелец: " << ownerSurname << endl;
        cout << "Номер счета: " << accountNumber << endl;
        cout << "Процентная ставка: " << interestRate << "%" << endl;
        cout << "Баланс: " << fixed << setprecision(2) << balance << " руб." << endl;
    }

    // Преобразование в строку
    string toString() const {
        stringstream ss;
        ss << "Владелец: " << ownerSurname 
           << ", Счет: " << accountNumber 
           << ", Ставка: " << interestRate << "%"
           << ", Баланс: " << fixed << setprecision(2) << balance << " руб.";
        return ss.str();
    }

    // Сменить владельца счета
    void changeOwner(const string& newSurname) {
        ownerSurname = newSurname;
    }

    // Снять деньги со счета
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }

    // Положить деньги на счет
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    // Начислить проценты
    void addInterest() {
        balance += balance * (interestRate / 100);
    }

    // Перевести в доллары
    double toDollars(double exchangeRate = 90.0) const {
        return balance / exchangeRate;
    }

    // Перевести в евро
    double toEuros(double exchangeRate = 100.0) const {
        return balance / exchangeRate;
    }

    // Получить сумму прописью
    string amountInWords() const {
        return ::amountInWords(balance);
    }

    // Геттеры для доступа к приватным полям
    string getOwnerSurname() const { return ownerSurname; }
    long getAccountNumber() const { return accountNumber; }
    double getInterestRate() const { return interestRate; }
    double getBalance() const { return balance; }

    // Сеттеры (опционально)
    void setInterestRate(double rate) { 
        if (rate >= 0) interestRate = rate; 
    }
};

// Демонстрация работы с классом
void demoClass() {
    cout << "\n=== РЕАЛИЗАЦИЯ ЧЕРЕЗ КЛАСС ===" << endl;
    
    AccountClass myAccount("Сидоров", 9876543210, 7.5, 15000.0);
    
    cout << "Исходный счет:" << endl;
    myAccount.display();
    cout << endl;
    
    // Операции со счетом
    myAccount.changeOwner("Кузнецов");
    myAccount.deposit(3000.0);
    myAccount.withdraw(1000.0);
    myAccount.addInterest();
    
    cout << "После операций:" << endl;
    myAccount.display();
    cout << endl;
    
    cout << "В долларах: " << myAccount.toDollars() << " USD" << endl;
    cout << "В евро: " << myAccount.toEuros() << " EUR" << endl;
    cout << "Сумма прописью: " << myAccount.amountInWords() << endl;
    cout << "Строковое представление: " << myAccount.toString() << endl;
}

// Главная функция
int main() {
    demoStruct();
    demoClass();
    
    return 0;
}
