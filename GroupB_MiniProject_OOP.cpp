#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cstdlib>

#define SUBJECT_COUNT 4
#define MAX_SUB_MARKS 100
#define PASS_PERCENTAGE 30.00

const std::string subjects[] = {"EMMD", "DSA", "OOP", "COA"};

void clear_terminal()
{
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

void back_to_menu()
{
    std::cout << "\nPress Enter to go back to menu...";
    std::cin.ignore(10000, '\n');
    std::cin.get();
    clear_terminal();
}

class StudentRecord
{
    int roll_number;
    int year;
    int marks[SUBJECT_COUNT];
    std::string first_name;
    std::string last_name;
    float percentage;
    int total_marks;
    bool isPassed;

    void calculate_results()
    {
        if (SUBJECT_COUNT == 0 || MAX_SUB_MARKS == 0)
        {
            throw std::runtime_error("Division by zero error");
        }

        total_marks = 0;
        for (int i = 0; i < SUBJECT_COUNT; i++)
        {
            total_marks += marks[i];
        }

        percentage = ((float) total_marks / (SUBJECT_COUNT * MAX_SUB_MARKS)) * 100.0f;
        isPassed = (percentage >= PASS_PERCENTAGE);
    }

public:
    StudentRecord()
    {
        roll_number = 0;
        year = 0;
        first_name = "";
        last_name = "";
        percentage = 0.0f;
        total_marks = 0;
        isPassed = false;

        for (int i = 0; i < SUBJECT_COUNT; i++)
        {
            marks[i] = 0;
        }
    }

    int get_roll_number() const
    {
        return roll_number;
    }

    void input_data()
    {
        std::cout << "Roll Number: ";
        if (!(std::cin >> roll_number) || roll_number <= 0)
        {
            throw std::invalid_argument("Invalid Roll Number");
        }

        std::cout << "First Name: ";
        std::cin >> first_name;

        std::cout << "Last Name: ";
        std::cin >> last_name;

        std::cout << "Year (1-4): ";
        if (!(std::cin >> year) || year < 1 || year > 4)
        {
            throw std::invalid_argument("Invalid Year");
        }

        for (int i = 0; i < SUBJECT_COUNT; i++)
        {
            std::cout << subjects[i] << " Marks: ";
            if (!(std::cin >> marks[i]) || marks[i] < 0 || marks[i] > MAX_SUB_MARKS)
            {
                throw std::invalid_argument("Invalid Marks (must be 0 to 100)");
            }
        }

        calculate_results();
    }

    void display_report_card() const
    {
        std::cout << "\nRoll Number: " << roll_number << std::endl;
        std::cout << "Name: " << first_name << " " << last_name << std::endl;
        std::cout << "Year: " << year << std::endl;

        for (int i = 0; i < SUBJECT_COUNT; i++)
        {
            std::cout << subjects[i] << ": " << marks[i] << std::endl;
        }

        std::cout << "Total: " << total_marks << "/" << (SUBJECT_COUNT * MAX_SUB_MARKS) << std::endl;
        std::cout << "Percentage: " << percentage << "%" << std::endl;
        std::cout << "Status: " << (isPassed ? "PASS" : "FAIL") << std::endl;
    }

    friend void write_student(const StudentRecord& s, const std::string& filename, bool append);
    friend void read_all_students(const std::string& filename);
};

void write_student(const StudentRecord& s, const std::string& filename, bool append)
{
    std::ofstream file;
    if (append)
    {
        file.open(filename, std::ios::app);
    }
    else
    {
        file.open(filename);
    }

    if (!file.is_open())
    {
        throw std::runtime_error("Cannot open file: " + filename);
    }

    file << s.roll_number << " "
         << s.year << " "
         << s.first_name << " "
         << s.last_name;

    for (int i = 0; i < SUBJECT_COUNT; i++)
    {
        file << " " << s.marks[i];
    }
    file << "\n";

    file.close();
}

void read_all_students(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("File not found: " + filename);
    }

    StudentRecord s;
    bool has_records = false;

    while (true)
    {
        file >> s.roll_number;
        if (file.eof())
        {
            break;
        }

        file >> s.year >> s.first_name >> s.last_name;
        for (int i = 0; i < SUBJECT_COUNT; i++)
        {
            file >> s.marks[i];
        }

        s.calculate_results();
        s.display_report_card();
        has_records = true;
    }

    if (!has_records)
    {
        std::cout << "No records in file." << std::endl;
    }

    file.close();
}

int main()
{
    const std::string filename = "students.txt";
    int choice = 0;

    clear_terminal();

    while (true)
    {
        std::cout << "1. Write New File (Overwrite)\n";
        std::cout << "2. Append Student Record\n";
        std::cout << "3. Read All Report Cards\n";
        std::cout << "4. Test File Not Found Error\n";
        std::cout << "5. Exit\n";
        std::cout << "Choice: ";

        try
        {
            if (!(std::cin >> choice))
            {
                std::cin.clear();
                std::string bad_input;
                std::cin >> bad_input;
                throw std::invalid_argument("Choice must be a number");
            }

            clear_terminal();

            if (choice == 1)
            {
                StudentRecord s;
                s.input_data();
                write_student(s, filename, false);
                std::cout << "\nSaved to new file." << std::endl;
                back_to_menu();
            }
            else if (choice == 2)
            {
                StudentRecord s;
                s.input_data();
                write_student(s, filename, true);
                std::cout << "\nAppended to file." << std::endl;
                back_to_menu();
            }
            else if (choice == 3)
            {
                read_all_students(filename);
                back_to_menu();
            }
            else if (choice == 4)
            {
                read_all_students("does_not_exist.txt");
            }
            else if (choice == 5)
            {
                break;
            }
            else
            {
                throw std::invalid_argument("Invalid menu choice");
            }
        }
        catch (const std::exception& e)
        {
            std::cin.clear();
            std::cout << "\nError: " << e.what() << std::endl;
            back_to_menu();
        }
    }

    return 0;
}