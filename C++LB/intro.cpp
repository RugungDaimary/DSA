#include<iostream>
using namespace std;
int main(){
   cout<<"Welcome !!!"<<endl;

   return 0;
}
#include<iostream>
using namespace std;
int main(){
   int n;
   cin>>n;
   if (n>0) {
       cout<<n<<" is +ve\n";
   }else if (n==0){
       cout<<n<<" is neither +ve nor -ve\n ";
   }
   else{
       cout<<n<<" is not positive\n";
   }
   

   return 0;
}



//#include<iostream>
//using namespace std;
//int main(){
//    int a,b;
//    cin>>a>>b;
//    if (a>b) {
//        cout<<a;
//    }else{
//        cout<<b;
//    }
//
//    return 0;
//}

//#include<iostream>
//using namespace std;
//int main(){
//    char c;
//    int isLowercase,isUppercase;
//    cout<<"Enter a character\n";
//    cin>>c;
//    int n=0;
//    cout<<"Enter a number\n";
//    cin>>n;
//    isLowercase=(c=='a'||c=='b'||c=='c'||c=='d'||c=='d'||c=='e'||c=='f'||c=='g'||c=='h'||c=='i'||c=='j'||c=='k'||c=='l'||c=='m'||c=='n'||c=='o'||c=='p'||c=='q'||c=='r'||c=='s'||c=='t'||c=='u'||c=='v'||c=='w'||c=='x'||c=='y'||c=='z');
//    isUppercase=(c=='A'||c=='B'||c=='C'||c=='D'||c=='E'||c=='F'||c=='G'||c=='H'||c=='I'||c=='J'||c=='K'||c=='L'||c=='M'||c=='N'||c=='O'||c=='P'||c=='Q'||c=='R'||c=='S'||c=='T'||c=='U'||c=='V'||c=='W'||c=='X'||c=='Y'||c=='Z');
//    if (n<=9) {
//        cout<<n<<" Numeric\n";
//    }
//    if (isLowercase) {
//        cout<<c<<" is Lowercase \n";
//    }
//    if (isUppercase) {
//        cout<<c<<" is Uppercase\n";
//    }
//    return 0;
//}
//

//SUM OF NUMBERS TILL N
//#include<iostream>
//using namespace std;
//int main(){
//    int n;
//    cin>>n;
//    int i=1;
//    int sum=0;
//    while (i<=n) {
//        sum=sum+i;
//        i++;
//    }
//    cout<<"The value of sum is : "<<sum<<endl;
//
//    return 0;
//}


//SUM OF EVEN NUMBERS TILL N

//#include<iostream>
//using namespace std;
//int main(){
//    int n;
//    cout<<"Enter the value of n\n";
//    cin>>n;
//    int sum=0;
//    int i=1;
//    while (i<=n) {
//        if (i%2==0) {
//            sum=sum+i;
//            i=i+1;
//        }
//
//    }
//
//
//    return 0;
//}



//Degreee to Fahrenheit conversion
//#include<iostream>
//using namespace std;
//int main(){
//    int cel;
//    cout<<"Enter the degree in Celsius\n";
//    cin>>cel;
//    int Farh;
//    Farh=(9*cel)/5+32;
//    cout<<Farh<<endl;
//    return 0;
//}


//checking a number is prime or not
// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     int i=2;
//     while (i<n) {
//         if (n%i==0) {
//             cout<<"not prime for "<<i<<endl;
//         }else{
//             cout<<"Prime for "<<i<<endl;
//         }
//         i=i+1;
//     }
//
//     return 0;
// }
