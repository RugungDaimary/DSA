#include<bits/stdc++.h>
using namespace std;
//generate all binary strings of length k without consecutive 1's
void solve(char prev ,int k,int i,string s){
  if(i==k){
    cout<<s<<endl;
    return;
  }
  solve('0',k,i+1,s+'0');
  if(prev !='1'){
    solve('1',k,i+1,s+'1');
  }

}
void genetrateBinaryString(int k){
  solve('2',k,0,"");
}
int main(){
  genetrateBinaryString(4);
  
  return 0;
}