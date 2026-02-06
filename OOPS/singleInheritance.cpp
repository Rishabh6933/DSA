#include<iostream>
using namespace std;

class Scooty {  // parent class
public:
    int topSpeed;
    float mileage;
private:
    int bootSpace;

};

class Bike: public Scooty{     //child class or derived class
public:
    int gears;
};

int main() {
    Bike b1;
    b1.topSpeed = 210;
    b1.mileage =48.2;
    b1.gears = 6;
    // b1.bootSpace = 600 
    //cannot be accessed as it is contained in private section of scooty
}