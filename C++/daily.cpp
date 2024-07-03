#include <bits/stdc++.h>
using namespace std;
bool checkPalindrome(int i, int j, string &s)
{
  
  if (i > j)
    return true;
  if (s[i] == s[j])
  {
    return checkPalindrome(i + 1, j - 1, s);
  }
  return false;
}
int main()
{
  string s = "ruugng";
  if (checkPalindrome(0, s.length() - 1, s))
  {
    cout << "YES\n";
  }
  else
  {
    cout << "NO\n";
  }
  return 0;
}

