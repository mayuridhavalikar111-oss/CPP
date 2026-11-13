/*Multiple Inheritance: Create two base classes, Academic and Sports. The Academic class should store academic marks, while the Sports class should store sports scores. Derive a class Result from both classes and calculate the student's final result.*/
#include<iostream>
using namespace std;

class academic{
protected:
    int marks;

public:
    academic(int m)
    {
        marks=m;

    }
};

class sports{
protected:
    int score;

public:
    sports(int s)
    {
        score=s;
    }
};

class result : public academic, public sports{
protected:
    int finalResult;

public:
    result(int m, int s): academic(m), sports(s)
    {
        finalResult=m+s;
    }

    void displayResult()
    {
        cout << "Academic Marks: " << marks << endl;
        cout << "Sports Score: " << score << endl;
        cout << "Final Result: " << finalResult << endl;
    }
};

int main()
{
    result r(80, 20);
    r.displayResult();
    return 0;
}