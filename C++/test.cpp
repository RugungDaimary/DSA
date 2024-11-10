
// #include<bits/stdc++.h>
// using namespace std;

// void solve()
// {
//     string given;
//     cin >> given;
//     string to_make;
//     cin >> to_make;
//     int m = given.length();
//     int n = to_make.length();
//     string k = ""; // no need, we will not append to this, as this might result in tle/mle

//     vector<int> indices[26];
//     for (int i = 0; i < m; i++)
//     {
//         indices[given[i] - 'a'].push_back(i);
//     }
//     int idx = 0;
//     int iterations_over_given_string = 0;
//     int prev = 0;
//     while (idx < n)
//     {
//         int actual_idx = to_make[idx] - 'a';
//         auto itr = lower_bound(indices[actual_idx].begin(), indices[actual_idx].end(), prev);
//         if (itr == indices[actual_idx].end())
//         {
//             prev = 0;
//             iterations_over_given_string++;
//             auto jtr = lower_bound(indices[actual_idx].begin(), indices[actual_idx].end(), prev);
//             if (jtr == indices[actual_idx].end())
//             {
//                 cout << "Not possible to get the string as subsequence of another string" << endl;
//                 return;
//             }
//             else
//             {
//                 prev = *jtr;
//             }
//         }
//         else
//         {
//             prev = *itr;
//         }
//         idx++;
//     }
//     cout << iterations_over_given_string + 1 << endl;
// }
// int main(){

//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
int solve(string& target,string& s){//we have to return how many times s should be added such that target becomes subsequences of s
    int n=s.length();
    int m=target.length();
    vector<vector<int>>index(26,vector<int>());

    for(int i=0;i<n;i++){
        int idx=s[i]-'a';
        index[idx].push_back(i);
    }
    int prev = -1;
    int count=0;
    int i=0;
    while(i<m){
        int idx = s[i] - 'a';
        auto itr = upper_bound(index[idx].begin(), index[idx].end(), prev);
        if (itr == index[idx].end())
        {
            count++;
            prev = -1;
        }
        else
        {
            prev = *itr;
            i++;
        }
    }

    return count;

}
int substring(string& target,string& s){//we have to return how many times s should be added such that target becomes subsequences of s
    int n=target.length();
    int m=s.length();
    vector<vector<int>>index(26,vector<int>());
    for(int i=0;i<m;i++){
        int idx=s[i]-'a';
        index[idx].push_back(i);
    }
    int prev = -1;
    int count=0;
    int i=0;
    bool taken=false;
    while(i<n){
        int idx = target[i] - 'a';
        if(index[idx].size()==0){
            return -1;
        }
        if(taken){
            if (binary_search(index[idx].begin(), index[idx].end(), prev + 1))
            {
                prev++;
                i++;
            }
            else
            {
                if(index[idx][0]!=0)return -1;
                prev=0;
                count++;
                i++;
            }
        }else{
            prev = index[idx][0];
            taken=true;
            i++;
        }

    }

    return count+1;

}
int main(){

    string s="abcd";
    string target = "cdabcdab";
    cout<<substring(target,s)<<endl;

    return 0;
}