#include<iostream>
#include <locale>
using namespace std;

int getNod(int x, int y)
{
    if (y == 0)
        return x;
    return getNod(y, x % y);
}
class Rational{
private:
    int a;
    int b; // a/b
public:
explicit Rational(int num){
    a = num;
    b = 1;
}
Rational(int a1, int b1){
    if(b1 == 0)
        __throw_invalid_argument("Error!");
    if(a1 == 0){
        a = 0;
        b = 1;
    }
    else{
        int nod = getNod(a1, b1);
        a = a1 / nod;
        b = b1 / nod;
    }
}
Rational operator+(Rational r2){
    int rezc = this->a * r2.b + r2.a * this->b;
    int rezz = this->b * r2.b;
    int nod = getNod(rezc, rezz);
    rezc /= nod; rezz /= nod;
    Rational rez = Rational(rezc, rezz);
    return rez;
}
Rational operator-(Rational r2){
    int rezc = this->a * r2.b - r2.a * this->b;
    int rezz = (this->b) * r2.b;
    int nod = getNod(rezc, rezz);
    rezc /= nod; rezz /= nod;
    Rational rez = Rational(rezc, rezz);
    return rez;
}
    Rational operator*(Rational r2){
        int rezc = this->a * r2.a;
        int rezz = this->b * r2.b;
        int nod = getNod(rezc, rezz);
        rezc /= nod; rezz /= nod;
        Rational rez = Rational(rezc, rezz);
        return rez;
    }

    Rational operator/(Rational r2){
        int rezc = this->a * r2.b;
        int rezz = this->b * r2.a;
        int nod = getNod(rezc, rezz);
        rezc /= nod; rezz /= nod;
        Rational rez = Rational(rezc, rezz);
        return rez;
    }
    void Print(){
    cout << a << "/" << b << endl;
}
};
int main(){
    Rational a = Rational(5,4);
    Rational b = Rational(9,10);
    Rational c = a * b;
    c.Print();
}