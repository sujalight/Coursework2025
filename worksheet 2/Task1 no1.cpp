#include <iostream>
using namespace std;
class temperature
{
    float t;
public:
    void f2c (float x)
    {
        t=(x - 32) * 5/9;
    }
    void c2f (float x)
    {
        t=(x * 9/5) + 32;
    }
    void displayf2c()
    {
     cout<<"The required temperature is :"<<t<<" C"<<endl;
    }
    void displayc2f ()
    {

        cout <<"The required temperature is:"<<t<<" F"<<endl;
    }
};
int main ()
{
    temperature t1;
    float x;
    int ch;
    cout <<"Press 1 if you want to convert Fahrenheit into Celsius"<<endl
    <<"Press 2 if you wan to convert Celsius into Fahrenheit"<<endl;
    cin >> ch;

    if (ch==1)
    {
        cout <<"Enter the temperature in Fahrenheit:";
        cin>>x;
        t1. f2c (x);
        t1. displayf2c();
    }
    if (ch==2)
    {
        cout <<"Enter the temperature in Celsius:";
        cin>>x;
        t1. c2f (x);
        t1. displayc2f ();
    }
    else
        {
        cout <<"Invalid input!!! Please enter 1 to convert to Celsius or enter 2 to convert to Fahrenheit";
        }
    return 0;
}

