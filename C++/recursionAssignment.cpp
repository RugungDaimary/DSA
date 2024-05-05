#include<bits/stdc++.h>
using namespace std;
//last occurrence of a character in string-> O(n) time complexity
//space complexity O(n)
void lastOccurrenceLtoR(string s,int i,int &ans,char &ch){
    if(i>=s.size()){
        return;
    }
    if(s[i]==ch){
        ans=i;
    }
    lastOccurrenceLtoR(s,i+1,ans,ch);
}
void lastOccurrenceRtoL(string s,int i,int &ans,char& ch){
    if(i<0){
        return;
    }
    if(s[i]==ch){
        ans=i;
        return;
        
    }
    lastOccurrenceRtoL(s,i-1,ans,ch);

}
//Reverse a string recursively Inplace
void reverseString(string &s,int i,int j){//time complexity=> O(n/2)=>O(n)/space=>O(n)
    if(i>j){
        return;
    }
    swap(s[i],s[j]);
    reverseString(s,i+1,j-1);

}

//add two strings recursively

int main(){
    string s="rugung";
    char ch='g';
    int ans=-1;
    // lastOccurrenceLtoR(s,0,ans,ch);
    // cout<<"Index : "<<ans<<endl;

    // lastOccurrenceRtoL(s,s.size()-1,ans,ch);
    // cout<<"Index : "<<ans<<endl;
    reverseString(s,0,s.size()-1);
    cout<<s<<endl;

    return 0;
}