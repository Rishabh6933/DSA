#include<iostream>
using namespace std;


class Cricketer {
    public:
    string name;
    int runs;
    float avg;

    Cricketer(string name, int runs, float avg) {
        this->name = name;
        this->runs = runs;
        this->avg = avg;
    }

    void change(Cricketer* c) {
        //this is same to this
        c->avg = 68.9; // (*c).avg = 68.9
    }
};

int main() {
    Cricketer c1("Virat Kohli", 25000, 55.2);
    //Cricketer c2("Rohit Sharma", 18000, 47.8);

    Cricketer* p1 = &c1;

    //both are same
    cout<<c1.runs<<endl;
    cout<<(*p1).runs<<endl;
    //this can also be written as
    cout<<p1->runs<<endl;

    cout<<c1.avg<<endl;
    p1->avg = 77.8;
    //(*p1).avg = 77.8;
    cout<<c1.avg<<endl;



    // in short a->b is equivalent to (*a).b

    // int x = 4;
    // cout<<x;
    // cout<<endl;
    // cout<<&x;
    // cout<<endl;
    // int* p = &x;
    // cout<<*p;
    // cout<<endl;
    // cout<<p;
}