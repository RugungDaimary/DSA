#include <bits/stdc++.h>
using namespace std;
void z_algo(string &s, string &pat)
{
    int n = s.length();
    int m = pat.length();
    vector<int> z(n);
    int l = 0, r = 0;

    for (int i = 1; i < n; i++)
    {
        // condition 1
        if (i > r)
        {
            l = i;
            r = i;
            while (r < n and s[r - l] == s[r])
            {
                r++;
            }
            r--;
            z[i] = r - l + 1;
        }
        // condition 2
        else
        {
            int j = i - l;
            // condition 2a
            if (z[j] <= r - i + 1)
            {
                z[i] = z[j];
            }
            // condition 2b
            else
            {
                l = i;
                while (r < n and s[r - l] == s[r])
                {
                    r++;
                }
                r--;
                z[i] = r - l + 1;
            }
        }
    }
    // vector<int> index;
    // for (int i = 0; i < z.size(); i++)
    // {
    //     if(z[i]==m)
    //         index.push_back(i - z[i] - m + 1);
    // }
    // for (auto it : index)
    // {
    //     cout << it << " ";
    // }
}

int main()
{
    string s = "Rugung";
    string pat = "ugu";
    string new_string = pat + "#" + s;
    z_algo(new_string, pat);

    return 0;
}