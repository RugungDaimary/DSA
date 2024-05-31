#include<bits/stdc++.h>
using namespace std;
int countTriplets(vector<int> &nums)
{
    int n = nums.size();
    int cnt = 0;
    int Xor = 0;       
    unordered_map<int, vector<int> > mp;
    for (int i = 0; i < n; i++)
    {
        Xor ^= nums[i];
        if (Xor == 0)
        {
            cnt += i;
        }
        if (mp.find(Xor) != mp.end())
        {
            for(auto idx: mp[Xor]){
                cnt+=i-idx-1;
            }
        }
        mp[Xor].push_back(i);
      
    }

    return cnt;
}
int main(){
    vector<int> nums = {1, 1, 1, 1, 1};
    cout << countTriplets(nums) << endl;

    
    return 0;
}