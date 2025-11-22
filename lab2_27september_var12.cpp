#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

class Account {
private:
    string ownerLastName;
    string accountNumber;
    double interestRate;
    double balance;

public:
    Account() {
        ownerLastName = "";
        accountNumber = "";
        interestRate = 0.0;
        balance = 0.0;
    }
    
    Account(const string& lastName, const string& accNumber, double rate, double initialBalance) {
        ownerLastName = lastName;
        accountNumber = accNumber;
        interestRate = rate;
        balance = initialBalance;
    }
    
    Account(const Account& other) {
        ownerLastName = other.ownerLastName;
        accountNumber = other.accountNumber;
        interestRate = other.interestRate;
        balance = other.balance;
    }
    
    void changeOwner(const string& newOwner) {
        ownerLastName = newOwner;
    }
    
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }
    
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }
    
    void applyInterest() {
        balance += balance * (interestRate / 100.0);
    }
    
    double toDollars(double exchangeRate = 75.0) const {
        return balance / exchangeRate;
    }
    
    double toEuros(double exchangeRate = 85.0) const {
        return balance / exchangeRate;
    }
    
    string getAmountInWords() const {
        return convertToWords(balance);
    }
    
    string getOwner() const { return ownerLastName; }
    string getAccountNumber() const { return accountNumber; }
    double getInterestRate() const { return interestRate; }
    double getBalance() const { return balance; }
    
    void setInterestRate(double rate) { interestRate = rate; }
    
    void displayInfo() const {
        cout << "Владелец: " << ownerLastName << endl;
        cout << "Номер счета: " << accountNumber << endl;
        cout << "Процентная ставка: " << interestRate << "%" << endl;
        cout << "Баланс: " << fixed << setprecision(2) << balance << " руб." << endl;
    }
    
    // ПЕРЕГРУЗКИ ОПЕРАТОРОВ:
    
    // 1. Перегрузка оператора += (пополнение счета)
    Account& operator+=(double amount) {
        deposit(amount);
        return *this;
    }
    
    // 2. Перегрузка оператора -= (снятие со счета)
    Account& operator-=(double amount) {
        withdraw(amount);
        return *this;
    }
    
    // 3. Перегрузка оператора + (сложение балансов двух счетов)
    double operator+(const Account& other) const {
        return balance + other.balance;
    }
    
    // 4. Перегрузка оператора > (сравнение балансов)
    bool operator>(const Account& other) const {
        return balance > other.balance;
    }
    
    // 5. Перегрузка оператора << для вывода
    friend ostream& operator<<(ostream& os, const Account& acc) {
        os << "Владелец: " << acc.ownerLastName << endl;
        os << "Номер счета: " << acc.accountNumber << endl;
        os << "Процентная ставка: " << acc.interestRate << "%" << endl;
        os << "Баланс: " << fixed << setprecision(2) << acc.balance << " руб." << endl;
        return os;
    }

private:
    string convertToWords(double number) const {
        int rubles = static_cast<int>(number);
        int kopecks = static_cast<int>((number - rubles) * 100);
        
string units[10] = {"", "один", "два", "три", "четыре", "пять", "шесть", "семь", "восемь", "девять"};
        string teens[10] = {"десять", "одиннадцать", "двенадцать", "тринадцать", "четырнадцать", 
                           "пятнадцать", "шестнадцать", "семнадцать", "восемнадцать", "девятнадцать"};
        string tens[10] = {"", "десять", "двадцать", "тридцать", "сорок", "пятьдесят", 
                          "шестьдесят", "семьдесят", "восемьдесят", "девяносто"};
        string hundreds[10] = {"", "сто", "двести", "триста", "четыреста", "пятьсот", 
                              "шестьсот", "семьсот", "восемьсот", "девятьсот"};
        
        string result;
        
        if (rubles == 0) {
            result = "ноль рублей";
        } else {
            int thousands = rubles / 1000;
            if (thousands > 0) {
                if (thousands == 1) result += "одна тысяча ";
                else if (thousands == 2) result += "две тысячи ";
                else if (thousands == 3 || thousands == 4) result += units[thousands] + " тысячи ";
                else result += units[thousands] + " тысяч ";
                rubles %= 1000;
            }
        
            int hundred = rubles / 100;
            if (hundred > 0) {
                result += hundreds[hundred] + " ";
                rubles %= 100;
            }
            
            if (rubles >= 10 && rubles <= 19) {
                result += teens[rubles - 10] + " ";
            } else {
                int ten = rubles / 10;
                if (ten > 0) {
                    result += tens[ten] + " ";
                    rubles %= 10;
                }
                if (rubles > 0) {
                    result += units[rubles] + " ";
                }
            }
            
            int lastDigit = rubles % 10;
            int lastTwoDigits = rubles % 100;
            
            if (lastTwoDigits >= 11 && lastTwoDigits <= 19) {
                result += "рублей";
            } else if (lastDigit == 1) {
                result += "рубль";
            } else if (lastDigit >= 2 && lastDigit <= 4) {
                result += "рубля";
            } else {
                result += "рублей";
            }
        }
        
        if (kopecks > 0) {
            result += " " + to_string(kopecks) + " копеек";
        }
        
        return result;
    }
};

