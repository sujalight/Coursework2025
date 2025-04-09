#include<iostream>
using namespace std;

class CinemaBookingSystem {
private:
    char seats[5][5];

public:

    CinemaBookingSystem()
    {
        for(int i = 0; i < 5; ++i)
        {
            for(int j = 0; j < 5; ++j)
            {
                seats[i][j] = 'O';
            }
        }
    }


    void display() {

        cout << "Current Seating Arrangement:" << endl;
        for(int i = 0; i < 5; ++i) {
            for(int j = 0; j < 5; ++j) {
                cout << seats[i][j] << " ";
            }
            cout << endl;
        }
    }

    void bookSeat() {
        int row, col;


        cout << "Enter row number (1-5): ";
        cin >> row;
        cout << "Enter column number (1-5): ";
        cin >> col;


        if(row < 1 || row > 5 || col < 1 || col > 5) {
            cout << "Invalid row/column number. Please try again." << endl;
            return;
        }

        row -= 1;
        col -= 1;


        if(seats[row][col] == 'X') {
            cout << "\nError: This seat is already booked.\n" << endl;
             cout <<"------------------------------------------\n";
        } else {
            // Mark the seat as booked
            seats[row][col] = 'X';
            cout << "\nSeat booked successfully!\n" << endl;
             cout <<"------------------------------------------\n";
        }
    }
};

int main() {
    CinemaBookingSystem system;
    int ch;

    do {

        system.display();


        cout << "\n--------Menu--------" << endl;
        cout << "Press 1 to book a seat" << endl;
        cout << "Press 2 to exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch(ch) {
            case 1:
                system.bookSeat();
                break;
            case 2:
                cout <<"------------------------------------------\n";
                cout << "Exiting the system. Goodbye!" << endl;
                break;
            default:
                cout <<"------------------------------------------\n";
                cout << "Invalid choice! Please try again." << endl;
        }

    } while(ch != 2);

    return 0;
}
