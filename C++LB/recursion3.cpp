#include<bits/stdc++.h>
using namespace std;
//Coin Change
int CoinChange(vector<int>&v,int target){
    if(target==0){
        return 0;//no element is required to make '0';
    }
    if(target<0){
        return INT_MAX;//such that min doesn't update
    }

    //let's solve1 case
    int mini=INT_MAX;
    for (int i = 0; i < v.size(); i++)
    {
        int ans=CoinChange(v,target-v[i]);
        if(ans!=INT_MAX)//update mini
        mini=min(mini,ans+1);
    }
    return mini;
}
//another approach(wrong here)
int MinElements(vector<int>&v,int &target,int output){
    if(output==target){
        return 0;
    }
    if(output>target){
        return INT_MAX;
    }
    int mini=INT_MAX;
    for (int i = 0; i < v.size(); i++)
    {   output+=v[i];
        int ans=MinElements(v,target,output);
        if(ans!=INT_MAX){
            ans = ans + 1;
            mini = min(ans, mini);
        }
       
    }
    return mini;
    
}
//cut into segments(Find maximum no of segments)
int maxSegments(int n,int x,int y,int z){
    if(n==0){
        return 0;//we can't cut '0' length's rod into segments
    }
    if(n<0){
        return INT_MIN;
    }
    int ans1=maxSegments(n-x,x,y,z)+1;
    int ans2=maxSegments(n-y,x,y,z)+1;
    int ans3=maxSegments(n-z,x,y,z)+1;
    
    return max(ans1,max(ans2,ans3));

}


//maximum sum of non-adjacent elements(house Robber)
void maxLoot(vector<int>&loot,int i,int sum,int &maxi){
    if(i>=loot.size()){
        maxi=max(maxi,sum);
        return;
    }
    //include
    maxLoot(loot,i+2,sum+loot[i],maxi);
    //exclude
    maxLoot(loot,i+1,sum,maxi);

}

//add strings
void AddRE(string &num1, int p1, string &num2, int p2, int carry, string &ans)
{
    if (p1 < 0 && p2 < 0)
    {
        if (carry != 0)
        {
            ans.push_back(carry + '0');
        }
        return;
    }
    int n1 = (p1 >= 0 ? num1[p1] : '0') - '0';
    int n2 = (p2 >= 0 ? num2[p2] : '0') - '0';
    int cSum = n1 + n2 + carry;
    int digit = cSum % 10;
    carry = cSum / 10;
    ans.push_back(digit + '0');
    AddRE(num1, p1 - 1, num2, p2 - 1, carry, ans);
}

//Palindrome check Recursively, Time=>O(n) | space=>O(n )
bool isPalindrome(string &s, int i,int j){
    if(i>=j){
        return true;
    }
    if(s[i]!=s[j]){
        return false;
    }
    return isPalindrome(s,i+1,j-1);

}

//remove all occurrences of a subarray
void removeOccurrence(string& s,string &part){
    int found=s.find(part);
    if(found!=string::npos){//part string has been found,now remove it
        string left_part=s.substr(0,found);
        string right_part=s.substr(found+part.size(),s.size());
        s=left_part+right_part;
        removeOccurrence(s,part);

    }else{
        //all occurrences have been removed from s
        return;
    }

}

//print all subArrays
void printSubarray_helper(vector<int>&nums,int s,int e){
    //base case
    if(e==nums.size()){
        return;
    }
    //solve for 1 case
    for(int i=s;i<=e;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    printSubarray_helper(nums,s,e+1);
}
void printSubarray(vector<int>&nums){
    for (int s = 0; s < nums.size(); s++)
    {
        int e=s;
        printSubarray_helper(nums,s,e);    
    }  
}
int main(){
    // vector<int>v{1,2};
    // int target=7;
    // cout<<"Min no of Elements required : "<<CoinChange(v,target)<<endl;
    // cout<<"Min no of Elements required : "<<MinElements(v,target,0)<<endl;

    // int n=7;
    // int x=5;
    // int y=2;
    // int z=2;
    // int ans=maxSegments(n,x,y,z);
    // if(ans<0){
    //     ans=0;
    // }
    // cout<<ans<<endl;


    
    // int i=0;
    // int sum=0;
    // int maxi=INT_MIN;
    // vector<int>v{2,1,4,9};
    // maxLoot(v,i,sum,maxi);
    // cout<<maxi<<endl;

    // string num1="146";
    // string num2="37";
    // string ans = "";
    // int carry = 0;
    // AddRE(num1, num1.size() - 1, num2, num2.size() - 1, carry, ans);
    // reverse(ans.begin(), ans.end());
    // cout<<"SUM : "<<ans<<endl;

    // string s="aba";
    // cout<<isPalindrome(s,0,s.length()-1)<<endl;


    // string s="daabcbaabcbc";
    // cout<<s<<endl;
    // string part="abc";
    // removeOccurrence(s,part);
    // cout<<s<<endl;

    vector<int>v{1,2,3,4,5};
    printSubarray(v);

    return 0;
}