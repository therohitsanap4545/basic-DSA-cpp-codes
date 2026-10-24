#include<iostream>
using namespace std;
class Complex
{
  private:
  float real;
  float imag;
  public:
   Complex()
   {
    real=0;
    imag=0;
   }  
   Complex(float r,float i)
   {
       real=r;
       imag=i;
   }
   void display()
   {
         cout<<real<<"+"<<imag<<"i"<<endl;
   }   
};
int main()
{
    Complex c1(2.0,3.0);
    cout<<"Complex no is :";
    c1.display();
    Complex c2(5.0,7.0);
    cout<<"Complex no is :";
    c2.display();
    return 0;
}
/*PS C:\Users\ADMIN\OneDrive\Documents\cpp codes rohit> cd "c:\Users\ADMIN\OneDrive\Documents\cpp codes rohit\" ; if ($?) { g++ complex.cpp -o complex } ; if ($?) { .\complex }
Complex no is :2+3i
Complex no is :5+7i
PS C:\Users\ADMIN\OneDrive\Documents\cpp codes rohit> PS*/