int main() {
    cout << "=== Демонстрация работы класса Account ===" << endl << endl;
    
    cout << "1. Создание счета с помощью конструктора инициализации:" << endl;
    Account account1("Иванов", "40817810099910004312", 5.5, 15000.0);
    account1.displayInfo();
    cout << endl;
    
    cout << "2. Создание счета с помощью конструктора без аргументов:" << endl;
    Account account2;
    account2.displayInfo();
    cout << endl;
    
    cout << "3. Создание счета с помощью конструктора копирования:" << endl;
    Account account3(account1);
    account3.displayInfo();
    cout << endl;

    cout << "4. Создание массива счетов:" << endl;
    Account accounts[3] = {
        Account("Петров", "40817810099910004313", 4.0, 25000.0),
        Account("Сидоров", "40817810099910004314", 6.0, 35000.0),
        Account("Кузнецов", "40817810099910004315", 3.5, 45000.0)
    };
    
    for (int i = 0; i < 3; i++) {
        cout << "Счет " << i + 1 << ":" << endl;
        accounts[i].displayInfo();
        cout << endl;
    }
    
    cout << "5. Демонстрация всех методов:" << endl;
    Account demoAccount("Смирнов", "40817810099910004316", 7.0, 10000.0);
    
    cout << "Исходное состояние:" << endl;
    demoAccount.displayInfo();
cout << endl;
    
    cout << "После смены владельца:" << endl;
    demoAccount.changeOwner("Васильев");
    demoAccount.displayInfo();
    cout << endl;
    
    cout << "После пополнения на 5000 руб.:" << endl;
    demoAccount.deposit(5000.0);
    demoAccount.displayInfo();
    cout << endl;
    
    cout << "После снятия 2000 руб.:" << endl;
    if (demoAccount.withdraw(2000.0)) {
        demoAccount.displayInfo();
    } else {
        cout << "Недостаточно средств!" << endl;
    }
    cout << endl;
    
    cout << "После начисления процентов:" << endl;
    demoAccount.applyInterest();
    demoAccount.displayInfo();
    cout << endl;
    
    cout << "Баланс в долларах: " << fixed << setprecision(2) 
         << demoAccount.toDollars() << " USD" << endl;
    cout << "Баланс в евро: " << fixed << setprecision(2) 
         << demoAccount.toEuros() << " EUR" << endl;
    cout << endl;
    
    cout << "Сумма прописью: " << demoAccount.getAmountInWords() << endl;
    cout << endl;
    
    cout << "6. Демонстрация суммы прописью для разных сумм:" << endl;
    Account test1("Тест", "00000000000000000001", 0.0, 1.0);
    Account test2("Тест", "00000000000000000002", 0.0, 1234.56);
    Account test3("Тест", "00000000000000000003", 0.0, 1000000.99);
    
    cout << "1 рубль: " << test1.getAmountInWords() << endl;
    cout << "1234.56 рубля: " << test2.getAmountInWords() << endl;
    cout << "1000000.99 рубля: " << test3.getAmountInWords() << endl;
    
    // 7. ДЕМОНСТРАЦИЯ ПЕРЕГРУЗОК ОПЕРАТОРОВ
    cout << "\n=== Демонстрация перегруженных операторов ===" << endl;
    
    Account acc1("Алексеев", "10000000000000000001", 5.0, 10000.0);
    Account acc2("Борисов", "10000000000000000002", 5.0, 20000.0);
    
    cout << "Исходные счета:" << endl;
    cout << "acc1:" << endl << acc1 << endl;
    cout << "acc2:" << endl << acc2 << endl;
    
    // Перегрузка +=
    cout << "После acc1 += 1500.50:" << endl;
    acc1 += 1500.50;
    cout << acc1 << endl;
    
    // Перегрузка -=
    cout << "После acc2 -= 3000.75:" << endl;
    acc2 -= 3000.75;
    cout << acc2 << endl;
    
    // Перегрузка +
    cout << "Сумма балансов acc1 + acc2: " << (acc1 + acc2) << " руб." << endl << endl;
    
    // Перегрузка >
    cout << "acc1 > acc2: " << (acc1 > acc2 ? "true" : "false") << endl;
    cout << "acc2 > acc1: " << (acc2 > acc1 ? "true" : "false") << endl << endl;
    
    // Перегрузка << (уже используется выше)
    cout << "Использование оператора << для вывода:" << endl;
    cout << acc1;
    
    return 0;
}
