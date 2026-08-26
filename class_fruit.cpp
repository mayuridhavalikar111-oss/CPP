#include<iostream>
using namespace std;

class fruit 
{
    public:
    string name="Apple";
    string colour="Red";
};
int main()
{
    fruit f;
    cout<<"Fruit is: "<<f.name<<endl<<"Colour is: "<<f.colour;

}

//Pringing information using void:
/*class Fruit
{
    public:
    string name="Apple";
    string colour="Red";

    void display()
    {
        cout<<"Fruit details are: "<<name<<endl<<colour;

    }
};
int main()
{
    Fruit f1;
    f1.display();
}
    */
