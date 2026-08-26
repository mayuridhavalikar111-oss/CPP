#include<iostream>
using namespace std;
class student
{
    public:
    string name="XYZ";
    int rollno=1;
    string div="SY-G";
    void display()
    {
        cout<<"Student information is: "<<endl<<name<<endl<<rollno<<endl<<div;
    }
};
    int main()
    {
        student s;
        s.display();

    }
