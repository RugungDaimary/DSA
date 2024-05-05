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
BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root Data\n";
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }
        cout << "Enter right child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }

    }
    return root;
}

void printTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ": ";
    if (root->left != NULL)
    {
        cout << "L" << root->left->data << ",";
    }
    if (root->right != NULL)
    {
        cout << "R" << root->right->data;
    }
    cout << endl;

    printTree(root->left);
    printTree(root->right);
}
void levelorderTraversal(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(nullptr);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        if (front != NULL)
        {
            cout << front->data << " ";
            if (front->left != NULL)
            {
                pendingNodes.push(front->left);
            }
            if (front->right != NULL)
            {
                pendingNodes.push(front->right);
            }
        }
        else
        { // front==NULL
            cout << endl;
            if (!pendingNodes.empty())
            {
                pendingNodes.push(nullptr);
            }
            else
            {
                break;
            }
        }
    }
}

// Create  Insert Duplicate Node
void createInsertDuplicateNode(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    int data=root->data;
    BinaryTreeNode<int>* current=new BinaryTreeNode<int>(data);
    BinaryTreeNode<int> *temp=root->left;
    root->left=current;
    current->left=temp;
    createInsertDuplicateNode(current->left);
    createInsertDuplicateNode(root->right);

}

// Pair sum Binary Tree( Here time complexity is reduced to O(nlogn))
void preorderTraversal(BinaryTreeNode<int> *root, vector<int>& v)
{
    if(root==NULL){
        return;
    }
    v.push_back(root->data);
    preorderTraversal(root->left,v);
    preorderTraversal(root->right,v);
}
void pairSum(BinaryTreeNode<int>* root,int s){
    vector<int>v;
    preorderTraversal(root,v);
    sort(v.begin(),v.end());
    int i=0;
    int j=v.size()-1;
    while (i<=j)
    {
        if(v[i]+v[j]==s){
            cout<<v[i]<<" "<<v[j]<<endl;
            i++;
            j--;
        }
        else if(v[i]+v[j]>s){
            j--;
        }else{
            i++;
        }

    }
}

// LCA of Binary Tree
BinaryTreeNode<int> *LCA(BinaryTreeNode<int> *root, BinaryTreeNode<int> *node1, BinaryTreeNode<int> *node2){
    if(root==NULL){
        return NULL;
    }
    if(node1->data==root->data || node2->data==root->data){
        return root;
    }
    BinaryTreeNode<int> *leftAns = LCA(root->left,node1,node2);
    BinaryTreeNode<int> *rightAns = LCA(root->right,node1,node2);
    if(leftAns!=NULL && rightAns==NULL){
        return leftAns;
    }
    else if (leftAns == NULL && rightAns != NULL){
        return rightAns;
    }
    else if (leftAns != NULL && rightAns != NULL){
        return root;
    }else{//both are NULL
        return NULL;
    }
}
//LCA of BST
BinaryTreeNode<int>* LCAofBST(BinaryTreeNode<int>* root,BinaryTreeNode<int>* node1,BinaryTreeNode<int>* node2){
    if(root==NULL){
        return NULL;
    }
    if (node1->data == root->data || node2->data == root->data)
    {
        return root;
    }
    BinaryTreeNode<int> *leftAns =NULL;
    BinaryTreeNode<int> *rightAns =NULL;
    if (node1->data > root->data && node2->data>root->data){
        rightAns = LCAofBST(root->right, node1, node2);
    }else if(node1->data <root->data && node2->data<root->data){
        leftAns = LCAofBST(root->left, node1, node2);
    }
    else
    { // node1->data<root->data && node2->data>root->data
      // node1->data>root->data && node2->data<root->data
        leftAns = LCAofBST(root->left, node1, node2);
        rightAns = LCAofBST(root->right, node1, node2);
    }
    if (leftAns != NULL && rightAns == NULL)
    {
        return leftAns;
    }
    else if (leftAns == NULL && rightAns != NULL)
    {
        return rightAns;
    }
    else if (leftAns != NULL && rightAns != NULL)
    {
        return root;
    }
    else
    { // both are NULL
        return NULL;
    }
}

int main()
{
    //  1 2 3 4 5 6 7 -1 -1 -1 -1 10 15 -1 -1 -1 -1 -1 -1
    BinaryTreeNode<int>* root=takeInputLevelWise();
    // createInsertDuplicateNode(root);

    levelorderTraversal(root);
    cout<<endl;
    pairSum(root,15);
}