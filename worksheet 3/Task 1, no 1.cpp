#include <iostream>
using namespace std;

class Time {
private:
    int hour;
    int minute;

public:

    Time() {
        hour = 0;
        minute = 0;
    }

    Time(int a, int b)
    {
        if (a>24 || b>59)
        {
            throw invalid_argument("Exception!!! Hour can not be more than 24 and minutes can not be 60 or more!");
        }

        hour = a;

        minute = b;
    }
    Time operator+(Time T) {
        Time temp;
        temp.minute = minute + T.minute;
        int ff= temp.minute/60;
        temp.minute %= 60;
        temp.hour = ff+hour + T.hour;
        return temp;
    }

    void display() {
        cout << hour << " hours " << minute << " minutes" << endl;
    }
};

int main()
{
    int x, y;
try
   {
    cout << "Enter the hour of the first time: ";
    cin >> x;
    cout << "Enter the minutes of the first time: ";
    cin >> y;
    Time t1(x, y);
    cout<<endl;

    cout << "Enter the hour of the second time: ";
    cin >> x;
    cout << "Enter the minutes of the second time: ";
    cin >> y;
    Time t2(x, y);
    cout<<endl;

    Time t3 = t1 + t2;


    cout << "First time: ";
    t1.display();
    cout << "Second time: ";
    t2.display();
    cout << "Sum of first time and second time: ";
    t3.display();
   }
catch (const invalid_argument &e)
    {
        cerr << e.what() << endl;
    }


    return 0;
}
