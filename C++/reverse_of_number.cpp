//****DECIMAL TO BINARY conversion
// #include<iostream>
// #include<math.h>
// using namespace std;
// int main(){
//    int n;
//    cin>>n;
//    int rem;
//    int i=0;
//    int ans=0;
//    while (n!=0) {
//        rem=n%2;
//        ans=(rem*pow(10,i))+ans;
//        n=n/2;
//        i++;
//    }
//    cout<<ans<<endl;

//    return 0;
// }

//**Another Method***//
// #include<iostream>
// #include<math.h>
// using namespace std;
// int main(){
//    int n;
//    cin>>n;
//    int ans=0;
//    int i=0;
//    while (n!=0) {
//        int bit=n&1;
//        ans=(bit*pow(10,i))+ans;
//        n=n>>1;
//        i++;
//    }
//    cout<<"Answer is : "<<ans<<endl;


//    return 0;

// }



//DECIMAL TO BINARY & BINARY TO DECIMAL CONVERSION
#include<iostream>
#include <math.h>
using namespace std;
int main(){
   int n;
   cout<<"Enter the binary number\n";
   cin>>n;
   int r;
   int ans = 0;
   int i = 0;
   while (n!=0) {
       r=n%10;//r-->remainder
       n=n/10;
       ans=ans+(r*pow(2,i));
       i++;
   }
   cout<<ans<<endl;
   return 0;
}

// IN C code

//  #include <stdio.h>
//  #include <math.h>
//  int main(){
//     int n, d, b = 0, t = 1, m, bn, f, sum = 0, i = 0, k;
//     printf("Enter a decimal number\n");
//     scanf("%d", &n);
//     m = n;
//     while (n != 0)
//     {
//         d = n % 2;
//         b = b + d * t;
//         n = n / 2;
//         t = t * 10;

//    }
//    printf("The binary equivalent of %d = %d\n", m, b);
//    printf("Enter a binary number\n");
//    scanf("%d", &bn);
//    k = bn;
//    while (bn != 0)
//    {
//        f = bn % 10;
//        sum = sum + f * pow(2, i);
//        bn = bn / 10;
//        i++;

//    }
//    printf("The decimal equivalent of %d = %d\n", k, sum);

//    return 0;
// }
