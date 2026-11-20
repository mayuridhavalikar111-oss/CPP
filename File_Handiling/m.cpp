#include <iostream>
#include <string>

using namespace std;

class PercentageException {
    string message;
public:
    void checkPercentage(float percentage) {
        if (percentage > 100 || percentage < 0) {
            throw "Invalid Percentage! Percentage must be between 0 and 100.";
        }
    }
};

class PhoneNumberException {
    string message;
public:
    void checkPhoneNumber(string phone_number) {
        int count = 0;

        for (int i = 0; i < phone_number.length(); i++) {
            if (phone_number[i] >= '0' && phone_number[i] <= '9') {
                count++;
            }
        }

        if (count > 10 || count < 10) {
            throw "Invalid Phone Number! Phone number must contain exactly 10 digits.";
        }
    }
};


class Student {
private:
    string name;
    float percentage;
    string phone_number;

public:
    void acceptDetails() {
        cout << "Enter Student Name: ";
        getline(cin, name);

        cout << "Enter Percentage: ";
        cin >> this->percentage;

        cout << "Enter Phone Number: ";
        cin >> this->phone_number;
    }

    void displayDetails() {
        cout << "\nStudent Details" << endl;
        cout << "Name       : " << name << endl;
        cout << "Percentage : " << percentage << "%" << endl;
        cout << "Phone No.  : " << phone_number << endl;
    }

    void validateDetails() {
        PercentageException p;
        PhoneNumberException ph;

        p.checkPercentage(this->percentage);
        ph.checkPhoneNumber(this->phone_number);
    }
};

int main() {
    Student s;

    try {
        s.acceptDetails();
        s.validateDetails();
        s.displayDetails();
    }
    catch (const char* msg) {
        cout << "\nException Caught: " << msg << endl;
    }

    return 0;
}




