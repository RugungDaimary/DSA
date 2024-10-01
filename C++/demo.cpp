#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>


void Z_algo(string &s, vector<int> &z)
{
    int n = s.length();
    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i > r)
        {
            l = i, r = i;
            bool not_match = false;
            while (r < n)
            {

                if (s[r - l] != s[r])
                {
                    if (not_match)
                        break;
                    not_match = true;
                }
                r++;
            }
            r--;
            z[i] = r - l + 1;
        }
        else
        {
            int j = i - l;
            if (z[j] < (r - i + 1))
            {
                z[i] = z[j];
            }
            else
            {
                l = i;
                bool not_match = false;
                while (r < n)
                {

                    if (s[r - l] != s[r])
                    {
                        if (not_match)
                            break;
                        not_match = true;
                    }
                    r++;
                }
                r--;
                z[i] = r - l + 1;
            }
        }
    }
    for (auto it : z)
    {
        cout << it << " ";
    }
    cout << endl;
}
int minStartingIndex(string s, string pattern)
{
    int m = pattern.length();
    string new_string = pattern + "#" + s;
    // cout << new_string << endl;
    int n = new_string.length();
    vector<int> z(n);
    Z_algo(new_string, z);
    for (int i = m + 1; i < n; i++)
    {
        if (z[i] == m)
            return (i - (m + 1));
    }
    return -1;
}
int main()
{
   

    // string s = "abcdefg";
    // string pattern = "bcdffg";
    // cout << minStartingIndex(s, pattern) << endl;

    return 0;
}




