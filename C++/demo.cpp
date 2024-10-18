#include <bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(T data)
    {
        this->data = data;
        left = right = NULL;
    }
};
class BST
{
    TreeNode<int> *root;

    void deleteTree(TreeNode<int>* node) {
        if (node == NULL) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

public:
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        deleteTree(root);
    }
    //Insertion
    TreeNode* insert_helper(TreeNode* node,int data){
        if(node==NULL){
            TreeNode* newNode=new TreeNode(data);
            return newNode;
        }
        if(node->data<data){//right side
            node->right=insert_helper(node->right,data);

        }else{
            node->left = insert_helper(node->left, data);
        }
        return node;

    }
    void insert(int data) {
        root = insert_helper(root, data);
    }
    TreeNode* delete_helper(TreeNode* node,int data){
        if(node==NULL)return NULL;
        if(data<node->data){//left side
            node->left = delete_helper(node->left,data);

        }else if(data>node->data)//right side
        {
            node->right = delete_helper(node->right, data);
        }else{//node-data==data
            if(node->left==NULL && node->right==NULL){
                delete node;
                return NULL;
            }else if(node->left!=NULL && node->right){
                TreeNode* temp=node->left;
                node->left=NULL;
                delete node;
                return temp;
            }else if( node->right!=NULL && node->left==NULL){
                TreeNode* temp=node->right;
                node->right=NULL;
                delete node;
                return temp;
            }else{//both left and right are not null
                //find the minimum value in right side 
                //kyuki minimum lement sabse leftmost pe hi hoga
                TreeNode* rightNode=node->right;
                while(rightNode->left!=NULL){
                    rightNode=rightNode->left;
                }
                int minData=rightNode->data;
                node->data=minData;
                node->right=delete_helper(node->right,minData);
                return node;
            }

        }
    }
    void deleteNode(int data) {
        root = delete_helper(root, data);
    }
    pair<TreeNode*,bool>search_helper(TreeNode* node,int data){
        if(node==NULL){
            return {NULL,false};
        }
        if(node->data==data){
            return {node,true};
        }
        if(data<node->data){
            return search_helper(node->left,data);
        }
        if (data > node->data)
        {
            return search_helper(node->right, data);
        }

    }
    bool search(TreeNode* root,int data){
        pair<TreeNode*,bool>ans=search_helper(root,data);
        if(ans.second)return true;
        return false;

    }

    //check isBST or not
    int findMaximum(TreeNode* node){
        if(node==NULL)return INT_MIN;

        int ans=max({node->data,findMaximum(node->left),findMaximum(node->right)});
        return ans;

    }
    int findMinimum(TreeNode* node){
        if (node == NULL)
            return INT_MAX;

        int ans = min({node->data, findMaximum(node->left), findMaximum(node->right)});
        return ans;
    }
    bool isBST(TreeNode* root){
        if(root==NULL)return true;
        if(isBST(root->left) && isBST(root->right))return true;
        int leftMaxi = findMaximum(root->left);
        int rightMini = findMinimum(root->right);
        if (leftMaxi < root->data && root->data < rightMini)
        {
            return true;
        }
        return false;

    }
};





// #include <bits/stdc++.h>
// #include <list>

// using namespace std;

// int main()
// {
//     list<int> dll;
//     map<int, list<int>::iterator> mp;
//     dll.push_front(1);
//     mp[1] = dll.begin();
//     dll.push_front(2);
//     mp[2] = dll.begin();
//     dll.push_front(3);
//     mp[3] = dll.begin();
//     dll.push_front(4);
//     mp[4] = dll.begin();

//     for (auto val : dll) {
//         cout << val << " ";
//     }
//     cout<<endl;
//     dll.erase(mp[2]);
//     for (auto val : dll)
//     {
//         cout << val << " ";
//     }

//     return 0;
// }
