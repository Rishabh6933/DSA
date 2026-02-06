#include<iostream>
using namespace std;

class Vehicle {  // parent class
public:
    int topSpeed;
    float mileage;
    string fuel;

};

class Car : public Vehicle{
public:
};

class Bike : public Vehicle{
public:
};

class Truck : public Vehicle{
public:
};

int main() {
    Car c1;
    c1.topSpeed = 210;
    c1.mileage =48.2;
    c1.fuel = "DIESEL";
}