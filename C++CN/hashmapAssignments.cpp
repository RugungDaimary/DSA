#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;
// remove duplicates
vector<int> removeDuplicate(int a[],int n){
    // here time complexity is O(n);
    vector<int> v;
    unordered_map<int,bool> seen;
    for(int i=0;i<n;i++){
        if(seen.count(a[i])>0){
            continue;
        }
        seen[a[i]]=true;
        v.push_back(a[i]);
    }
    return v;
}
// or using set
// vector<int> removeDuplicate(int a[],int n){
//     vector<int> v;
//     unordered_set<int> s;
//     for(int i=0;i<n;i++){
//         if(s.insert(a[i]).second)
//         { // returns a pair consisting of an iterator(.first)
//             // and a boolean value indicating whether the element was inserted or not
//             // The iterator points to the position of the inserted element
//             v.push_back(a[i]);
//         }
//     }
//     return v;
// }


//most frequent number
// int mostFrequent(int a[],int n){
//     unordered_map<int,int>myMap;
//     for(int i=0;i<n;i++){
//         if(myMap.count(a[i])>0){
//             myMap[a[i]]++;
//         }else{
//             myMap[a[i]] = 1;
//         }

//     }
//     cout<<endl;
//     for (const auto &entry : myMap)
//     {
//         cout<<entry.first<<" "<<entry.second<<endl;
//     }
//     cout<<endl;
//     // Find the element with the highest frequency
//     int maxFrequency = 0;
//     int mostFrequentElement = 0;
//     for (const auto &entry : myMap)
//     {
//         if (entry.second > maxFrequency)
//         {
//             maxFrequency = entry.second;
//             mostFrequentElement = entry.first;
//         }
//     }

//     return mostFrequentElement;
// }
//Array of Intersection
void Intersection(int *a1,int*a2,int n,int m){
    unordered_map<int,int>myMap;
    for(int i=0;i<n;i++){
        int a=a1[i];
        if(myMap.count(a)==0){//not present
            myMap[a]=1;
        }else{//if already exists
            int prevCount=myMap[a];
            myMap[a]=prevCount+1;

        }
    }
    for(int i=0;i<m;i++){
        int a=a2[i];
        if(myMap.count(a)>0 && myMap[a]>0){
            cout<<a<<" ";
            int prevCount=myMap[a];
            myMap[a]=prevCount-1;

        }
    }
}

// Pair sum to 0 //as here k=0
int PairCount(int *a,int n,int k=0){
    unordered_map<int,int>map;
    int numPair=0;
    for (int i = 0; i < n; i++)//a+b=k
    {
        int b=-a[i];
        if(map[b]){//if found
            numPair=numPair+map[b];
        }
        map[a[i]]++;//if an element id found it's fre becomes 1 
    }
    return numPair;

}

//remove duplicate
void removeDuplicate(string s){
    map <char,int> m;
    for(int i=0;i<s.length();i++){
        if(m[s[i]]==0){
            m[s[i]];
        }
    }
    map<char,int> :: iterator it=m.begin();
    for(;it!=m.end();it++){
        cout<< it->first;
    }
}

// Longest Consecutive Sequence
vector<int> longestSequence(int a[],int n){
    vector<int>v;
    unordered_map<int,bool> m;
    for(int i=0;i<n;i++){
        m[a[i]]=true;
    }
    int maxLength=0;
    int count=0;
    int start=0;
    for(int i=0;i<n;i++){
        if(m.find(a[i])!=m.end() && m[a[i]]==true){
            if(m.find(a[i]-1)==m.end()){//if not found
                m[a[i]]=false;
                int j=1;
                while (m.find(a[i]+j)!=m.end())//if found
                {
                    m[a[i]+1]=false;
                    count++;
                    j++;
                }                  
                if(count+1>maxLength){
                    maxLength=count+1;
                    start = a[i];
                }
                count=0;//resetting value   
            }     
        } 
    }
    v.push_back(start);
    if (maxLength > 1)
    {
        v.push_back(start + maxLength - 1);
    }
    return v;
}

//  Pairs with difference K
int diffPairCount(int n,int a[],int k){
    if (k < 0){
            return 0;
    }   
    unordered_set<int> s;
    unordered_map<int, int> m;
    int count = 0;
    for (int i=0;i<n;i++) {
        s.insert(a[i]);
        m[a[i]]++;
    }
    unordered_set<int>::iterator it = s.begin();
    for (auto it: s) {
        if (k == 0) {
            if (m[it] > 1) {
                count++;
            }
            } else {
                if (m.count(it - k) > 0) {
                    count++;
                }
            }
        }
    return count;
    
}

//longest subset zero sum
int longestSubsetZeroSum(int n,int* a){
    unordered_map<int,int>map;
    int maxLength=0;
    int sum=0;
   
    for (int i = 0; i < n; i++)
    {   
        int length=0;
        sum+=a[i];
        if (sum == 0) {
            maxLength = i + 1; 
        }
        if (map.count(sum) > 0)
        {
            length=i-map[sum];
            if (length > maxLength)
            {
                maxLength = length;
            }
            continue;
        }
        map[sum]=i;
           
    }
    return maxLength;
}

int main(){
    // int a[4] = {1,-1,-1,1};
    // vector<int> v=removeDuplicate(a,7);
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i]<<" ";
    // }

    // cout<<endl;

    // cout << "most Frequent Element is " << mostFrequent(a,7)<<endl;

    // int b[5]={1,4,6,3,2};
    // Intersection(a,b,8,5);

   
    // cout<<PairCount(a,4)<<endl;

    // string s;
    // getline(cin,s);
    // removeDuplicate(s);

    int a[9]={6,3,-1,2,-4,3,1,-2,20};
    cout<<"Max length : "<<longestSubsetZeroSum( 9,a)<<endl;
    int arr[]={1,2,3,4,5};
    cout<<diffPairCount(5,arr,1)<<endl;
    


    return 0;
}
