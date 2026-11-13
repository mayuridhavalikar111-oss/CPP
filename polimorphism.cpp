//same operation can be performed on different types of objects(multiple forms)

/*
Types:
1. compilet time (static dynding, early binding)     
    No inheritance
    - function overloading
    - operator overloading
2. Run time  (late time binding)

*/


//Multilevel inheritance
//virtual function 
#include <iostream>
using namespace std;
class user
{      //base class
    public:
    virtual void display(){
        cout<<"User class"<<endl;
    }
};

class developer: virtual public user    //inheritance 
{      //child class of user
    public:
    void display()override
    {
        cout<<"Developer class"<<endl;
    }
};

class leaner: virtual public user    //inheritance 
{      //child class of user
    public:
    void display()override
    {
        cout<<"Learner class"<<endl;
    }
};

class trainee: public developer, public leaner    //inheritance 
{      //child class of user
    public:
    void display()override
    {
        cout<<"Trainee class"<<endl;
    }
};

int main()
{
    trainee t;

    //user pointer
    user *ptr;
    ptr=&t;
    ptr->display();       //(indecation symbol ->)
    return 0;

}