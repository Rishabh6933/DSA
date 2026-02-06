#include<iostream>
using namespace std;

class Student {
public:
    string name;
    int rno;

    Student(string name, int rno, float marks) {
        this->name = name; 
        this->rno = rno;
        this->marks = marks;
    }

    float getmarks() {
        return marks;
    }
    void setmarks(float m) {
        marks = m;
    }
     
    void display() {
        cout<<name<<" "<<rno<<" "<<marks<<endl;
    }

private:
    float marks;
};

int main() {
    Student s1("Rishabh Sharma", 127, 77.5);
    s1.display();
    s1.setmarks(85.2);
    cout<<s1.getmarks()<<endl;
    s1.display();
    //s1.name = "Rishabh Sharma";
    //s1.rno = 127;
    //s1.marks = 88; error because it is private    


}