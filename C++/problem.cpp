
//Given an integer n, return the difference b/w the product of digits and the sum of its digits

//#include <iostream>
//using namespace std;
//int main() {
//  int n;
//  cin>>n;
//  int product=1;
//  int sum=0;
//  while(n!=0){
//      int digit=n%10;
//      product=product*digit;
//      sum=sum+digit;
//      n=n/10;
//
//
//  }
//  int ans;
//  ans=(product-sum);
//  cout<<ans<<endl;
//
//
//  return 0;
//}


//Checking how many 1's are there in binary nos of an integer
//#include<iostream>
//using namespace std;
//int main(){
////    int n;
////    cin>>n;
//    int count=0;
//    while (n!=0) {
//        //checking last bit
//        if (n&1) {
//            count++;
//        }
//        n=n>>1;
//    }
//
//    return 0;
//}

//#include<iostream>
//using namespace std;
//int main(){
//    for (int i=0; i<=5; i++) {
//        for (int j=1; j<=5; j++) {
//            if (i+j==6) {
//              break;
//           }
//            cout<<i<<" "<<j<<endl;
//
//        }
//    }
//
//    return 0;
//}

//#include<iostream>
//using namespace std;
//int main(){
//    for (int i=0; i<=5; i++) {
//        cout<<i<<" ";
//        i++;
//    }
//    
//    return 0;
//}
//

//#include<iostream>
//using namespace std;
//int main(){
//    for (int i=0; i<=5; i--) {        //Infinite Loop
//        cout<<i<<" ";
//        i++;
//    }
//
//    return 0;
//}

//#include<iostream>
//using namespace std;
//int main(){
//    for (int i=0; i<=15; i+=2) {
//        cout<<i<<" ";
//        if (i&1) {        //i&1 -->true if 'i' is an odd no else-->false
//            continue; //if this statement comes true-->i++ won't execute-->
//        }                 //directs to updation;
//        i++;
//    }
//    return 0;
//}

#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter number\n";
    cin>>n;
    cout<<n<<endl;
    for (int i = 0; i < 5; i++)
    {
        cout<<"Rugung\n";
    }
    
    
    
    
    
    return 0;
}

