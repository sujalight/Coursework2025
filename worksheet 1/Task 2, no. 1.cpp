#include<iostream>
using namespace std;
class bouncynumber
{
public:
    void getdata (int &num)
    {
        cout <<"Enter the number you want to know if it is a bouncy or not:";
        cin>>num;
    }

    void calculate(int num)
    {
        bool increasing=false;
        bool decreasing=false;

    int a,b;

       a=num%10;
       num/=10;

       while (num>0)
    {
       b=num%10;
       num/=10;

       if (b<a)
       {
           decreasing=true;
       }
       else if (b>a)
       {
           increasing=true;
       }
       a=b;
    }

    if (increasing  && decreasing)
    {
        cout <<"This is  a bouncy number"<<endl;
    }
    else
    {
        cout <<"The number is not bouncy number"<<endl;
    }

    }

};
int main ()
{
    int num;
bouncynumber b1;
b1. getdata (num);
b1. calculate(num);

return 0;

}
