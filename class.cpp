#include<iostream>
using namespace std;
class emp
{
    private:
    string name;
    int salary;

    public:
    void setname(string n)
    {
        name=n;
    }
    void setsalary(int s)
    {
        if(salary>0)
        {
            salary=s;
        }
        else
        {
            salary=0;
        }
    }
    string getname()
    {
        return name;
    }
    int getsalary()
    {
        return salary;
    }
};
int main()
{
    emp e;
    e.setname("XYZ");
    e.setsalary(100);
    cout<<"Name is:"<<e.getname()<<endl;
    cout<<"Salary is:"<<e.getsalary()<<endl;
    return 0;
}