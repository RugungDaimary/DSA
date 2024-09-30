#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>


bool isVowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

long long countOfSubstrings(string word, int k)
{
    int n = word.length();
    long long result = 0;
    map<int, int> consonant;
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (!isVowel(word[i]))
        {
            c++;
            consonant[c] = i;
        }
    }
    // for (auto it : consonant)
    // {
    //     cout << it.first << "->" << it.second << endl;
    // }
    // cout << endl;
    vector<int> index(n, -1);
    map<char, int> mp;
    int j = n - 1;

    for (int i = n - 1; i >= 0; i--)
    {
        if (isVowel(word[i]))
        {
            mp[word[i]]++;
        }
        while (mp.size() == 5)
        {
            index[j] = i;
            if (isVowel(word[j]))
            {
                mp[word[j]]--;
                if (mp[word[j]] == 0)
                {
                    mp.erase(word[j]);
                }
            }
            j--;
        }
    }
    for (auto it : index)
    {
        cout << it << " ";
    }
    cout << endl;
    int i = 0;
    j = 0;
    map<char, int> m;
    int conso = 0;
    int id = 0;
    while (j < n)
    {
        if (isVowel(word[j]))
        {
            m[word[j]]++;
        }
        else
        {
            conso++;
        }

        if (m.size() == 5 && conso == k)
        {
            if (index[j] != -1)
            {
                int idx = min(index[j], consonant[id]);
                result += (idx - i + 1);
                id++;
            }
        }

        while (conso > k)
        {
            if (isVowel(word[i]))
            {
                m[word[i]]--;
                if (m[word[i]] == 0)
                {
                    m.erase(word[i]);
                }
            }
            else
            {
                conso--;
            }
            i++;
        }

        j++;
    }

    return result;
}


int main()
{
    string s = "iqeaouqi";
    int k = 2;
    cout << countOfSubstrings(s, k) << endl;

    return 0;
}
