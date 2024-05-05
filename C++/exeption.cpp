// #include<iostream>
// using namespace std;
// int main(){
//     int a,b;
//     cout<<"Enter 2 numbers\n";
//     cin>>a>>b;
//     int result=0;
//     try{
//         if (b==0)
//         {
//             throw b;//this will throw 0 to catch direct
//         }
//         result = a / b;//error may happen here
//     }
//     catch(int ex){
//         cout<<"Exception: Divide by Zero Not allowed "<<ex;
//     }
//     cout<<endl;
//     cout<<"Result is "<<result<<endl;
    
//     return 0;
// }

#include <iostream>
using namespace std;
class Complex
{
public:
    int a, b;
    void setNumber(int n1, int n2)
    {
        a = n1;
        b = n2;
    }
    void getNumber()
    {
        cout << "Number is : " << a << " + " << b << "i" << endl;
    }
    sumComplex(Complex o1, Complex o2);
};
Complex sumComplex(Complex o1, Complex o2)
{
    Complex o3;
    o3.setNumber((o1.a + o2.a), (o1.b + o2.b));
    o3.getNumber();
    return o3;
}
int main()
{
    Complex c1, c2;
    c1.setNumber(5, 14);
    c2.setNumber(56, 8);
    c1.getNumber();
    c2.getNumber();
    Complex sum = sumComplex(c1, c2);
    // cout<<sum;
    return 0;
}