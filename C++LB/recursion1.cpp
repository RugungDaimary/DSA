//FINDING FACTORIAL 
#include<bits/stdc++.h>
using namespace std;
// int factorial(int n){
//     //first write Base Case
//     if (n==0)           
//     {
//         return 1; // return likhna mandatory
//     }
//     int SmallerProblm=factorial(n-1);
//     int BigProblem=n*SmallerProblm;
//     return BigProblem;
    

// }
//OR in short 
int factorial(int n){
    if (n==0)
    {
        return 1;
    }
    return n*factorial(n-1);
}

//POWER FUNCTION
int power(int m,int n){
    if(n==0){
        return 1;
    }
    int smallerPrblm=power(m,n-1);
    int biggerPrblm=m*smallerPrblm;
    return biggerPrblm;

}
//Print Counting
int counting(int n){
    //base case
    if (n==1)   
    {
        cout<<"1"<<" ";
        return 1;

    }
    int smallerPrblm=counting(n-1);
    int biggerPrblm=1+smallerPrblm;
    cout<<biggerPrblm<<" ";
    return biggerPrblm;
}
// or
void print(int n){
    //base case
    if (n==0)
    {
        return ;
    }
    
    print(n-1);//Recursive ralation
    cout << n << " ";
    //Head Recurion
}


//printing the array
void printArray(int* a,int n){
    if(n==0){
        return;
    }
    printArray(a + 1, n-1);
    cout << a[0] << " ";
}
// or
void print(int * a,int n,int i){
    if(i>=n){
        return;
    }
    cout<<a[i]<<" ";
    print(a,n,i+1);//if we write i++ in place of i+1,
    //it will run infinitely as in post increment first prevoius value of 'i' id copied in 'i' then incremented in prevoius i by 1
}

//finding max element in array
int maxElement(int* a,int n,int &maxi){
    if(n==0){
        return INT_MIN;
    }
    if(maxi<a[0]){
        maxi=a[0];
    }
    int ans=maxElement(a+1,n-1,maxi);
    if(maxi<ans){
        return ans;
    }else{
        return maxi;
    }
    
}
//finding minimum element in array
void minElement(int *a,int n,int& mini){//pass by reference otherwise wrong answer 
    if(n==0){
        return;
    }
    if(mini>a[0]){
        mini=a[0];
    }
    minElement(a+1,n-1,mini);
}

//check an element is present or not
bool isPresent(string s,int n,char ch){
    n=s.length();
    if(n==0){
        return false;
    }
    if(s[0]==ch){
        return true;
    }
    return isPresent(s.substr(1),n-1,ch);
    
}
//or
bool checkKey(string &s,int n,int i,char key){//try to pass by reference
    if(i>=n){
        return false;
    }
    if(s[i]==key){
        return true;
    }
    int newi=i++;
    return checkKey(s,n,newi,key);
    
}
// return  first index of key
int isPresent(string &s,int n,int i,char key){
    if(i>=n){
        return -1;
    }
    if(s[i]==key){
        return i;//return is mandatory to return the first index
    }
    return isPresent(s,n,i+1,key);
}
//return all indeces of key(DON'T DO THIS ,pass by reference )
//here many times vector 'v' is created
// vector<int> indices(string&s,int i,int n,char key){
//     vector<int>v;
//     if(i>=n){
//         // v.push_back(-1);
//         return v;
//     }
//     if(s[i]==key){
//         v.push_back(i);
//     }
//     vector<int> ans=indices(s,i+1,n,key);
//     for(int x=0;x<ans.size();x++){
//         v.push_back(ans[x]);
//     }
//     return v;

// }
//or
void checkKey(string &s,int i,int n,char key,vector<int>&ans){
    if(i>=n){
        return;
    }
    if(s[i]==key){
        ans.push_back(i);
        //don't write return here,otherwise it won't traverse all indices
    }
    checkKey(s,i+1,n,key,ans);

}
//counting the frequency
void countFreq(string& s,int i,int n,char key,int& count){
    if(i>=n){
        return;
    }
    if(s[i]==key){
        count++;
    }
    countFreq(s,i+1,n,key,count);
}
//print all digits of a number
// using itrative
void printDigits(int n){
    vector<int>v;
    while (n>0)
    {
        v.push_back(n%10);
        n=n/10;

    }
    for (int i = v.size()-1; i >=0; i--)
    {
        cout<<v[i]<<" ";
    }
    
    
}
//using recursion
void digits(int n){
    if(n<=0){
        return;
    }
    digits(n/10);
    cout << n % 10 << " ";
}

