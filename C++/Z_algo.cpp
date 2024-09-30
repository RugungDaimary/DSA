#include <bits/stdc++.h>
using namespace std;
void Z_function(string &s, vector<int> &z)
{
    int n = s.length();
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
            if (z[j] < r - i + 1)
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
}

int main()
{
    string text = "rugngngf";
    string pat = "rug";
    string new_string = pat + "$" + text;
    int m = pat.length();
    int n = new_string.length();
    vector<int> z(n);
    Z_function(new_string, z);
    for (int i = m + 1; i < n; i++)
    {
        if (z[i] == m)
        {
            cout << "Found at index " << i - (m + 1) << endl;
        }
    }

    return 0;
}