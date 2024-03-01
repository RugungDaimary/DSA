//#include<iostream>
//using namespace std;
//int main(){
//    int a,b;
//    cout<<"Enter the value of a\n";
//    cin>>a;
//    cout<<"Enter the value of b\n";
//    cin>>b;
//    char op;
//    cout<<"Enter th operation you want to perform\n";
//    cin>>op;
//    switch (op) {
//        case '+':
//        {cout<<"The addition of a & b is "<<a+b<<endl;}//block can be used
//            break;
//        case '-':
//            cout<<"The substraction of a & b is "<<a-b<<endl;
//            break;
//        case '*':
//            cout<<"The multiplication of a & b is "<<a*b<<endl;
//            break;
//        case '/':
//            cout<<"The devision of a & b is "<<a/b<<endl;
//            break;
//        case '%':
//            cout<<"The modulation of a & b is "<<a%b<<endl;
//            break;
//
//        default:
//            cout<<"Please enter a valid operator\n";
//            break;
//    }
//    return 0;
//}
//
//

//#include<iostream>
//using namespace std;
//int main(){
//    int n;
//    cin>>n;
//    switch (2*n)//Expression or character can be used
//    {
//        case 1:
//            cout<<"First\n";
//            break;
//        case 2:
//            cout<<"Second\n";
//            break;
//        case 4:
//            cout<<"Fourth\n";
//            break;
//
//        default:
//            cout<<"Invalid number entered\n";
//            break;
//    }
//    return 0;
//}
//
//Qn) You are given n rupees, write a code using switch case to find how many 100 nootes,50 notes,20 notes,10 notes and 1 notes.

//#include<iostream>
//using namespace std;
//int main(){
//    int n;
//    cin>>n;
//    int a=n/100;
//    int b=(n-100*a)/50;
//    int c=(n-100*a-50*b)/20;
//    int d=(n-100*a-50*b-20*c)/10;
//    int e=n-100*a-50*b-20*c-10*d;
//    cout<<a+b+c+d+e;
//
//    return 0;
//}
//#include<iostream>
//using namespace std;
//int main(){
//    int n,a,b,c,d,e;
//    cin>>n;
//    switch (1) {//1-->True always
//        case 1:
//            a=n/100;
//        case 2:
//            b=(n-100*a)/50;
//        case 3:
//            c=(n-100*a-50*b)/20;
//        case 4:
//            d=(n-100*a-50*b-20*c)/10;
//        case 5:
//            e=(n-100*a-50*b-20*c-10*d)/1;
//
//    }
//    cout<<"The number of 100 notes are "<<a<<endl;
//    cout<<"The number of 50 notes are "<<b<<endl;
//    cout<<"The number of 20 notes are "<<c<<endl;
//    cout<<"The number of 10 notes are "<<d<<endl;
//    cout<<"The number of 1 notes are "<<e<<endl;
//    cout<<"Total notes : "<< a+b+c+d+e<<endl;
//
//    return 0;
//}

//#include<iostream>
//using namespace std;
//int main(){
//    int n,a,b,c;
//    cout<<"Enter the number of days\n";
//    cin>>n;
//    a=n/365;
//    b=(n-365*a)/30;
//    c=(n-365*a-30*b);
//    cout<<"Years : "<<a<<endl;
//    cout<<"Months : "<<b<<endl;
//    cout<<"days : "<<c<<endl;
//
//
//    return 0;
//}








