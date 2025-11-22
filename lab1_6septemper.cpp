#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

static void die(const string& msg);
static double ipow_double(double base, long long exp);
static bool is_denom(int v);

// ============= 1 =============
class Pair1{
    double first; int second;
public:
    Pair1(double f=1,int s=0);
    void init(double f,int s);
    void input();
    void output();
    double power();
};

// ============= 2 =============
class Pair2{
    double first, second;
public:
    Pair2(double f=1,double s=1);
    void init(double f,double s);
    void input();
    void output();
    double power();
};

// ============= 3 =============
class Pair3{
    long long first, second;
public:
    Pair3(long long a=1,long long b=1);
    void init(long long a,long long b);
    void input();
    void output();
    long long ipart();
};

// ============= 4 =============
class Pair4{
    int first, second;
public:
    Pair4(int d=1,int c=1);
    void init(int d,int c);
    void input();
    void output();
    long long summa();
};

// ============= 5 =============
class Pair5{
    double first; int second;
public:
    Pair5(double p=1,int q=1);
    void init(double p,int q);
    void input();
    void output();
    double cost();
};

// ============= 6 =============
class Pair6{
    int first; double second;
public:
    Pair6(int k=100,double kg=0.1);
    void init(int k,double kg);
    void input();
    void output();
    double power(); // общая калорийность
};

// ============= 7 =============
class Pair7{
    double first, second;
public:
    Pair7(double l=0,double r=0);
    void init(double l,double r);
    void input();
    void output();
    bool rangecheck(double x);
};

// ============= 8 =============
class Pair8{
    int first, second;
public:
    Pair8(int l=0,int r=1);
    void init(int l,int r);
    void input();
    void output();
    bool rangecheck(int x);
};

// ============= 9 =============
class Pair9{
    int first, second;
public:
    Pair9(int h=0,int m=0);
    void init(int h,int m);
    void input();
    void output();
    int minutes();
};

// ============= 10 =============
class Pair10{
    double first, second; // A, B
public:
    Pair10(double A=0,double B=0);
    void init(double A,double B);
    void input();
    void output();
    double function(double x);
};

// ============= 11 =============
class Pair11{
    double first, second; // A, B
public:
    Pair11(double A=1,double B=0);
    void init(double A,double B);
    void input();
    void output();
    double root();
};

// ============= 12 =============
class Pair12{
    double first, second; // x, y
public:
    Pair12(double x=0,double y=0);
    void init(double x,double y);
    void input();
    void output();
    double distance();
};

// ============= 13 =============
class Pair13{
    double first, second; // a, b
public:
    Pair13(double a=1,double b=1);
    void init(double a,double b);
    void input();
    void output();
    double hypotenuse();
};

// ============= 14 =============
class Pair14{
    double first; int second; int daysInMonth;
public:
    Pair14(double s=30000,int dw=0,int dm=30);
    void init(double s,int dw,int dm);
    void input();
    void output();
    double summa();
};

// ============= 15 =============
class Pair15{
    int first; double second;
public:
    Pair15(int m=1,double c=1);
    void init(int m,double c);
    void input();
    void output();
    double cost();
};

// ============= 16 =============
class Pair16{
    double first, second; // int part, frac [0,1)
public:
    Pair16(double ip=0,double fp=0);
    void init(double ip,double fp);
    void input();
    void output();
    double multiply(double k);
};

// ============= 17 =============
class Pair17{
    int first, second, maxX, maxY;
public:
    Pair17(int x=0,int y=0,int MX=1920,int MY=1080);
    void init(int x,int y,int MX,int MY);
    void input();
    void output();
    void changex(int dx);
    void changey(int dy);
};
// ============= 18 =============
class Pair18{
    long long first; unsigned second; // frac in thousandths
public:
    Pair18(long long ip=0,unsigned ft=0);
    void init(long long ip,unsigned ft);
    void input();
    void output();
    long double multiply(int k);
};

