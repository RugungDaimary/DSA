#include<bits/stdc++.h>
using namespace std;
unordered_map<char,int>findSubstring(string& s)
{ // finding substring of same character of maximum length
    unordered_map<char,int>mp;
    
    int count=1;
    for(int i=0;i<s.length()-1;i++){
        if(s[i]==s[i+1]){
            count++;
            
        }else{
            
            mp[s[i]]=max(mp[s[i]],count);
            count=1;
        }
        mp[s[i]] = max(mp[s[i]], count); // for last character
    }
    return mp;
}

int main(){
    string s = "annnccaaccc";

    unordered_map<char, int> mp = findSubstring(s);
    
    for(auto i:mp){
        cout<<i.first<<" -> "<<i.second<<endl;
    }

    return 0;
}