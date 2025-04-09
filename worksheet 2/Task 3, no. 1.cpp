#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Library {
    char bookList[10][150];
    string filePath;

public:
    void inputBooks() {
        cout << "Enter 10 book titles:\n";
        cin.ignore();
        for (int i = 0; i < 10; ++i) {
            cout << "Title " << i + 1 << ": ";
            cin.getline(bookList[i], 150);
        }
    }

    void exportBooks() {
        cout << "Enter the filename to save books: ";
        cin >> filePath;
        ofstream outFile(filePath, ios::binary);
        if (!outFile) {
            cout << "Error creating file.\n";
            return;
        }
        outFile.write((char *)bookList, sizeof(bookList));
        outFile.close();
    }

    void findBook() {
        char query[150];
        cout << "Enter a book title to search: ";
        cin.ignore();
        cin.getline(query, 150);
        ifstream inFile(filePath, ios::binary);
        if (!inFile) {
            cout << "Book not found.\n";
            return;
        }
        inFile.read((char *)bookList, sizeof(bookList));
        inFile.close();

        for (int i = 0; i < 10; ++i) {
            if (strcmp(bookList[i], query) == 0) {
                cout << "Book is available in the library.\n";
                return;
            }
        }
        cout << "Book not found.\n";
    }
};

class StudentRecord {
    int rollNo;
    string fullName;
    int score;

public:
    void enterData() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, fullName);
        cout << "Enter Marks: ";
        cin >> score;

        if (score < 0 || score > 100) {
            throw out_of_range("Marks must be between 0 and 100.");
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
    Library lib;
    StudentRecord student;
    int option;
    string studentFileName = "student_data.txt";

    while (true) {
        cout << "\n=== MENU ===\n"
             << "1. Enter Book Titles\n"
             << "2. Save Books to File\n"
             << "3. Search for a Book\n"
             << "4. Add a Student Record\n"
             << "5. Exit\n"
             << "Choose an option: ";
        cin >> option;

        switch (option) {
            case 1:
                lib.inputBooks();
                break;
            case 2:
                lib.exportBooks();
                break;
            case 3:
                lib.findBook();
                break;
            case 4:
                try {
                    student.enterData();
                    student.saveRecord(studentFileName);
                } catch (exception &e) {
                    cout << "Error: " << e.what() << "\n";
                }
                break;
            case 5:
                cout << "Exiting the program. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid option. Try again.\n";
        }
    }
}