//check array is sorted or not
bool isSorted(int*a ,int& n,int i){
    if(i==n-1){
        return true;//means i is at out of range,false didn't occurred means the array is sorted
    }
    if(a[i]>a[i+1]){
        return false;
    }
    bool ans= isSorted(a, n, i + 1); 
    return ans;
}
//sort array in increasing order
void SortArray(int * a,int n,int i){
    if(i==n-1){
        return;
    }
    if(a[i]>a[i+1]){
        swap(a[i],a[i+1]);
        if(a[i-1]>a[i]){
            SortArray(a,n,i-1);
        }
    }
    SortArray(a,n,i+1);

}

// binary search using recursion
int binarySearch(vector<int>&v,int s,int e,int key)
{
    if (s > e)//key not found
    {
        return -1;
    }
    int mid = (s + e) / 2;
    if (v[mid] == key)
    {
        return mid;//if key found
    }
    if (v[mid] > key)
    {
        return binarySearch(v, s, mid-1, key);
    }
    else
    {
        return binarySearch(v, mid+1,e, key);
    }
    
}
//subsequeneces of a string
void printSubsequence(string &s,string output,int i,vector<string>&v){
    if(i>=s.size()){//or i==s.size()
        cout<<output<<endl;
        v.push_back(output);
        return;
    }
    //exclude
    printSubsequence(s,output,i+1,v);
    //include
    // output.push_back(s[i]);
    output=output+s[i];
    printSubsequence(s,output,i+1,v);

}

//Integer to Words
string numberToWords_helper(int num, vector<pair<int, string>>& mp) {
    if (num == 0) {
        return "Zero";
    }
    for (auto it : mp) {
        if (num >= it.first) {
            string a = "";
            if (num >= 100) {
                a = numberToWords_helper(num / it.first, mp) + " ";
            }
            string b = it.second;
            string c = "";
            if (num % it.first != 0) {
                c = " " + numberToWords_helper(num % it.first, mp);
            }
            return a + b + c;
        }
    }
    return "";
}
string numberToWords(int num) {
    vector<pair<int, string>> mp{
        {1000000000, "Billion"},
        {1000000, "Million"},
        {1000, "Thousand"},
        {100, "Hundred"},
        {90, "Ninety"},
        {80, "Eighty"},
        {70, "Seventy"},
        {60, "Sixty"},
        {50, "Fifty"},
        {40, "Forty"},
        {30, "Thirty"},
        {20, "Twenty"},
        {19, "Nineteen"},
        {18, "Eighteen"},
        {17, "Seventeen"},
        {16, "Sixteen"},
        {15, "Fifteen"},
        {14, "Fourteen"},
        {13, "Thirteen"},
        {12, "Twelve"},
        {11, "Eleven"},
        {10, "Ten"},
        {9, "Nine"},
        {8, "Eight"},
        {7, "Seven"},
        {6, "Six"},
        {5, "Five"},
        {4, "Four"},
        {3, "Three"},
        {2, "Two"},
        {1, "One"}
    };

    return numberToWords_helper(num, mp);
}
// Wildcard Matching
bool isMatchHelper(string &s, int si, string &p, int pi)
{
    if (si == s.size() && pi == p.size())
    {
        return true;
    }
    if (si == s.size() && pi < p.size())
    {
        while (pi < p.size())
        {
            if (p[pi] != '*')
            {
                return false;
            }
            pi++;
        }
        return true;
    }
    if (s[si] == p[pi] || '?' == p[pi])
    {
        return isMatchHelper(s, si + 1, p, pi + 1);
    }
    if (p[pi] == '*')
    {
        bool caseA = isMatchHelper(s, si, p, pi + 1);
        bool caseB = isMatchHelper(s, si + 1, p, pi);
        return caseA || caseB;
    }
    return false;
}
bool isMatch(string s, string p)
{
    int si = 0;
    int pi = 0;
    return isMatchHelper(s, si, p, pi);
}