// ============= 19 =============
class Pair19{
    int first, second; // k, n
public:
    Pair19(int k=0,int n=1);
    void init(int k,int n);
    void input();
    void output();
    long double combination();
};

// ============= 20 =============
class Pair20{
    double first, second; // a0, r
public:
    Pair20(double a0=1,double r=1);
    void init(double a0,double r);
    void input();
    void output();
    double elementj(long long j);
};

// ---------- РЕАЛИЗАЦИИ УТИЛИТ ----------
static void die(const string& msg){ cerr<<"Ошибка: "<<msg<<endl; exit(1); }
static double ipow_double(double base, long long exp){
    if (exp==0) return 1.0;
    bool neg = exp<0; long long e = neg? -exp:exp;
    long double r=1.0L, b=base;
    while(e){ if(e&1) r*=b; b*=b; e>>=1; }
    return neg? (1.0/(double)r) : (double)r;
}
static bool is_denom(int v){
    const int d[9]={1,2,5,10,50,100,500,1000,5000};
    for(int i=0;i<9;i++) if(d[i]==v) return true;
    return false;
}

// ---------- РЕАЛИЗАЦИИ КЛАССОВ ----------
// 1
Pair1::Pair1(double f,int s){ init(f,s); }
void  Pair1::init(double f,int s){ first=f; second=s; }
void  Pair1::input(){ cout<<"[1] Введите first(double) и second(int): "; if(!(cin>>first>>second)) die("Некорректный ввод"); }
void  Pair1::output(){ cout<<"[1] {first="<<first<<", second="<<second<<"}"; }
double Pair1::power(){ if(first==0.0 && second==0) return 1.0; return ipow_double(first,second); }

// 2
Pair2::Pair2(double f,double s){ init(f,s); }
void  Pair2::init(double f,double s){
    if(f<0 && floor(s)!=s) die("Отрицательное в нецелую степень нельзя .");
    first=f; second=s;
}
void  Pair2::input(){
    cout<<"[2] Введите first(double) и second(double): ";
    if(!(cin>>first>>second)) die("Некорректный ввод");
    if(first<0 && floor(second)!=second) die("Отрицательное в нецелую степень нельзя");
}
void  Pair2::output(){ cout<<"[2] {first="<<first<<", second="<<second<<"}"; }
double Pair2::power(){ if(first==0.0 && second==0.0) return 1.0; return pow(first,second); }

// 3
Pair3::Pair3(long long a,long long b){ init(a,b); }
void  Pair3::init(long long a,long long b){
    if(a<=0||b<=0) die("Числитель/знаменатель >0");
    if(b==0) die("Знаменатель = 0");
    first=a; second=b;
}
void  Pair3::input(){
    cout<<"[3] Введите числитель>0 и знаменатель>0: ";
    if(!(cin>>first>>second)) die("Некорректный ввод");
    if(first<=0||second<=0) die("Числитель/знаменатель >0");
}
void  Pair3::output(){ cout<<"[3] {num="<<first<<", den="<<second<<"}"; }
long long Pair3::ipart(){ return first/second; }

// 4
Pair4::Pair4(int d,int c){ init(d,c); }
void  Pair4::init(int d,int c){
    if(!is_denom(d)) die("Недопустимый номинал");
    if(c<=0) die("Количество >0");
    first=d; second=c;
}
void  Pair4::input(){
    cout<<"[4] Введите номинал и количество: ";
    if(!(cin>>first>>second)) die("Некорректный ввод");
    if(!is_denom(first)||second<=0) die("Неверные данные по купюрам");
}
void  Pair4::output(){ cout<<"[4] {denom="<<first<<", count="<<second<<"}"; }
long long Pair4::summa(){ return 1LL*first*second; }

