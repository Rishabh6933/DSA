#include<iostream>
using namespace std;

class Scooty {
    public:
    int topSpeed;
    float mileage;

    void sound() {
        cout<<"Vroom Vroom"<<endl;
    }
};

class Bike : public Scooty {
    public:
    int gears;
    void sound() {
        cout<<"Dhroom Dhroom"<<endl;
    }
};

int main() {
    Bike b1;
    b1.sound();
    Bike b2;
    b2.sound();
    Scooty s1;
    s1.sound();
}