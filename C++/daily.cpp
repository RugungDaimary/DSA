#include<bits/stdc++.h>
using namespace std;
vector<int>computePrime(){
    vector<bool>numbers(1000,true);

    for(int i=2;i<=1000;i++){
        if(numbers[i]){
            for(int j=i*i;j<=1000;j+=i){
                numbers[j]=false;
            }
        }
    }
    vector<int>primes;
    for(int i=2;i<=1000;i++){
        if(numbers[i]){
            primes.push_back(i);
        }
    }
    cout<<endl;
    for(int i=2;i<=1000;i++){
        if(numbers[i]){
            cout<<i<<" ";
        }
    }
    return primes;

}
int main(){
    computePrime();
    
    return 0;
}