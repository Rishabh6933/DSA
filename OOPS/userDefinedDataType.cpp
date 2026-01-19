#include<iostream>
using namespace std;




class Student { 
public:
    string name;
    int rno;
    float gpa;
    int age;
};

class Car {
    public:
    string name;
    int price;
    int seat;
    string type;


    //default constructor
    Car() {

    }    
    
    //parameterized constructor
    Car(string n, int p, int s, string t) {
        name = n;
        price = p;
        seat = s;
        type = t;
    }
     // n,p,s,t can not be equal to name,price,seat,type
};

void print(Car c) {
    cout<<c.name<<" "<<c.price<<"   "<<c.seat<<"    "<<c.type<<endl;
}

int main() {


    //for both type of initialisation you must have to give a parameterized as well as default constructor


    Car c1("Fortuner", 5000000, 7, "SUV");
    // c1.name = "Fortuner";
    // c1.price = 5000000;
    // c1.seat = 7;
    // c1.type = "SUV";

    Car c2;
    c2.name = "BMW 5 series";
    c2.price = 10000000;
    c2.seat = 5;
    c2.type = "SEDAN";


    Car c3("DEFENDER", 15000000, 5, "SUV");
    // c3.name = "DEFENDER";
    // c3.price = 15000000;
    // c3.seat = 7;
    // c3.type = "SUV";

    
    print(c1);
    print(c2);
    print(c3);
}