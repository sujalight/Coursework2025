#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <limits>
using namespace std;

class StudentRecord {
    int rollNo;
    string fullName;
    int score;

public:
    void enterData() {
        while (true) {
            cout << "Enter roll number of the student: ";
            cin >> rollNo;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter a valid roll number.\n";
            } else {
                break;
            }
        }

        cin.ignore();
        cout << "Enter name of the student: ";
        getline(cin, fullName);

        while (true) {
            cout << "Enter total marks of the student: ";
            cin >> score;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid! Enter marks.\n";
            } else if (score < 0 || score > 100) {
                cout << "Marks must be between 0 and 100.\n";
            } else {
                break;
            }
        }
    }

    void saveRecord(const string& fileName) {
        ofstream file(fileName, ios::app);
        if (file) {
            file << rollNo << "\n" << fullName << "\n" << score << "\n";
            file.close();
        } else {
            cout << "Unable to open student file.\n";
        }
    }
};

int main() {
    StudentRecord student;
    string studentFileName = "student_records.txt";

    try {
        student.enterData();
        student.saveRecord(studentFileName);
        cout << "Student's record saved successfully in the file named student_records.\n";
    } catch (exception& e) {
        cout << "Error: " << e.what() << "\n";
    }

    return 0;
}
