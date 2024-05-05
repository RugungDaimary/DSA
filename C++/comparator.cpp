#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(pair<int,int>a,pair<int,int>b){
    return a.second<b.second;
}
bool comp1(pair<int,int>a,pair<int,int>b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    return a.first < b.first;
}

int main()
{

    int n;
    cin >> n;
    // built in comparator
    //  vector<int> v(n);
    //  for(int i=0;i<n;i++){
    //    cin>>v[i];
    //  }
    //  sort(v.begin(),v.end(),greater<int>());
    //  for(int i=0;i<n;i++){
    //    cout<<v[i]<<" ";
    //  }


    // input type is pair
    vector<pair<int, int> > v;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x,y));
    
    }
    cout<<endl;
    // sort(v.begin(), v.end()); // will sort the vector according to 1st parameter in increasing order
    // sort(v.begin(), v.end(),greater<pair<int,int> >()); // will sort the vector according to 1st parameter in decreasing order

    // for (int i = 0; i < n; i++)
    // {
    //     cout << v[i].first << " " << v[i].second << endl;
    // }

    // to sort according to 2nd parameter ,we have to make custom comparator
    // sort(v.begin(), v.end(),comp); //will sort the vector according to 2nd parameter
    // for (int i = 0; i < n; i++)
    // {
    //     cout << v[i].first << " " << v[i].second << endl;
    // }

    sort(v.begin(), v.end(),comp1); 
    for (int i = 0; i < n; i++)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }

    return 0;
}