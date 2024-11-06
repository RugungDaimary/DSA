#include<bits/stdc++.h>
using namespace std;

void solve()
{
    string given;
    cin >> given;
    string to_make;
    cin >> to_make;
    int m = given.length();
    int n = to_make.length();
    string k = ""; // no need, we will not append to this, as this might result in tle/mle

    vector<int> indices[26];
    for (int i = 0; i < m; i++)
    {
        indices[given[i] - 'a'].push_back(i);
    }
    int idx = 0;
    int iterations_over_given_string = 0;
    int prev = 0;
    while (idx < n)
    {
        int actual_idx = to_make[idx] - 'a';
        auto itr = lower_bound(indices[actual_idx].begin(), indices[actual_idx].end(), prev);
        if (itr == indices[actual_idx].end())
        {
            prev = 0;
            iterations_over_given_string++;
            auto jtr = lower_bound(indices[actual_idx].begin(), indices[actual_idx].end(), prev);
            if (jtr == indices[actual_idx].end())
            {
                cout << "Not possible to get the string as subsequence of another string" << endl;
                return;
            }
            else
            {
                prev = *jtr;
            }
        }
        else
        {
            prev = *itr;
        }
        idx++;
    }
    cout << iterations_over_given_string + 1 << endl;
}
int main(){


    return 0;
}

