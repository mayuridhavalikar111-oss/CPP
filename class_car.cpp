#include<iostream>
using namespace std;

class car
{
    private:
    string brand;
    string model;
    float price;

    public:
    void input()
    {
        cout<<"Enter brand name: ";
        cin>>brand;
        cout<<"Enter model name: ";
        cin>>model;
        cout<<"Enter price: ";
        cin>>price;
    }
    void display()
    {
        cout<<"Brand name is :"<<brand;
        cout<<"Model name is: "<<model;
        cout<<"Price is: "<<price;
    }
};
int main()
{
    car c;
    c.input();
    c.display();
    
}