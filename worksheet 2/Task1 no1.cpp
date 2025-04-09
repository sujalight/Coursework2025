#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int marks[3];
    int totalMarks;
    float average;
    char grade;

public:

    void getdata() {
        cout << "Enter student's name: ";
        cin>>name;


        for (int i = 0; i < 3; ++i) {
            cout << "Enter mark for subject " << i + 1 << ": ";
            cin >> marks[i];


            if (marks[i] < 0 || marks[i] > 100) {
                cout << "Error: Marks must be between 0 and 100!" << endl;
                exit(1);
            }
        }
    }

    void calculateGrade() {

        totalMarks = marks[0] + marks[1] + marks[2];
        average = totalMarks / 3.0;


        if (average >= 90) {
            grade = 'A';
        } else if (average >= 80) {
            grade = 'B';
        } else if (average >= 70) {
            grade = 'C';
        } else if (average >= 60) {
            grade = 'D';
        } else {
            grade = 'F';
        }
    }


    void displayDetails() {
        cout << "\nStudent's Name: " << name << endl;
        cout << "Your Total Marks is: " << totalMarks <<" / 300"<< endl;
        cout << "Your Average Marks is: " << average << " / 100"<<endl;
        cout << "Your Grade is: " << grade << endl;
    }
};

int main() {
    Student student;

    student.getdata();
    student.calculateGrade();
    student.displayDetails();

    return 0;
}

