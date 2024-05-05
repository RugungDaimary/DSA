//****to print counting***//

//#include<iostream>
//using namespace std;
//int main(){
//    int n;
//    cout<<"Enter the value of n\n";
//    cin>>n;
////    int count=1;
//    for (int i=1; i<=n; i++) {
//        cout<<i;
////        cout<<count;
////        count++;
//        cout<<endl;
//    }
//
//    return 0;
//}
//


//#include<iostream>
//using namespace std; //multiple variable can be included inside loop//
//int main(){
////    int n;
////    cin>>n;
//    for (int a=0,b=1; a>=0&&b>=1; a--,b--) {
//        cout<<a<<" "<<b<<endl;
//    }
//
//    return 0;
//}

//***Sum of numbers till n ***//
//
//#include<iostream>
//using namespace std;
//int main(){
//    int n;
//    cin>>n;
//    int sum=0;
//    for (int i=1; i<=n; i++) {
//        sum+=i;
//    }
//    cout<<sum<<endl;
//    return 0;
//}


//**** Fibonacci Series = 0,1,1,2,3,5,8,13,21....
//sum=(n-1)+(n-2)
//#include<iostream>
//using namespace std;
//int main(){
//    int n;
//    cin>>n;
//    int a=0,b=1;
//    cout<<a<<" "<<b<<" ";
//    for (int i=1;i<=n; i++) {
//        int nextNumber=a+b;
//        cout<<nextNumber<<" ";
//        a=b;
//        b=nextNumber;
//
//    }
//    cout<<endl;
//    return 0;
//}

//****To check a no is prime or not
//#include<iostream>
//using namespace std;
//int main(){
//    int n;
//    cin>>n;
//    bool isPrime=1;
//    for (int i=2; i<n-1; i++) {
//        if (n%i==0) {
//            //cout<<"Not prime"<<endl;
//            isPrime=0;
//            break;
//
//        }
//
//    }
//    if (isPrime==0) {
//        cout<<" is not a prime no\n";
//    }else{
//        cout<<" is a prime no\n";
//    }
//
//
//    return 0;
//}
//
//
//
//**CONTINUE  KEYWORD*****

#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for (int i=1; i<=n; i++) {
        cout<<"Hey\n";
        cout<<"Hiii\n";
        cout<<"Reply to karde\n";
        continue;
        cout<<"Okay bro\n"; //Unreacheable

    }

    return 0;
}


// ****SUM OF FEBONICII SERIES****//
//#include <iostream>
//using namespace std;
//
//int main() {
//    int n;
//    cin>>n;
//    int a=0;
//    int b=1;
//    int sum=0;
//
//    for(int i=1;i<=n-2;i++){
//
//        int c=a+b;
//           sum+=c;              //Sum of fibonicii series
//        a=b;
//        b=c;
//
//
//
//
//    }
//    sum=sum+1;
//    cout<<sum<<endl;
//    return 0;
//}

//#include <iostream>
//using namespace std;
//int main() {
//    int n;
//    cin>>n;
//    int a=0;
//    int b=1;
//
//    cout<<a<<" "<<b<<" ";
//    for(int i=1;i<=n-2;i++){
//        int c=a+b;
//        cout<<c<<" ";
//
//
//        a=b;
//        b=c;
//
//
//    }
//
//    return 0;
//}
//

//#include<iostream>
//using namespace std;
//int main(){
//    int n;
//    cin>>n;
//    switch (n) {
//        case 1:
//            cout<<"Rugung loves Sonika\n";
//            break;
////        case 2:
////            cout<<"Ragu\n";//continue is not a part of loop,it stops the execution of loop
////            continue;
//        case 3:
//            cout<<"Sonika loves Rugung\n";
//            break;;
//            
//        default:
//            cout<<"Invalid statement";
//            break;
//    }
//    
//    return 0;
//}
//