// 5
Pair5::Pair5(double p,int q){ init(p,q); }
void  Pair5::init(double p,int q){ if(p<=0||q<=0) die("Цена/количество >0"); first=p; second=q; }
void  Pair5::input(){
    cout<<"[5] Введите цену>0 и количество>0: ";
    if(!(cin>>first>>second)) die("Некорректный ввод");
    if(first<=0||second<=0) die("Должно быть >0");
}
void  Pair5::output(){ cout<<"[5] {price="<<first<<", qty="<<second<<"}"; }
double Pair5::cost(){ return first*second; }
// 6
Pair6::Pair6(int k,double kg){ init(k,kg); }
void  Pair6::init(int k,double kg){ if(k<=0||kg<=0) die("Ккал/100г и масса >0"); first=k; second=kg; }
void  Pair6::input(){
    cout<<"[6] Введите ккал/100г (>0) и массу кг (>0): ";
    if(!(cin>>first>>second)) die("Некорректный ввод");
    if(first<=0||second<=0) die("Неверные данные");
}
void  Pair6::output(){ cout<<"[6] {kcal100="<<first<<", kg="<<second<<"}"; }
double Pair6::power(){ return (first/100.0)*(second*1000.0); }

// 7
Pair7::Pair7(double l,double r){ init(l,r); }
void  Pair7::init(double l,double r){ if(l>r) die("Левая граница > правой"); first=l; second=r; }
void  Pair7::input(){
    cout<<"[7] Введите левую и правую границы (double): ";
    if(!(cin>>first>>second)) die("Некорректный ввод");
    if(first>second) die("Левая > правой");
}
void  Pair7::output(){ cout<<"[7] ["<<first<<"; "<<second<<"]"; }
bool  Pair7::rangecheck(double x){ return x>=first && x<=second; }

// 8
Pair8::Pair8(int l,int r){ init(l,r); }
void  Pair8::init(int l,int r){ if(l>=r) die("Нужно l<r"); first=l; second=r; }
void  Pair8::input(){
    cout<<"[8] Введите левую(вкл) и правую(не вкл) границы (int): ";
    if(!(cin>>first>>second)) die("Некорректный ввод");
    if(first>=second) die("l<r");
}
void  Pair8::output(){ cout<<"[8] ["<<first<<"; "<<second<<")"; }
bool  Pair8::rangecheck(int x){ return x>=first && x<second; }

// 9
Pair9::Pair9(int h,int m){ init(h,m); }
void  Pair9::init(int h,int m){
    if(h<0) die("Часы >=0");
    if(m<0||m>=60) die("Минуты [0,59]");
    first=h; second=m;
}
void  Pair9::input(){
    cout<<"[9] Введите часы(>=0) и минуты[0..59]: ";
    if(!(cin>>first>>second)) die("Некорректный ввод");
    if(first<0||second<0||second>=60) die("Неверное время");
}
void  Pair9::output(){ cout<<"[9] {h="<<first<<", m="<<second<<"}"; }
int   Pair9::minutes(){ return first*60+second; }

// 10
Pair10::Pair10(double A,double B){ init(A,B); }
void  Pair10::init(double A,double B){ first=A; second=B; }
void  Pair10::input(){ cout<<"[10] Введите A и B: "; if(!(cin>>first>>second)) die("Некорректный ввод"); }
void  Pair10::output(){ cout<<"[10] {A="<<first<<", B="<<second<<"}"; }
double Pair10::function(double x){ return first*x + second; }

// 11
Pair11::Pair11(double A,double B){ init(A,B); }
void  Pair11::init(double A,double B){ if(A==0.0) die("A != 0"); first=A; second=B; }
void  Pair11::input(){
    cout<<"[11] Введите A(!=0) и B: ";
    if(!(cin>>first>>second)) die("Некорректный ввод");
    if(first==0.0) die("A != 0");
}
void  Pair11::output(){ cout<<"[11] {A="<<first<<", B="<<second<<"}"; }
double Pair11::root(){ return -second/first; }

// 12
Pair12::Pair12(double x,double y){ init(x,y); }
void  Pair12::init(double x,double y){ first=x; second=y; }
void  Pair12::input(){ cout<<"[12] Введите x и y: "; if(!(cin>>first>>second)) die("Некорректный ввод"); }
void  Pair12::output(){ cout<<"[12] P("<<first<<","<<second<<")"; }
double Pair12::distance(){ return hypot(first,second); }

