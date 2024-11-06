#include<bits/stdc++.h>
using namespace std;
struct cmp{
    bool operator()(vector<int>&a,vector<int>&b)const{
        return a[1]<b[1];
    }

};
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    int n=intervals.size();
    sort(intervals.begin(),intervals.end(),cmp());
    vector<vector<int>>mergedIntervals;
    int start=-1;
    int end=-1;
    for(int i=0;i<n;i++){
        int s=intervals[i][0];
        int e=intervals[i][1];
        if(start==-1){
            start=s;
            end=e;
            continue;
        }
        if(end<s){
            mergedIntervals.push_back({start,end});
            start=s;
            end=e;
        }else{
            start=min(start,s);
            end=max(end,e);
        }

    }
    return mergedIntervals;
}
int main(){
    
    
    return 0;
}