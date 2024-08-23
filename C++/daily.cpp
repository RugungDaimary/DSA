#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
    char data;
    vector<TrieNode*>child;
    bool isTerminal;
    TrieNode(char d) : data(d), child(26, nullptr),isTerminal(false)
    {
    }
    void insert(int idx,string &s,TrieNode*root){
        int n=s.length();
        if(idx>=n){
            return;
        }
        char ch=s[idx]-'a';




    }
    bool check(int idx,string &s, TrieNode *root)
    {

    }
};

int main(){
    
    return 0;
}