#include <iostream>
using namespace std;

class circle
{
private:
    float areafirst;
    float areasecond;
    float radius1;
    float radius2;

public:
    circle(float r1, float r2) {
        radius1 = r1;
        radius2 = r2;
        areafirst = 3.14 * radius1 * radius1;
        areasecond = 3.14 * radius2 * radius2;
    }

    void displayfirst() {

        cout <<"\nThe area of the first circle is  "<<  areafirst<<endl;
    }
    void displaysecond() {

        cout <<"The area of the second circle is  "<<  areasecond<<endl;
    }

    friend void compareTwoCircles(circle c1, circle c2);
};

void compareTwoCircles(circle c1, circle c2) {
    cout <<"------------------------------------------\n";
    cout << "\nBy Comparing the two circles, it was found that:" << endl;
    if (c1.areafirst > c2.areasecond) {

        cout << "First circle is larger !" << endl;
    }
    else if (c1.areafirst < c2.areasecond) {

        cout << "Second circle is larger !" << endl;
    }
    else {

        cout << "Both circles have equal area" << endl;
    }
}

int main()
{
    float radius1, radius2;

    cout <<"Enter the radius of the first circle:";
    cin >> radius1;

    cout << "Enter the radius of the second circle:";
    cin >> radius2;

    cout <<"------------------------------------------\n";

    circle c1(radius1, radius2);

    c1.displayfirst();
    c1.displaysecond();

    compareTwoCircles(c1, c1);

    return 0;
}
