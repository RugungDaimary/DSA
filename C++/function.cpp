
//#include<iostream>
//using namespace std;
//int main(){
//    int a,b;//finding a^b//pow(a,b)
//    cin>>a>>b;
//    int ans=1;
//    for (int i=1; i<=b; i++) {
//        ans=ans*a;
//    }
//    cout<<ans<<endl;
//
//    return 0;
//}


//#include<iostream>
//using namespace std;
//int power(int a,int b){
//    int ans=1;
//    for (int i=1; i<=b; i++) {
//        ans=ans*a;
//    }
//    return ans;
//}
//int main(){
//    int x,y;
//    cin>>x>>y;
//
//    int answer=power(x,y);
//
//    cout<<answer<<endl;
//
//
//    return 0;
//}
//#include<iostream>
//using namespace std;
//int power(){
//    int a,b;
//    cin>>a>>b;
//    int ans=1;
//    for (int i=1; i<=b; i++) {
//        ans=ans*a;
//    }
//    return ans;
//}
//int main(){
//    int answer=power();
//    cout<<answer<<endl;
//    int x=power();
//    cout<<x<<endl;
//    int y=power();
//    cout<<y<<endl;
//
//    return 0;
//}

//#include<iostream>
//using namespace std;
//int power(int x,int y){
//    int ans=1;
//    for (int i=1; i<=y; i++) {
//        ans=ans*x;
//    }
//    return ans;
//}
//int main(){
//    int a,b;
//    cin>>a>>b;
//    int answer=power(a, b);
//    cout<<answer<<endl;
//
//    return 0;
//}

//****EVEN_ODD PROGRAM ***//
//#include<iostream>
//using namespace std;
//int OddEven(){
//    int a;
//    cin>>a;
//    if (a&1) {
//        return 1; // 1--> Odd
//    }
//    return 0; //0-->Even
//}
//int main(){
//    int ans=OddEven();
//    if (ans==0) {
//        cout<<"Even\n";
//    }else{
//        cout<<"Odd\n";
//    }
//
//    return 0;
//}

//*****ANOTHER METHOD****//
//#include<iostream>
//using namespace std;
//bool OddEven(){
//    int a;
//    cin>>a;
//    if (a%2==0) {
//        return 0;
//    }
//    else{
//        return 1;
//    }
//}
//
//int main(){
//    bool ans=OddEven();
//    if (ans==0) {
//        cout<<"Even\n";
//
//    }else{
//        cout<<"Odd\n";
//    }
//
//    return 0;
//}
//****Bhaiya's appraoch***//

//#include<iostream>
//using namespace std;
////1-->Even
////0-->Odd
//bool isEven(int a){
//    //odd
//    if (a&1) {
//        return 0;
//    }
////    else{//Even
////        return 1;
////    }
//    return 1;
//}
//
//int main(){
//    int num;
//    cin>>num;
//    if(isEven(num)) {
//            cout <<"Number is Even" <<endl;
//        }
//        else {
//            cout<< "Number is Odd" <<endl;
//        }
//
//    return 0;
//}

//***FINDING nCr VALUE ****//
//#include<iostream>
//using namespace std;
//int factorial(int n){
//    int fact=1;
//    for (int i=1; i<=n; i++) {
//        fact=fact*i;
//    }
//    return fact;
//}
//int nCr(int n,int r){
//    int numer=factorial(n);
//    int denom=factorial(r)*factorial(n-r);
//    //int ans=numer/denom;
//    //return ans;
//    return numer/denom;
//
//}
//int main(){
//    int n,r;
//    cin>>n>>r;
////    int answer=nCr(n,r);
////    cout<<answer<<endl;
//    cout<<"Answer is "<<nCr(n, r)<<endl;
//
//    return 0;
//}
//

//****PRINT COUNTING****//
//#include<iostream>
//using namespace std;
////Function signature
//void PrintCounting(int n){
//    //function body
//    for (int i=1; i<=n; i++) {
//        cout<<i<<" ";
//
//    }
//    //cout<<endl;
//    //return ;
//}
//int main(){
//    int n;
//    cin>>n;
//    PrintCounting(n);//function call//no need to print here ,since it's printed in above.
//    return 0;
//}

//***CHECKING PRIME OR NOT ****// Applicable except number < 1
//#include<iostream>
//using namespace std;
//// 1-->Prime
////0-->Not a prime
//bool isPrime(int n){
//    for (int i=2; i<=n-1; i++) {
//        //divide ho gya,not a prime
//        if (n%i==0) {
//            return 0;
//        }
//    }
//    return 1;
//
//}
//int main(){
//    int n;
//    cin>>n;
//    if (isPrime(n)==0) {
//        cout<<"Not a Prime\n";
//    }
//    else{
//        cout<<"Prime \n";
//    }
//
//
//    return 0;
//}
//
//
//
//

//#include<iostream>
//using namespace std;
//void dummy(int n){
//    n++; //parameter/formal parameter
//    cout<<"n is "<<n<<endl;
//}
//int main(){
//    int n;    //argument/actual parameter
//    cin>>n;
//    dummy(n);
//    cout<<"number n is  "<<n<<endl;
//
//    return 0;
//}

#include<iostream>
using namespace std;
int power(int a,int b){
    int ans=1;
    for (int i=1; i<=b; i++) {
        ans=ans*a;
    }
    return ans;

}
int main(){
    int a,b;
    cin>>a>>b;
    int P=power(a,b);
    cout<<P<<endl;


    return 0;
}


