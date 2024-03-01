#include<bits/stdc++.h>
using namespace std;
bool checkPrime(int n){ // TC-> O(sqrt(n));
    int count=0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            count++;
            if((n/i)!=i){
                count++;
            }
        }
    }
    if(count==2)return true;
    return false;

}

int N=100000000;
bool sieve[10000000+1];//whenever something is declared globally ,all are marked as 0
vector<int>primes;
void createSieve(){//TC-> N*log(logN);
    //as primme no starts from 2
    for(int i=2;i<=N;i++){
        sieve[i]=true;
    }
    
    for(int i=2;i*i<=N;i++){//as beyond i*i to N all not primes has been marked false till i*i
        if(sieve[i]==true){
            for(int j=i*i ;j<=N;j+=i){//as all primes between 1 to i*i-1  has been marked
                sieve[j]=false;
            }      
        }
    }

    //finding the kth prime no
    int limit=5*1000000;//(5*10^6) is the k's limit
    int cnt=0;
    int size=1;

    for(int i=2;;i++)//till infinity
    {
        if(sieve[i]==true){
            cnt++;

        }
        if(cnt==limit){
            size=i ;
            break;
        }
    }
    cout<<size<<endl;

    for(int i=2;i<=N;i++){//finding kth prime no
        if(sieve[i]==true){
            primes.push_back(i);
        }
    }
}



//Qn) how many numbers in the range 1 to 10^6 have minimum prime factor as n,n is every prime no
/*
int n=1000000;
int sieve[1000000+1];
void createSieve(){
    for(int i=2;i<=n;i++){
        sieve[i]=1;
    }
    for(int i=2;i*i<=n;i++){
        for(int j=i*i;j<=n;j+=i){
            if(sieve[j]!=0){
                sieve[i]++;
                sieve[j]=0;
            }
        }
    }
}
*/

int main(){
    createSieve();
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        // if(checkPrime(n)){
        //     cout<<"YES\n";
        // }else{
        //     cout<<"NO\n";
        // }
        if(sieve[n]==true){
            cout<<"YES\n";

        }else{
            cout<<"NO\n"; 
        }
    }
    
    
    return 0;
}