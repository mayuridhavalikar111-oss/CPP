//For run time error we use exception handling in C++ using try, catch and throw keywords.
//Create a class MathOperation with a function to divide two numbers. Handle divide by zero using try , catch and throw. Use nested try catch block to handle the exception.
#include <iostream>
#include <stdexcept>
using namespace std;

class MathOperation{
    string message;
public:
    double divide(double a,double b)
        //Outer try block 
    {
        try{
            //Inner try block
            try{
                if(b==0)
                        {
                            throw invalid_argument("Division by zero is not allowed!");
                        }
                        return a/b;
            }
            catch(const invalid_argument& e)
            {
                cout<<"Inner catch block: "<<e.what()<<endl;
                throw; // rethrow the exception to be caught by the outer catch block
            }
        }
        //Outer catch block to handle the rethrown exception
        catch(const exception& e){
            cout<<"Outer catch block: "<<e.what()<<endl;
            throw runtime_error("Division failed");
        }
    }
};

int main(){
    MathOperation m;
    try{
        cout<<m.divide(10,0)<<endl;
    }
    catch(const exception& e)
    {
        cerr<<e.what()<<endl;
    }
return 0;
}