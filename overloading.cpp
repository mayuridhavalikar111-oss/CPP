#include <iostream>
using namespace std;

class person{
    public:
    string name;
    int age;
    public:
    person(string name=n, int age=a){
        cout<<"Person constructor is called"<<endl;
    }
    void display person(){
        cout<<"Person class"<<endl;
    }
    ~person(){
        cout<<"Person destructor is called"<<endl;
    }
    class employee: public person{
        public:
        float salary;
        public:
        employee(string name=n, int age=a, float salary=s): person(name, age){
            cout<<"Employee constructor is called"<<endl;
        }
        void display employee(){
            cout<<"Employee class"<<endl;
            display person()
            cout<<"__Person__"<<endl;
        }
        ~employee(){
            cout<<"Employee destructor is called"<<endl;
        }
    }
    class manager: public employee{
        public:
        string department;
        public:
        manager(string name=n, int age=a, float salary=s, string department=d): employee(name, age, salary){
            cout<<"Manager constructor is called"<<endl;
        }
        void display manager(){
            cout<<"Manager class"<<endl;
            display employee()
            cout<<"__Employee__"<<endl;
        }
        ~manager(){
            cout<<"Manager destructor is called"<<endl;
        }
}