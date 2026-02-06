#include<iostream>
using namespace std;

class Fraction {
public:
    int num;
    int den;

    Fraction(int num, int den) {
        this->num = num;
        this->den = den;
    }
    void display() {
        cout<<num<<" / "<<den<<endl;
    }
    // Fraction add(Fraction f) {
    //     int newnum = this->num*f.den + this->den*f.num;
    //     int newden = this->den*f.den;
    //     Fraction ans(newnum ,newden);
    //     return ans;
    // }

        Fraction operator+(Fraction f) {
        int newnum = this->num*f.den + this->den*f.num;
        int newden = this->den*f.den;
        Fraction ans(newnum ,newden);
        return ans;
    }

        Fraction operator-(Fraction f) {
        int newnum = this->num*f.den - this->den*f.num;
        int newden = this->den*f.den;
        Fraction ans(newnum ,newden);
        return ans;
    }
        Fraction operator*(Fraction f) {
        int newnum = this->num*f.num;
        int newden = this->den*f.den;
        Fraction ans(newnum ,newden);
        return ans;
    }
        Fraction operator/(Fraction f) {
        int newnum = this->num*f.den;
        int newden = this->den*f.num;
        Fraction ans(newnum ,newden);
        return ans;
    }
};


int main() {
    Fraction f1(1,2);
    Fraction f2(1,4);
    f1.display();
    f2.display();
    //Fraction f3 = f1.add(f2);
    Fraction f3 = f1 + f2;
    Fraction f4 = f1 - f2;
    Fraction f5 = f1 * f2;
    Fraction f6 = f1 / f2;
    f3.display();
    f4.display();
    f5.display();
    f6.display();

    
}