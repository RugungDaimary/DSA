//Qn}count no of unique string
#include<bits/stdc++.h>
using namespace std;
int base=31;
int mod=1e9+7;
const int N=1e5+3;//size of vector
vector<long long>power(N,0);
void calculatePower(){

    for (int i = 0; i < N; i++)
    {
        if (i == 0)
        {
            power[0] = 1 ;
            continue;
        }
        power[i] = (power[i - 1] * base) % mod;
    }
}
long long calculateHash(string &s){
   
    long long h=0;
    for(int i=0;i<s.length();i++){
        int idx=s[i]-'a'+1;
        
        h=(h+idx*power[i])%mod;
    }
    return h;

}
int main(){
    
    vector<string>s={"aa","ab","aa","ac","bd","aa"};
    int n=s.size();
    /*
    sort(s.begin(),s.end());//here the sort function takes(nlog(n)) for integer values and comparing between two string takes O(m)) 
    //so the total time complexity is O(nmlog(n));//m is the avg length of each string
    int count=1;
    for(int i=0;i<n-1;i++){
        if(s[i]!=s[i+1])count++;

    }
    cout<<"No of unique strings : "<<count<<endl;
    */

    //TO optimise the string comparison between the two string we use hash values(integer comparison is O(1))
    //so the time complexity will reduce to O(nlog(n))

    vector<long long>hash;
    for(auto &t:s){
        hash.push_back(calculateHash(t));
    }
    sort(hash.begin(),hash.end());
    int cnt = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (hash[i] != hash[i + 1])
            cnt++;
    }
    cout << "No of unique strings : " << cnt << endl;
    cout<<('z'-'a')<<endl;

    return 0;
}



/*
class StringHash {
public:
	vector<long long>ps1,ps2;
	long long Q1 = 271, Q2 = 277, M1 = 1000000007, M2 = 998244353;
	StringHash(string s) {
		ps1 = vector<long long>(s.size()+1); ps2 = vector<long long>(s.size()+1);
		for (int i = 1; i <= s.size(); i++) {
			long long c = s[i-1] + 1;
			ps1[i] = ((Q1 * ps1[i-1]) + c)%M1;
			ps2[i] = ((Q2 * ps2[i-1]) + c)%M2;
		}
	}
	long long int powxy(long long int x, long long int y, long long M) {
		if (y == 0) return 1;
		if (y%2 == 1) return (x*powxy(x, y-1, M))%M;
		long long int t = powxy(x, y/2, M);
		return (t*t)%M;
	}
	long long substrHash1(int firstIndex, int lastIndex) {
		long long rem = (powxy(Q1,lastIndex-firstIndex+1,M1) * ps1[firstIndex])%M1;
		return (ps1[lastIndex+1] - rem + M1)%M1;
	}
	long long substrHash2(int firstIndex, int lastIndex) {
		long long rem = (powxy(Q2,lastIndex-firstIndex+1,M2) * ps2[firstIndex])%M2;
		return (ps2[lastIndex+1] - rem + M2)%M2;
	}
	pair<long long, long long> substrHash(int firstIndex, int lastIndex) {
		return {substrHash1(firstIndex, lastIndex), substrHash2(firstIndex, lastIndex)};
	}
};
*/