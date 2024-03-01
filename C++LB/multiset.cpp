#include<bits/stdc++.h>
using namespace std;
int main(){
    //both are sorted ,they are ordered
    set<int>s;
    multiset<int>ms;
    s.insert(8);
    s.insert(2);
    s.insert(3);
    s.insert(3);
    s.insert(4);
    s.insert(5);

    ms.insert(8);
    ms.insert(2);
    ms.insert(3);
    ms.insert(3);
    ms.insert(4);
    ms.insert(5);
    for(auto i:s){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i:ms){
        cout<<i<<" ";
    }
    cout<<endl;
    s.erase(3);
    // ms.erase(3);//will remove all occurrence of 3
    ms.erase(ms.find(3));//will remove the first occurrence of 3
    for(auto i:s){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i:ms){
        cout<<i<<" ";
    }
    cout<<endl;
    if(binary_search(ms.begin(),ms.end(),3))
    { // will return true if 3 found else false
        cout<<"True\n";
    }
    else{
        cout<<"False\n";
    }
    for(auto i:ms){
        cout<<i<<" "; 
    }
    cout<<endl;
    if(lower_bound(ms.begin(),ms.end(),4)!=ms.end()){
        cout << "Index " << distance( ms.begin() ,lower_bound(ms.begin(), ms.end(), 4));
    }
    cout<<endl;
    // vector<int>v{1,4,8,9};
    // cout<<"Index "<<lower_bound(v.begin(),v.end(),8)-v.begin()<<endl;



    unordered_multiset<int>m;//random data
    m.insert(1);
    m.insert(1);
    m.insert(2);
    m.insert(1);
    m.insert(4);
    for(auto i:m){
        cout<<i<<" ";
    }
    cout<<endl;
    m.erase(m.find(1));
    for(auto i:m){
        cout<<i<<" ";
    }
    cout<<endl;



    
   

    return 0;
}

