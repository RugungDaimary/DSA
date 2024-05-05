#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(T data)
    {
        this->data = data;
        left = right = NULL;
    }
};
class BST{
    BinaryTreeNode<int>* root;
    public:
    BST(){
        root=NULL;
    }
    ~BST(){
        delete root;
    }
    private://for deleting
    BinaryTreeNode<int>* helperDelete(BinaryTreeNode<int>* node,int data){
        // if(node==NULL){
        //     return NULL;
        // }
        // if(data<node->data){
        //     BinaryTreeNode<int> *leftAns = helperDelete(node->left, data);
        //     node->left=leftAns;
        // }
        // if(data>node->data){
        //    BinaryTreeNode<int>* rightAns= helperDelete(node->right,data);
        //    node->right=rightAns;
        // }
        // if(data==node->data){
        //     if(node->left==NULL && node->right==NULL){
        //         delete node;
        //         return NULL;
        //     }
        //     else if(node->left!=NULL && node->right==NULL){
        //         BinaryTreeNode<int> *temp = node->left;
        //         node->left = NULL;
        //         delete node;
        //         return temp;
                
        //     }
        //     else if(node->right!=NULL && node->left==NULL){
        //         BinaryTreeNode<int> *temp = node->right;
        //         node->right = NULL;
        //         delete node;
        //         return temp;

        //     }
        //     else{//if childs are not NULL
        //         //find smallest of right sub tree and replace it with node
        //         BinaryTreeNode<int> *minNode = node->right; // min node will be at left most side
        //         while (minNode->left != NULL)
        //         {
        //             minNode = minNode->left;
        //         }
        //         int rightMin = minNode->data;
        //         node->data = rightMin;
        //         node->right = helperDelete(node->right, rightMin);
        //         return node;
        //     }
        // }

        //or appraoch
        if(node==NULL){
            return NULL;
        }
        if(data>node->data){
            node->right = helperDelete(node->right,data);
            return node;
        }else if(data<node->data){
            node->left=helperDelete(node->left,data);
            return node;
    
        }else{//data==node->data
            if(node->left==NULL && node->right==NULL){
                delete node;
                return NULL;
            }else if (node->left!=NULL && node->right==NULL)
            {   BinaryTreeNode<int>* temp=node->left;
                node->left=NULL;
                delete node;
                return temp;
            }
            else if (node->right != NULL && node->left == NULL)
            {
                BinaryTreeNode<int> *temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }else{//node->right!=NULL && node->left!=NULL
            //find the minimum node in right tree and replace with root
                BinaryTreeNode<int>* minNode=node->right;//min node will be at left most side
                while (minNode->left!=NULL) 
                {
                    minNode=minNode->left;
                }
                int rightMin=minNode->data;
                node->data=rightMin;
                node->right=helperDelete(node->right,rightMin);
                return node;   

            }
        }


    }
    public:
    void deleteData(int data)
    {
        root= helperDelete(root,data);
    }

    //for inserting
    private:
        BinaryTreeNode<int> *insertHelper(BinaryTreeNode<int> *node, int data)
        {
            // if (node == NULL)
            // {
            //     BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
            //     return newNode;
            // }
            // if (data > node->data)
            // {
            //     if (node->right == NULL)
            //     {
            //         BinaryTreeNode<int> *temp = new BinaryTreeNode<int>(data);
            //         node->right = temp;
            //         return node;
            //     }
            //     return insertHelper(node->right, data);
            // }
            // if (data < node->data)
            // {
            //     if (node->left == NULL)
            //     {
            //         BinaryTreeNode<int> *temp = new BinaryTreeNode<int>(data);
            //         node->left = temp;
            //         return node;
            //     }
            //     return insertHelper(node->left, data);
            // }
            // return node;
            //another approach
            if (node == NULL)
            {
                BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
                return newNode;
            }
            if(data<node->data){
                node->left=insertHelper(node->left,data);
                return node;
            }else{
                node->right=insertHelper(node->right,data);
                return node;
            }
            return node;
    }

    public:
        void insert(int data)
        {
            this->root = insertHelper(this->root, data);
        }


    private://for checking
    bool helper(int data,BinaryTreeNode<int>* node){//this function is not related to above roots and class,
        if(node==NULL){                                //it just finds a data in it's tree provided root
            return false;
        }
        if(node->data==data){
            return true;
        }else if(data<node->data){
            return helper(data,node->left);
        }
        else{
            return helper(data,node->right);
        }
    }
    public:
    bool hasData(int data){
        return helper(data,root);
    }
    //for printing tree
    private:
        void printTree_levelWise(BinaryTreeNode<int> *root)
        {
        if (root == NULL)
        {
            return;
        }
        queue<BinaryTreeNode<int> *> pendingNodes;
        pendingNodes.push(root);
        while (pendingNodes.size() != 0)
        {
            BinaryTreeNode<int> *front = pendingNodes.front();
            pendingNodes.pop();
            cout << front->data << ":";
            if (front->left != NULL)
            {
                cout << "L" << front->left->data << ",";
                pendingNodes.push(front->left);
            }

            if (front->right != NULL)
            {
                cout << "R" << front->right->data << ",";
                pendingNodes.push(front->right);
            }
            cout << endl;
        }
        }
    public:
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
    b.deleteData(10);
    b.printTree();
}