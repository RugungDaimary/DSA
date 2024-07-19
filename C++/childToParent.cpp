#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int solve(TreeNode *root)
{
    if(root==NULL)return 0;
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    int leftCnt;
    if (root->left != NULL)
    {
        leftCnt = solve(root->left);
    }
    int rightCnt;
    if (root->right != NULL)
    {
        rightCnt = solve(root->right);
    }
    return (1)+leftCnt + rightCnt;
    //1 is for the count of root itself
}

int childToParent(TreeNode *root)
{
    return solve(root);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *leftChild = new TreeNode(2);
    TreeNode *rightChild = new TreeNode(3);
    root->left=leftChild;
    root->right=rightChild;

    // for an example to count the number of nodes from (child to parent)
    cout << childToParent(root) << endl;

    return 0;
}