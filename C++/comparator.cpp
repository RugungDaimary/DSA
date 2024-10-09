#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct comp
{
    bool operator()(pair<int, int> a, pair<int, int> b) const
    {
        if (a.first == b.first)
        {
            return a.second > b.second;
        }
        return a.first < b.first;
    }
};


int main()
{

    vector<int>v={9,2,1,7,4,2};
    sort(v.begin(),v.end(),greater<int>());

    vector<pair<int, int> > vec={{1,7},{2,7},{1,3},{5,3},{2,3}};

    // sort(vec.begin(), vec.end()); // will sort the vector according to 1st parameter in increasing order
    // sort(vec.begin(), vec.end(),greater<pair<int,int> >()); // will sort the vector according to 1st parameter in decreasing order

    // for (int i = 0; i < n; i++)
    // {
    //     cout << v[i].first << " " << v[i].second << endl;
    // }

    // to sort according to 2nd parameter ,we have to make custom comparator
    sort(vec.begin(), vec.end(),comp()); //will sort the vector according to 2nd parameter
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i].first << " " << vec[i].second << endl;
    }


    return 0;
}