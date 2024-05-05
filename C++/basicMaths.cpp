// PRIME NUMBER CHECK
 #include<iostream>
 using namespace std;
 bool isPrime(int n){
     if (n<=1)
     {
         return false;
     }

    for (int i = 2; i < n; i++ )
    {
        if (n % i == 0 )
        {

            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cout<<"Enter the number\n";
    cin>>n;
    isPrime(n);
    if (isPrime(n))
    {
        cout<<"Prime\n";
    }else{
        cout<<"Not a Prime\n";
    }
    

    
    return 0;
}

// #include<iostream>
// using namespace std;
// class Solution{
//     private:
//          bool isPrime(int n){
//              if (n<=1)
//              {
//                  return false;
//              }

//             for (int i = 2; i < n; i++ )
//             {
//                 if (n % i == 0 )
//                 {

//                     return false;
//                 }
//             }
//             return true;
//         }
//     public:
//     int countPrimes(int k){
//         int count=0;
//         for (int i = 2; i < n; i++)
//         {
//             if (isPrime(i)){
//                 count++;

            
//             }
            
            
            
//         }
//         return count;

//     }


// }
// int main(){
    
//     return 0;
// }