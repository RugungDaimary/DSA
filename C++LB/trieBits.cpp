// Trie for bits
// Qn) Finding the Maximum XOR of Two Numbers in an Array
#include<bits/stdc++.h>
using namespace std;

//traversing all bits from leftmost to rightmost
void traverse (int n){
    for(int i=31;i>=0;i--){
        int ith_bit=n>>i;
        if(ith_bit&1){
            cout<<i<<"th bit is "<<(ith_bit&1)<<endl;
        }else{
            cout << i << "th bit is " << (ith_bit & 1) << endl;
        }
    }
}

class TrieNode{
    public:
    int bit;
    TrieNode* left;//for 0
    TrieNode* right;// for 1
    TrieNode(int b){
        this->bit=b;
        left=NULL;
        right=NULL;
    }
};
void insert(TrieNode* root,int num){
    TrieNode* temp=root;
    for(int i=31;i>=0;i--){
        int ith_bit=(num>>i)&1;
        if(ith_bit){//means ith bit is 1
            if(temp->right!=NULL){//
                temp=temp->right;

            }else{
                TrieNode* child=new TrieNode(ith_bit);
                temp->right=child;
                temp=temp->right;

            }

        }else{//means ith bit is 0
            if(temp->left!=NULL){
                temp=temp->left;

            }else{
                TrieNode* child=new TrieNode(ith_bit);
                temp->left=child;
                temp=temp->left;
            }
        }
    }
    

}

int findMaxXOR_Helper(TrieNode* root,int num){
    TrieNode* temp=root;
    int ans=0;
    for(int i=31;i>=0;i--){
        int ith_bit=(num>>i)&1;
        if(ith_bit){//means 1
            if(temp->left!=NULL){
                int Xor=(ith_bit^0);
                ans+=(pow(2,i)*Xor);
                temp=temp->left;

            }else{
                int Xor = (ith_bit ^ 1);
                ans+=(pow(2,i)*Xor);
                temp = temp->right;
            }

        }else{//means 0
            if(temp->right!=NULL){
                int Xor = (ith_bit ^ 1);
                ans += (pow(2, i) * Xor);
                temp = temp->right;
            }else{
                int Xor = (ith_bit ^ 0);
                ans += (pow(2, i) * Xor);
                temp = temp->left;
            }
        }

    }
    return ans;

}
int findMaximumXOR(vector<int> &nums)

{
    int n = nums.size();
    TrieNode *root = new TrieNode(0);
    //for insertion of nums in trie
    for(int i=0;i<n;i++){
        insert(root,nums[i]);
    }//Insertion of nums is done ,now the trie is ready
    
    int result=INT_MIN;
    for(int i=0;i<n;i++){
        result=max(result,findMaxXOR_Helper(root,nums[i]));

    }
    return result;
}
int main(){
    traverse(255);
    vector<int>nums{3,5,2,7};
    cout<<findMaximumXOR(nums)<<endl;

 

    return 0;
}