//perfect square
int numSquares_helper(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    int i = 1;
    int end = sqrt(n);
    int ans = INT_MAX;
    while (i <= end)
    {
        int perfectSquare = i * i;
        int num = 1 + numSquares_helper(n - perfectSquare);
        if (num < ans)
        {
            ans = num;
        }
        i++;
    }
    return ans;
}
int numSquares(int n)
{
    return numSquares_helper(n) - 1;
}

//Minimum Cost for Ticket
int minCostTickets_helper(vector<int> &days, vector<int> &costs, int i)
{
    // base case
    if (i >= days.size())
    {
        return 0;
    }
    // soln for 1 case

    // 1 day pass taken
    int cost1 = costs[0] + minCostTickets_helper(days, costs, i + 1);
    // 7 day pass taken
    int passEndDay = days[i] + 7 - 1;
    int j = i;
    while (j < days.size() && days[j] <= passEndDay)
    {
        j++;
    }
    int cost7 = costs[1] + minCostTickets_helper(days, costs, j);
    // 30 day pass taken
    passEndDay = days[i] + 30 - 1;
    j = i;
    while (j < days.size() && days[j] <= passEndDay)
    {
        j++;
    }
    int cost30 = costs[2] + minCostTickets_helper(days, costs, j);
    return min(cost1, min(cost7, cost30));
}
int mincostTickets(vector<int> &days, vector<int> &costs)
{
    int i = 0;
    return minCostTickets_helper(days, costs, i);
}

//number of Dice roll with target sum

int numRollsToTarget(int n, int k, int target)
{

    if (target < 0)
        return 0;
    if (n == 0 && target == 0)
        return 1;
    if (n == 0 && target != 0)
        return 0;
    if (n != 0 && target == 0)
        return 0;
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans += numRollsToTarget(n - 1, k, target - i);
    }
    return ans;
}
int main(){
    // int n;
    // cout<<"Enter n\n";
    // cin>>n;
    // cout<<"Answer is "<<factorial(n)<<endl;
    // int a[]={1,4,6,8,2};
    // print(a, 5, 0);
    // cout<<"\nIn reverse order : ";
    // printArray(a,5);
    
    // cout<<endl;
    // int maxi=INT_MIN;
    // cout<<"Max Element : "<<maxElement(a,5,maxi)<<endl;


    // int mini=INT_MAX;
    // minElement(a,5,mini);
    // cout<<"Min Element : "<<mini<<endl;
    // string s="rugung";
    // cout<<isPresent(s,6,'r')<<endl;
    // cout<<"Index : "<<isPresent(s,6,0,'p')<<endl;
  

    // cout<<checkKey(s,6,0,'r')<<endl;

   
    // vector<int> ans=indices(s,0,6,'g');
    // for (int i = 0; i < ans; i++)
    // {
    //     cout<<"Found at : "<<ans[i]<<endl;
    // }


    // vector<int>ans;
    // checkKey(s,0,6,'g',ans);
    // for(int i=0;i<ans.size();i++){
    //     cout<<"found at : "<<ans[i]<<endl;
    // }

    // int count=0;
    // countFreq(s,0,6,'z',count);
    // cout<<endl;
    // cout<<"Frequency : "<<count<<endl;
    
    // printDigits(2115);
    // cout<<endl;
    // digits(2115);

    // int a[]={99,4,5,1,3,3,0,8,7,6};
    // SortArray(a,10,0);
    // for (int i = 0; i < 10; i++)
    // {
    //     cout<<a[i]<<" ";
    // }

    // int a[]={1,1,1};
    // int n=3;
    // cout<<isSorted(a,n ,0);


    // vector<int> v={10, 20, 30, 40, 50};
    // cout<<binarySearch(v,0,5,30)<<endl;


    // string s="abc";
    // string output="";
    // int i=0;
    // vector<string>v;
    // printSubsequence(s,output,i,v);
    // cout<<"Printing all subsequences : "<<endl;
    // for(auto j:v){
    //     cout<<j<<endl;
    // }

    // string s="cdefg";
    // string p="*fg";
    // cout<<isMatch(s,p)<<endl;


    // cout<<numberToWords(12345)<<endl;

    cout<<numSquares(13)<<endl;

    return 0;
}




