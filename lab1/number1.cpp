#include <iostream>
#include <cmath>

using namespace std;

struct PowerInt{
    double first;
    int second;
    
    void init(double base, int exponent){
        if(base == 0 && exponent <=0){
            throw invalid_argument("недопустимое значение ");
        }
        first = base;
        second = exponent;
    }
    
    void read(){
        cout<<"Введите основное дробное число: "; 
        cin>> first;
        cout<<"Введите показатель степени (целое число): ";
        cin>>second;
        if(first == 0 && second <=0){
            throw invalid_argument("недопустимое значение ");
        }
    }
    
    void display() const{
        cout<<first<<" "<<second;
    }
    
    double power()const{
        return pow(first, second);
    }
}

PowerInt make_PowerInt(double base,int exponent){
    if(base == 0 && exponent <=0){
        throw invalid_argument("недопустимое значение ");
    }
    PowP p;
    p.init(base,exponent);
    return p;
}
