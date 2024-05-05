#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_multimap<int,int>umm;
    umm.insert({1,30});
    umm.insert({2,10});
    umm.insert({1,20});
    for(auto i:umm){
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;
    umm.erase(umm.find(1));
    for(auto i:umm){
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}