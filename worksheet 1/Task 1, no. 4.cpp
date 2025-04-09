#include <iostream>
#include <string>
using namespace std;

class Week {
    string dayname;
    int x;

public:

    void Day(int x) {
        dayname = x;
    }

    void display ()
    {
    cout<<"!";
    }
};

int main() {
    Week w1;
    int ch, x;

    cout << "Enter a number (1-7) to find the corresponding day of the week: ";
    cin >> ch;

    if (ch == 1)
    {
        cout<<"The day is Sunday";
        w1.Day(x);
    }

    else if (ch == 2)
    {
        cout<<"The day is Monday";
        w1.Day(x);
    }

    else if (ch == 3)
    {
        cout<<"The day is Tuesday";
        w1.Day(x);
    }

    else if (ch == 4)
    {
        cout<<"The day is Wednesday";
        w1.Day(x);
    }

    else if (ch == 5)
    {
        cout<<"The day is Thursday";
        w1.Day(x);
    }

    else if (ch == 6)
    {
        cout<<"The day is Friday";
        w1.Day(x);
    }

    else if (ch == 7)
    {
        cout<<"The day is Saturday";
        w1.Day(x);
    }

    else
    {
        cout <<"Invalid input! Please enter between 1-7";
        w1.Day(x);
    }

    w1.display();

    return 0;
}