// 13
Pair13::Pair13(double a,double b){ init(a,b); }
void  Pair13::init(double a,double b){ if(a<=0||b<=0) die("Катеты >0"); first=a; second=b; }
void  Pair13::input(){
    cout<<"[13] Введите a>0 и b>0: ";
    if(!(cin>>first>>second)) die("Некорректный ввод");
    if(first<=0||second<=0) die("Катеты >0");
}
void  Pair13::output(){ cout<<"[13] {a="<<first<<", b="<<second<<"}"; }
double Pair13::hypotenuse(){ return hypot(first,second); }

// 14
Pair14::Pair14(double s,int dw,int dm){ init(s,dw,dm); }
void  Pair14::init(double s,int dw,int dm){
    if(s<=0) die("Оклад >0");
    if(dm<=0||dw<0||dw>dm) die("0<=отраб<=дни_месяца");
    first=s; second=dw; daysInMonth=dm;
}
void  Pair14::input(){
    cout<<"[14] Введите оклад>0, дни_месяца>0, отработанные дни: ";
    int dm;
    if(!(cin>>first>>dm>>second)) die("Некорректный ввод");
    if(first<=0||dm<=0||second<0||second>dm) die("Неверные дни/оклад");
    daysInMonth=dm;
}
void  Pair14::output(){ cout<<"[14] {salary="<<first<<", worked="<<second<<", days="<<daysInMonth<<"}"; }
double Pair14::summa(){ return first/daysInMonth*second; }
// 15
Pair15::Pair15(int m,double c){ init(m,c); }
void  Pair15::init(int m,double c){ if(m<=0||c<=0) die("минуты>0, цена/мин>0"); first=m; second=c; }
void  Pair15::input(){
    cout<<"[15] Введите минуты>0 и цену/мин>0: ";
    if(!(cin>>first>>second)) die("Некорректный ввод");
    if(first<=0||second<=0) die("Неверные данные");
}
void  Pair15::output(){ cout<<"[15] {min="<<first<<", p/min="<<second<<"}"; }
double Pair15::cost(){ return first*second; }

// 16
Pair16::Pair16(double ip,double fp){ init(ip,fp); }
void  Pair16::init(double ip,double fp){
    if(fp<0.0||fp>=1.0) die("Дробная часть [0,1)");
    first = (ip>=0 ? floor(ip) : ceil(ip));
    second= fp;
}
void  Pair16::input(){
    cout<<"[16] Введите целую часть и дробную [0,1): ";
    if(!(cin>>first>>second)) die("Некорректный ввод");
    if(second<0.0||second>=1.0) die("Дробная часть [0,1)");
    first = (first>=0 ? floor(first) : ceil(first));
}
void  Pair16::output(){ cout<<"[16] {int="<<first<<", frac="<<second<<"}"; }
double Pair16::multiply(double k){ return (first+second)*k; }

// 17
Pair17::Pair17(int x,int y,int MX,int MY){ init(x,y,MX,MY); }
void  Pair17::init(int x,int y,int MX,int MY){
    if(MX<=0||MY<=0) die("Размеры экрана >0");
    if(x<0||y<0||x>MX||y>MY) die("Начальные координаты вне экрана");
    first=x; second=y; maxX=MX; maxY=MY;
}
void  Pair17::input(){
    cout<<"[17] Введите maxX>0, maxY>0, x>=0, y>=0: ";
    if(!(cin>>maxX>>maxY>>first>>second)) die("Некорректный ввод");
    if(maxX<=0||maxY<=0||first<0||second<0||first>maxX||second>maxY) die("Неверные координаты/размеры");
}
void  Pair17::output(){ cout<<"[17] {x="<<first<<", y="<<second<<", maxX="<<maxX<<", maxY="<<maxY<<"}"; }
void  Pair17::changex(int dx){
    long long nx=(long long)first+dx; if(nx<0||nx>maxX) die("Выход X за экран"); first=(int)nx;
}
void  Pair17::changey(int dy){
    long long ny=(long long)second+dy; if(ny<0||ny>maxY) die("Выход Y за экран"); second=(int)ny;
}

