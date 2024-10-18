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
class BST{
    TreeNode<int>* root;
    public:
    BST(){
        root=NULL;
    }
    ~BST(){
        delete root;
    }
    TreeNode<int>* delete_helper(TreeNode<int>* node,int data){

        if(node==NULL){
            return NULL;
        }
        if(data>node->data){
            node->right = delete_helper(node->right,data);
            return node;
        }else if(data<node->data){
            node->left=delete_helper(node->left,data);
            return node;
    
        }else{//data==node->data
            if(node->left==NULL && node->right==NULL){
                delete node;
                return NULL;
            }else if (node->left!=NULL && node->right==NULL)
            {   TreeNode<int>* temp=node->left;
                node->left=NULL;
                delete node;
                return temp;
            }
            else if (node->right != NULL && node->left == NULL)
            {
                TreeNode<int> *temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }else{//node->right!=NULL && node->left!=NULL
                //find the minimum node in right tree and replace with root
                TreeNode<int>* minNode=node->right;//min node will be at left most side
                while (minNode->left!=NULL) 
                {
                    minNode=minNode->left;
                }
                int rightMin=minNode->data;
                node->data=rightMin;
                node->right=delete_helper(node->right,rightMin);
                return node;   

            }

        }


    }
    void deleteNode(int data)
    {
        root= delete_helper(root,data);
    }

    //for inserting
    TreeNode<int> *insert_helper(TreeNode<int> *node, int data)
    {
        
        if (node == NULL)
        {
            TreeNode<int> *newNode = new TreeNode<int>(data);
            return newNode;
        }
        if(data<node->data){
            node->left=insert_helper(node->left,data);
        }else{
            node->right=insert_helper(node->right,data);
        }
        return node;
    }
    void insert(int data)
    {
        this->root = insert_helper(this->root, data);
    }


    //for searching
    bool search(int data,TreeNode<int>* node){//this function is not related to above roots and class,
        if(node==NULL){                                //it just finds a data in it's tree provided root
            return false;
        }
        if(node->data==data){
            return true;
        }else if(data<node->data){
            return search(data,node->left);
        }
        else{
            return search(data,node->right);
        }
    }
    bool isPresent(int data){
        return search(data,root);
    }
    //for printing tree

    void printTree_levelWise(TreeNode<int> *root)//BFS Traversal
    {
        if (root == NULL)
        {
            return;
        }
        queue<TreeNode<int> *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode<int> *front = q.front();
            q.pop();
            cout << front->data << ":";
            if (front->left != NULL)
            {
                cout << "L" << front->left->data << ",";
                q.push(front->left);
            }

            if (front->right != NULL)
            {
                cout << "R" << front->right->data << ",";
                q.push(front->right);
            }
            cout << endl;
        }
    }

    void printTree(){
        printTree_levelWise(root);
    }

};
int main(){
    BST b;
    b.insert(10);
    b.insert(5);
    b.insert(20);
    b.insert(7);
    b.insert(3);
    b.insert(15);
    b.printTree();
    cout<<endl;
    b.deleteNode(10);
    b.printTree();
}