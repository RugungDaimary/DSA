// // minimize substring windows
// #include<bits/stdc++.h>
// using namespace std;
// string minWindow(string s, string t)
// {
//   int m = s.length();
//   int n = t.length();
//   int start = 0;
//   int ansIndex = -1;
//   int ansLen = INT_MAX;
//   if (m < n)
//   {
//     return "";
//   }
//   unordered_map<char, int> sMap;
//   unordered_map<char, int> tMap;
//   // to keep track of all characters of P string
//   for (int i = 0; i < t.length(); i++)
//   {
//     tMap[t[i]]++;
//   }
//   int count = 0;
//   for (int i = 0; i < s.length(); i++)
//   {
//     char ch = s[i];
//     sMap[ch]++;
//     // valid character -> jo character tumhare pattern me bhi ho
//     if (sMap[ch] <= tMap[ch])
//     {
//       count++;
//     }
//     if (count == n)
//     {
//       // window is ready
//       // minimise the window -> freq decrement, ans update , start ko aage badhana h
//       while (sMap[s[start]] > tMap[s[start]] || tMap[s[start]] == 0)
//       {
//         if (sMap[s[start]] > tMap[s[start]])
//           sMap[s[start]]--;
//         start++;
//       }
//       // ans update
//       int lengthOfWindow = i - start + 1;
//       if (lengthOfWindow < ansLen)
//       {
//         ansLen = lengthOfWindow;
//         ansIndex = start;
//       }
//     }
//   }
//   if (ansIndex == -1)
//     return "";
//   else
//     return s.substr(ansIndex, ansLen);
// }
// int main(){
//   cout<<minWindow("ADOBECODEBANC", "ABC")<<endl;
//   return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;
//         vector<vector<int>>matrix(n,vector<int>(n));
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 cin>>matrix[i][j];
//             }
//         }
//         vector<int>output(n);

//         for(int i=0;i<n;i++){
//             int ans;
//             for(int j=0;j<n;j++){
//                 if(i==j){
//                     continue;
//                 }
//                 ans=ans&matrix[i][j];
//             }
//             output.push_back(ans);
//         }
//         bool flag=false;
//         for(int i=0;i<output.size();i++){
//             if(output[i]!=0){
//                 flag=true;
//                 break;

//             }

//         }
//         if(flag==false){
//             cout<<"NO\n";
//         }else{
//             cout<<"YES\n";
//             for(auto i:output){
//                 cout<<i<<" ";
//             }
//             cout<<endl;
//         }

//     }
//     return 0;
// }
