#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr={1,5,7,8,2,6};
    map<pair<int, int>, int> maxi;
    for (int i = 0; i < arr.size(); i++)
    {
        maxi[{i, i}] = arr[i];
        for (int j = i + 1; j < arr.size(); j++)
        {
            maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
        }
    }
    for(auto i:maxi){
        pair<int,int>p=i.first;
        cout<<p.first<<" "<<p.second<<" : "<<i.second<<endl;

    }
    return 0;
}