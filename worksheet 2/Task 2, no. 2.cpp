#include <iostream>
using namespace std;

class Maximum {
public:
   void findMax(int x, int y) {
    try {
        if (x == y) {
            throw "Both numbers are same";
        }
        cout << "The maximum number is: " << ((x > y) ? x : y)
             << "\n----------------------------------------" << endl;
    } catch (const char* msg) {
        cout << msg << endl;
    }
}

   void findMax(float a, float b) {
    try {
        if (a == b) {
            throw "Both numbers are same";
        }
        cout << "The maximum number is: " << ((a > b) ? a : b)
             << "\n----------------------------------------" << endl;
    } catch (const char* msg) {
        cout << msg << endl;
    }
}
void findMax(int x, int y, int z) {
    try {
        if (x == y && y == z) {
            throw "All three numbers are same";
        } else if (x == y && x > z) {
            throw "First and second numbers are the same and maximum";
        } else if (y == z && y > x) {
            throw "Second and third numbers are the same and maximum";
        } else if (x == z && x > y) {
            throw "First and third numbers are the same and maximum";
        }

        cout << "The maximum number is: " << ((x > y && x > z) ? x : ((y > z) ? y : z))
             << "\n----------------------------------------" << endl;

    } catch (const char* msg) {
        cout << msg << endl;
    }
}

   void findMax(int x, float y) {
    try {
        if (x == y) {
            throw "Both numbers are same";
        }
        cout << "The maximum number is: " << ((x > y) ? x : y)
             << "\n----------------------------------------" << endl;
    } catch (const char* msg) {
        cout << msg << endl;
    }
}
};

int main() {
    Maximum m1;
    float a, b;
    int x, y, z,ch;

    cout<<"Press 1 if you want maximum between two integers"<<endl;


    cout<<"Press 2 if you want maximum between two floating-point numbers"<<endl;


    cout<<"Press 3 if you want maximum between three integers"<<endl;

    cout<<"Press 4 if you want maximum between an integer and a float	"<<endl;
    cin>>ch;

if (ch==1){
    cout << "Enter the first integer: ";
    cin >> x;
    cout << "Enter the second integer: ";
    cin >> y;
    m1.findMax(x, y);

}
if (ch==2){
    cout << "\nEnter the first floating-point number: ";
    cin >> a;
    cout << "Enter the second floating-point number: ";
    cin >> b;
    m1.findMax(a, b);
}
if (ch==3){
    cout << "\nEnter the first integer: ";
    cin >> x;
    cout << "Enter the second integer: ";
    cin >> y;
    cout << "Enter the third integer: ";
    cin >> z;
    m1.findMax(x, y, z);
}
if (ch==4){
    cout << "\nEnter any integer: ";
    cin >> x;
    cout << "Enter any floating-point number: ";
    cin >> b;
    m1.findMax(x, b);
}
    cout << "\nEnd of the Program!" << endl;
    return 0;
}
