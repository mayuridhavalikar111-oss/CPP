//Using class and void:
#include<iostream>
using namespace std;

class fruit
{
public:
    string name="apple";
    string colour="red";
    void display()
    {
        cout<<"Fruit information:"<<endl<<name<<endl<<colour;
    }
};
int main()
{
    fruit f;
    f.display();
}




//Using class:
class Fruit
{
    public:
    string name="Banana";
    string colour="Yellow";
};
int main()
{
    Fruit f;
    cout<<"Fruit is:"<<f.name<<endl<<"Colour is:"<<f.colour;
}
