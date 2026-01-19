#include<iostream>
using namespace std;

class Cricketer {
    public:
    string name;
    int runs;

    Cricketer() {

    }

    Cricketer(string name, int runs) {
        this->name = name;
        this->runs = runs;
    }

    // n,r can not be equal to name, runs
    // to make the variable same i mean name=name
    // or runs=runs we have to use this keyword
    // this->name = name
    // this->runs = runs

    //functions inside class

    void print() {
        cout<<name<<"   "<<runs<<endl;
    }
};

int main() {
    Cricketer c1;
    c1.name = "Virat Kohli";
    c1.runs = 25000;

    Cricketer c2("Rohit Sharma", 18000);

    c1.print();
    c2.print();

}