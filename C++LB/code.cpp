
#include<bits/stdc++.h>
using namespace std;
int longestValidParentheses(string s)
{

    int maxi=0;
    int n = s.length();
    int i = 0;
    int ans = 0;
    int count = 0;
    stack<char> st;
    while (i < n)
    {
        if (s[i] == '(') // opening bracket
        {
            st.push(s[i]);
        }
        else
        { // closing bracket
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
                count++;
                ans=max(ans,count);
                if (st.empty())
                {
                    ans += count;
                    
                    count=0;
                }
            }
            else
            {
                maxi=max(ans,maxi);
                ans=0;
                count = 0;
            }
        }
        i++;
    }
    ans=max(ans,count);
    maxi = max(ans, maxi);
    if (!st.empty())
    {
        st.pop();
    }
    cout << ans*2 << endl;
    i = n - 1;
    count = 0;
    int result=0;
    while (i >= 0)
    {
        if (s[i] == ')')
        {
            st.push(s[i]);
        }
        else
        {
            if (!st.empty() && st.top() == ')')
            {
                st.pop();
                count++;
                ans = max(ans, count);
                if (st.empty())
                {
                    result += count;
                    
                    count = 0;
                }
            }
            else
            {
                maxi = max(result, maxi);
                result=0;
                count = 0;
            }
        }
        i--;
    }
    result = max(result, count);
    maxi = max(result, maxi);
    int y=max(ans,result);
    cout<<y<<endl;
    return maxi * 2;
}

int main(){
    // string s = "(()(((()";
    // cout<<longestValidParentheses(s)<<endl;
    string s = "(*)";
    if(checkValidString(s)){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }

    return 0;
}
