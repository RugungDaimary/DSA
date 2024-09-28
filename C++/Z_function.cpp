#include<bits/stdc++.h>
using namespace std;
int Z_funcion(string &text,string &pat){
    int n=text.size();
    int m=pat.size();
    vector<int>Z;

    string new_string=pat+"#"+text;
    int len=new_string.length();
    //put 0 values upto m+1 in Z vector
    int i=0;
    while (i < len)
    {
        if(i<=m)Z.push_back(0);
        else{
            int left=0,right=i;
            while (right < len && new_string[left] == new_string[right])
            {
                left++;
                right++;
            }
            i=right
            Z.push_back(left);
        }
        i++;
    }
    for(auto i=0;i<len;i++){
        if(Z[i]==m){
            return i-m-1;
        }
    }
    return -1;
}
int main(){
    string s="Rugung";
    string pat="ugu";
    cout<<Z_funcion(s,pat)<<endl;
    
    return 0;
}