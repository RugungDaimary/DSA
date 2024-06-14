#include<bits/stdc++.h>
using namespace std;
class TrieNode
{
public:
    TrieNode *left;  // for 0
    TrieNode *right; // for 1

    TrieNode()
    {
        left = NULL;
        right = NULL;
    }
};
class Solution
{
public:
    TrieNode *root;

    Solution() { root = new TrieNode(); }

    void buildTrie(int num)
    {
        TrieNode *temp = root;
        for (int i = 30; i >= 0; --i)
        {
            if ((num >> i) & 1)
            { // if the ith bit is 1
                if (temp->right == NULL)
                {
                    temp->right = new TrieNode();
                }
                temp = temp->right;
            }
            else
            { // if the ith bit is 0
                if (temp->left == NULL)
                {
                    temp->left = new TrieNode();
                }
                temp = temp->left;
            }
        }
    }

    int findXorMax(int num)
    {
        TrieNode *temp = root;
        int maxXor = 0;
        for (int i = 30; i >= 0; --i)
        {
            int bit = (num >> i) & 1;
            if (bit == 1)
            {
                if (temp->left != NULL)
                {
                    maxXor += (1 << i);
                    temp = temp->left;
                }
                else
                {
                    temp = temp->right;
                }
            }
            else
            {
                if (temp->right != NULL)
                {
                    maxXor += (1 << i);
                    temp = temp->right;
                }
                else
                {
                    temp = temp->left;
                }
            }
        }
        return maxXor;
    }

    int findMaximumXOR(vector<int> &nums)
    {
        for (int num : nums)
        {
            buildTrie(num);
        }
        int maxXor = 0;
        for (int num : nums)
        {
            maxXor = max(maxXor, findXorMax(num));
        }
        return maxXor;
    }
};
int main(){
    
}