// 18
Pair18::Pair18(long long ip,unsigned ft){ init(ip,ft); }
void  Pair18::init(long long ip,unsigned ft){ if(ft>=1000u) die("Тысячные [0..999]"); first=ip; second=ft; }
void  Pair18::input(){
    cout<<"[18] Введите целую часть и дробную (тысячные [0..999]): ";
    if(!(cin>>first>>second)) die("Некорректный ввод");
    if(second>=1000u) die("Дробная часть [0..999]");
}
void  Pair18::output(){ cout<<"[18] {int="<<first<<", frac_thousand="<<second<<"}"; }
long double Pair18::multiply(int k){
    long double v=(long double)first+(long double)second/1000.0L; return v*(long double)k;
}

// 19
Pair19::Pair19(int k,int n){ init(k,n); }
void  Pair19::init(int k,int n){ if(n<=0||k<0||k>=n) die("0<=k<n, n>0"); first=k; second=n; }
void  Pair19::input(){
    cout<<"[19] Введите k и n (0<=k<n): ";
    if(!(cin>>first>>second)) die("Некорректный ввод");
    if(second<=0||first<0||first>=second) die("0<=k<n");
}
void  Pair19::output(){ cout<<"[19] {k="<<first<<", n="<<second<<"}"; }
long double Pair19::combination(){
    int k=first,n=second,kk=(k<n-k?k:n-k);
    long double num=1.0,den=1.0;
    for(int i=1;i<=kk;i++){ num*=(n-kk+i); den*=i; }
    return num/den;
}

