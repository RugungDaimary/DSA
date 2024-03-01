//COUNT ZEROS
//this code won't work for test case 0
// #include <iostream>
// using namespace std;
// int countZeros(int n,int count)
// {
//     if(n==0){
//         return count;
//     }
//     int lastDigit=n%10;
//     if (lastDigit == 0)
//         {
//             count++;
//         }
//     int small = countZeros(n / 10, count);
//     return small;
// }
// int main()
// {
//     int n;
//     cout << "Enter the value of n\n";
//     cin >> n;
//     int count=0;
    
//     cout << countZeros(n,count) << endl;

//     return 0;
// }


//GEOMETRIC SUM
// #include<iostream>
// #include<cmath>
// using namespace std;
// double GS(int k){
//     if(k==0){
//         return 1;
//     }
//     double small=GS(k-1);
//     return small+1/(pow(2,k));

// }
// int main(){
//     int k;
//     cin>>k;
//     cout<<GS(k)<<endl;
//     return 0;
// }

//PALINDROME CHECK
// #include<iostream>
// #include<string>
// using namespace std;
// bool helper(string s,int start,int end){
//     if (start>=end)//base case
//     {
//         return true;
//     }
//     if (s[start] != s[end])
//     {
//         return false;
//     }
//     return helper(s,start+1,end-1);
// }

// bool isPalindrome(string s){
//     int start=0;
//     int end=s.length()-1;
//     return helper(s,start,end);
    
// }
// int main(){
//     string s;
//     cin>>s;
//     cout<<isPalindrome(s)<<endl;

//     return 0;
// }



//SUM OF DIGITS
// #include<iostream>
// using namespace std;
// int helper(int n,int sum){
//     if(n==0){
//         return sum;
//     }
//     int lastDigit=n%10;
//     sum=sum+lastDigit;
//     return helper(n/10,sum);

// }
// int SumDigits(int n){
//     int sum=0;
//     return helper(n,sum);

// }
// int main(){
//     int n,sum;
//     cin>>n;
   
//     cout<<SumDigits(n)<<endl;
//     return 0;
// }