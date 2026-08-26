#include<iostream>
using namespace std;

class student
{
    private:
    int rollno;
    string name;

    public:
    static int count;

    //Constructor
    student()
    {
        count++;
        cout<<"Constructor called, object created"<<endl<<count<<endl;
    }

    //Destructor
    ~student()
    {
        cout<<"Destructor called, object created"<<endl<<count<<endl;
        count--;
    }
    inline void setData(int r,string n)
    {
        rollno=r;
        name=n;
    }

    inline void displayData()
    {
        cout<<"Roll no is:"<<rollno<<endl;
        cout<<"Name is:"<<name<<endl;
    }
}