#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//find maximum train that is accommodated in 1 platform
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int solve(int n, int arr[], int dept[])
{
    vector<pair<int, int>> data;
    for (int i = 0; i < n; i++)
    {
        data.push_back({arr[i], dept[i]});
    }

    sort(data.begin(), data.end(), cmp);

    int cnt = 1;
    cout << data[0].first << ", " << data[0].second << endl;
    int lastDept = data[0].second;
    for (int i = 1; i < n; i++)
    {
        if (data[i].first >= lastDept)
        {
            // current train can be included
            cnt++;
            lastDept = data[i].second;
            cout << data[i].first << ", " << data[i].second << endl;
        }
    }
    return cnt;
}



//find maximum platforms required to accommodate N trains
int findPlatform(int arr[], int dep[], int n)
{
    // Your code here
    int minPlatform = 1;
    int platformRequired = 1;
    sort(arr, arr + n);
    sort(dep, dep + n);

    int i = 1;
    int j = 0;
    while (i < n && j < n)
    {
        if (arr[i] <= dep[j])
        {
            minPlatform++;
            platformRequired = max(minPlatform, platformRequired);
            i++;
        }
        else
        {
            j++;
            minPlatform--;
        }
    }
    return platformRequired;
}

int main()
{
    // int n = 4;
    // int arr[] = {5, 8, 2, 4};
    // int dept[] = {7, 11, 6, 5};

    // int ans = solve(n, arr, dept);
    // cout << "Answer is:  " << ans << endl;


    
    int n = 6;
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    cout<<findPlatform(arr,dep,n)<<endl;

    return 0;
}
