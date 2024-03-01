#include<bits/stdc++.h>
#define set_bits __builtin_popcountll

using namespace std;
int getIthBit(int n,int ith){
    int mask=1<<ith;
    int ans=n&mask;
    if(ans==0){
        return 0;
    }
    return 1;
}
void setIthBit(int n,int i){
    int mask=1<<i;
    int ans=n|mask;
    cout<<"after setting i th bit : "<<ans<<endl;
}
void clearIthBit(int& n,int i){
    int mask=~(1<<i);
    n=n&mask;
    cout<<n<<endl;
} 
void updateIthBit(int& n,int i,int target){
    //clear ith bit
    clearIthBit(n,i);
    int mask=target<<i;
    n=n|mask;
    cout<<"After update "<<n<<endl;
}
void  clearlastXbits(int n,int x){
    int mask=(-1<<x);// -1 means all bits 1
    n=n&mask;
    cout<<n<<endl;
}
bool checkPower2(int n){

    int countBits=set_bits(n);
    if(countBits==1){
      return true;
    }
    return false;
    //or
    // n&(n-1)==0 ,it is power of 2
}

//count set bits
int countSetBits(int n){//this is brute force ,TC(log n)
    int count=0;
    while(n!=0){
        int lastBit=n&1;//if n is even last bit will be 0
        if(lastBit)
            count++;
        //right shift
        n=n>>1;
    }
    return count;
}
int countSetBitsFast(int n){//or we can use __builtin_popcount(n); 
    int count=0;
    while(n!=0){
        //remove last set bit
        n=(n&(n-1));
        count++;

    }
    return count;
}
//clear bits in range
void clearBitsRange(int n,int i,int j){
    int a=(-1<<(i+1));
    int b=(1<<j)-1;//this means n&(n-1)==0 concept n=1000 ,n-1=0111
    int mask=a|b;
    n=n&mask;
    cout<<n<<endl;
}

//stairs problem->in one step you can take only steps in power of 2
// int minSteps(int n,int i){
//     if(i>n){
//         return 0;
//     }
//     int mini=0;
//     for(int index=0;index<=n;index++){
//         mini=min(mini,minSteps())
//     }
// }



//all subsequences using bit masking
void subsequences(string &s){
    vector<string>output;
    int n=s.length();
    int count=0;
    for(int i=0;i<(1<<n);i++){
        string temp="";
        //we will create subsequences in temp string
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                //non zero value ke liye include current character
                temp+=s[n-j-1];
            }            
        }
        output.push_back(temp);
        count++;
    }
    cout<<count<<endl;
    cout<<"All subsequences are: \n";
    for(auto i:output){
        cout<<i<<endl;
        cout<<endl;
    }
    cout<<endl;
}
int main()
{
    int n = 15;
    int ith = 0;
    // setIthBit(10, ith);
    // clearIthBit(n, ith);
    // updateIthBit(n,1,0);
    // clearlastXbits(7, 2);
    // clearBitsRange(15,2,1);


    string s="abc";
    subsequences(s);

    return 0;
}