// 20
Pair20::Pair20(double a0,double r){ init(a0,r); }
void  Pair20::init(double a0,double r){ first=a0; second=r; }
void  Pair20::input(){ cout<<"[20] Введите a0 и r: "; if(!(cin>>first>>second)) die("Некорректный ввод"); }
void  Pair20::output(){ cout<<"[20] {a0="<<first<<", r="<<second<<"}"; }
double Pair20::elementj(long long j){
    if(j<0) die("j>=0"); if(j==0) return first; return first*ipow_double(second,j);
}
// ---------- МЕНЮ ----------
int main(){
    cout.setf(ios::fixed); cout<<setprecision(6);
    int choice;
    do{
        cout<<"\n=== МЕНЮ ЛР №1: Структура-пара (ручной ввод, реализации вне классов) ===\n";
        cout<<"1  – Задание 1 (power int)\n";
        cout<<"2  – Задание 2 (power real)\n";
        cout<<"3  – Задание 3 (ipart fraction)\n";
        cout<<"4  – Задание 4 (cash summa)\n";
        cout<<"5  – Задание 5 (item cost)\n";
        cout<<"6  – Задание 6 (calories)\n";
        cout<<"7  – Задание 7 (range real)\n";
        cout<<"8  – Задание 8 (range half-open int)\n";
        cout<<"9  – Задание 9 (time to minutes)\n";
        cout<<"10 – Задание 10 (linear function)\n";
        cout<<"11 – Задание 11 (linear root)\n";
        cout<<"12 – Задание 12 (point distance)\n";
        cout<<"13 – Задание 13 (hypotenuse)\n";
        cout<<"14 – Задание 14 (salary summa)\n";
        cout<<"15 – Задание 15 (call cost)\n";
        cout<<"16 – Задание 16 (real parts * double)\n";
        cout<<"17 – Задание 17 (cursor move bounds)\n";
        cout<<"18 – Задание 18 (int parts * int)\n";
        cout<<"19 – Задание 19 (combinations)\n";
        cout<<"20 – Задание 20 (geom progression)\n";
        cout<<"0  – Выход\n";
        cout<<"Выбор: ";
        if(!(cin>>choice)) { cout<<"\nЗавершение.\n"; return 0; }
switch(choice){
            case 1: { Pair1 a; a.input(); a.output(); cout<<" power="<<a.power()<<"\n"; } break;
            case 2: { Pair2 a; a.input(); a.output(); cout<<" power="<<a.power()<<"\n"; } break;
            case 3: { Pair3 a; a.input(); a.output(); cout<<" ipart="<<a.ipart()<<"\n"; } break;
            case 4: { Pair4 a; a.input(); a.output(); cout<<" summa="<<a.summa()<<"\n"; } break;
            case 5: { Pair5 a; a.input(); a.output(); cout<<" cost="<<a.cost()<<"\n"; } break;
            case 6: { Pair6 a; a.input(); a.output(); cout<<" kcal="<<a.power()<<"\n"; } break;
            case 7: { Pair7 a; a.input(); double x; cout<<"[7] Введите x: "; if(!(cin>>x)) die("Некорректный ввод x");
                      a.output(); cout<<" -> "<<(a.rangecheck(x)?"in":"out")<<"\n"; } break;
            case 8: { Pair8 a; a.input(); int x; cout<<"[8] Введите x (int): "; if(!(cin>>x)) die("Некорректный ввод x");
                      a.output(); cout<<" -> "<<(a.rangecheck(x)?"in":"out")<<"\n"; } break;
            case 9: { Pair9 a; a.input(); a.output(); cout<<" minutes="<<a.minutes()<<"\n"; } break;
            case 10:{ Pair10 a; a.input(); double x; cout<<"[10] Введите x: "; if(!(cin>>x)) die("Некорректный ввод x");
                      a.output(); cout<<" y="<<a.function(x)<<"\n"; } break;
            case 11:{ Pair11 a; a.input(); a.output(); cout<<" root="<<a.root()<<"\n"; } break;
            case 12:{ Pair12 a; a.input(); a.output(); cout<<" dist="<<a.distance()<<"\n"; } break;
            case 13:{ Pair13 a; a.input(); a.output(); cout<<" hyp="<<a.hypotenuse()<<"\n"; } break;
            case 14:{ Pair14 a; a.input(); a.output(); cout<<" summa="<<a.summa()<<"\n"; } break;
            case 15:{ Pair15 a; a.input(); a.output(); cout<<" cost="<<a.cost()<<"\n"; } break;
            case 16:{ Pair16 a; a.input(); double k; cout<<"[16] Введите множитель k: "; if(!(cin>>k)) die("Некорректный ввод k");
                      a.output(); cout<<" result="<<a.multiply(k)<<"\n"; } break;
            case 17:{ Pair17 a; a.input(); a.output(); cout<<"\n[17] Введите dx и dy: ";
                      int dx,dy; if(!(cin>>dx>>dy)) die("Некорректный ввод dx/dy");
                      a.changex(dx); a.changey(dy); cout<<" -> после сдвига: "; a.output(); cout<<"\n"; } break;
            case 18:{ Pair18 a; a.input(); int k; cout<<"[18] Введите целый множитель k: "; if(!(cin>>k)) die("Некорректный ввод k");
                      a.output(); cout<<" result="<<(double)a.multiply(k)<<"\n"; } break;
            case 19:{ Pair19 a; a.input(); a.output(); cout.setf(ios::fixed); cout<<setprecision(0)
                      <<" C(n,k)="<<a.combination()<<"\n"<<setprecision(6); } break;
            case 20:{ Pair20 a; a.input(); long long j; cout<<"[20] Введите j (>=0): "; if(!(cin>>j)) die("Некорректный ввод j");
                      a.output(); cout<<" a_j="<<a.elementj(j)<<"\n"; } break;
            case 0: cout<<"Выход.\n"; break;
            default: cout<<"Неверный пункт.\n";
        }
    }while(choice!=0);

    return 0;
}
