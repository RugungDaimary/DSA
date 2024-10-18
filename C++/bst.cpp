#include <iostream>
#include <queue>
#include<limits.h>
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
TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root Data\n";
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> q;
    q.push(root);
    while (q.size() != 0)
    {
        TreeNode<int> *front = q.front();
        q.pop();
        cout << "Enter left child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            TreeNode<int> *child = new TreeNode<int>(leftChildData);
            front->left = child;
            q.push(child);
        }
        cout << "Enter right child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            TreeNode<int> *child = new TreeNode<int>(rightChildData);
            front->right = child;
            q.push(child);
        }
    }
    return root;
}

void printTree(TreeNode<int> *root)
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
pair<TreeNode *, bool> search_helper(TreeNode *node, int data)
{
    if (node == NULL)
    {
        return {NULL, false};
    }
    if (node->data == data)
    {
        return {node, true};
    }
    else if (data < node->data)
    {
        return search_helper(node->left, data);
    }
    else
    {
        return search_helper(node->right, data);
    }
}
bool search(TreeNode *root, int data)
{
    pair<TreeNode *, bool> ans = search_helper(root, data);
    if (ans.second)
        return true;
    return false;
}

// Print Element in range
void printRange(TreeNode<int> *root, int k1, int k2)
{   //k1=min,k2=max
    if (root == NULL)
    {
        return;
    }
    if (root->data > k1) // if the root's data is greater than the minimum value
    { //(root->data>MAX) not like that as thought of
        printRange(root->left, k1, k2); // go to the left subtree
    }
    if (root->data >= k1 && root->data <= k2) // if the root's data is within the range
    {
        cout << root->data << " ";
    }
    if (root->data < k2) // if the root's data is less than the maximum value
    {  //(root->data<MIN) not as thought of
        printRange(root->right, k1, k2); // go to the right subtree
    }
}
void printRangeBetween(TreeNode<int> *root, int k1, int k2)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data >= k1 && root->data <= k2) // if the root's data is within the range
    {
        cout << root->data << " ";
    }
    if (root->data > k1) // if the root's data is greater than the minimum value
    { //(root->data>MAX) not like that as thought of
        printRangeBetween(root->left, k1, k2); // go to the left subtree
    }
    

    if (root->data <= k2) // if the root's data is less than the maximum value
    {  //(root->data<MIN) not as thought of
        printRangeBetween(root->right, k1, k2); // go to the right subtree
    }
}


//check BST or not
//here time complexity is O(n*h);
int findMaximum(TreeNode *node)
{
    if (node == NULL)
        return INT_MIN;
    while (node->right != NULL)
    {
        node = node->right;
    }
    return node->val;
}

int findMinimum(TreeNode *node)
{
    if (node == NULL)
        return INT_MAX;
    while (node->left != NULL)
    {
        node = node->left;
    }
    return node->val;
}

bool isValidBST(TreeNode *root)
{
    if (root == NULL)
        return true;
    if (root->left != NULL && findMaximum(root->left) >= root->val)
        return false;
    if (root->right != NULL && findMinimum(root->right) <= root->val)
        return false;
    return isValidBST(root->left) && isValidBST(root->right);
}

// another approach using class (O(n)time)
class isBSTReturn {
public:
    int minimum;
    int maximum;
    bool isBST;
};

isBSTReturn isBST(TreeNode<int>* root) {
    isBSTReturn ans;
    if (root == NULL) {
        ans.isBST = true;
        ans.maximum = INT_MIN;
        ans.minimum = INT_MAX;
        return ans;
    }
    isBSTReturn leftAns = isBST(root->left);
    isBSTReturn rightAns = isBST(root->right);

    bool isBSTFinal = (root->data > leftAns.maximum) && (root->data < rightAns.minimum) && leftAns.isBST && rightAns.isBST;
    int Min = min(root->data, min(leftAns.minimum, rightAns.minimum));
    int Max = max(root->data, max(leftAns.maximum, rightAns.maximum));
    ans.maximum = Max;
    ans.minimum = Min;
    ans.isBST = isBSTFinal;
    return ans;
}

//Construct BST form sorted array

TreeNode *HELPER(vector<int> &nums, int s, int e)
{

    int mid = s + (e - s) / 2;
    if (s > e)
    {
        return NULL;
    }
    TreeNode *root = new TreeNode(nums[mid]);
    TreeNode *leftTree = HELPER(nums, s, mid - 1);
    TreeNode *rightTree = HELPER(nums, mid + 1, e);
    root->left = leftTree;
    root->right = rightTree;
    return root;
}

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    int n = nums.size();
    return HELPER(nums, 0, n - 1);
}


//BST to sorted LL
template <typename T>
class Node
{
public:
    Node *next;
    T data;
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};
// Node<int>* BSTtoLL(TreeNode<int>* root){
//     if(root==NULL){
//         return NULL;
//     }
//     Node<int>* temp= new Node<int>(root->data);
//     Node<int> *leftHead=NULL;
//     Node<int> *rightHead=NULL;
//     if (root->left != NULL)
//     {
//         leftHead=BSTtoLL(root->left);
//     }
//     if(root->right!=NULL){
//         rightHead=BSTtoLL(root->right);
//     }
//     temp->next = rightHead;
//     if(leftHead!=NULL){//agar leftHead NULL hai to traverse karne ki jarurat nhi hai
//         Node<int> *current = leftHead;
//         while (current->next!=NULL)
//         {
//             current = current->next;
//         }
//         current->next = temp;
//         return leftHead;
//     }else{
//         return temp;

//     }    
// }

//another approach
pair<Node<int>*, Node<int>*> BSTtoLL(TreeNode<int> *root){
    //first=head;
    // second=tail;
    pair<Node<int>*,Node<int>*> Output;
    if (root==NULL)
    {   Output.first=NULL;
        Output.second=NULL;
        return Output;
    }
    pair<Node<int> *, Node<int> *> leftAns = BSTtoLL(root->left);
    pair<Node<int> *, Node<int> *> rightAns = BSTtoLL(root->right);
    Node<int>* current=new Node<int>(root->data);
    if (leftAns.second != NULL)
    {
        leftAns.second->next = current;
    }
    current->next = rightAns.first;

    if (leftAns.first != NULL)
    {
        Output.first = leftAns.first;
    }
    else
    {
        Output.first = current;
    }

    if (rightAns.second != NULL)
    {
        Output.second = rightAns.second;
    }
    else
    {
        Output.second = current;
    }

    return Output;
}

// Find path in BinaryTree
vector<int>* getRootToNodePath(TreeNode<int>* root,int k){
    
    if(root==NULL){
        return NULL;
    }
    if(root->data==k){
        vector<int>* output=new vector<int>();
        output->push_back(root->data);
        return output;
    }
    vector<int> *leftOutput = getRootToNodePath(root->left,k);
    if(leftOutput!=NULL){
        leftOutput->push_back(root->data);
        return leftOutput;
    }
    vector<int> *rightOutput = getRootToNodePath(root->right,k);
    if(rightOutput!=NULL){
        rightOutput->push_back(root->data);
        return rightOutput;
    }else{//Not found anywhere
        return NULL;
    }
}

// 1 2 3 -1 -1 4 7 5 6 -1 -1 -1 -1 -1 -1
// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
// 40 20 60 10 30 50 70 -1 -1 -1 -1 -1 -1 -1 -1    isbst
//1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1

int main()
{

    TreeNode<int> *root = takeInputLevelWise();
    printTree(root);
   
    // if(isPresent(root,6)){
    //     cout<<"Present\n";
    // }else{
    //     cout<<"Not Present\n";
    // }
    cout<<endl;
    // printRangeBetween(root,0,11);

    // cout<<isBST(root)<<endl;
    
    // delete root;


    vector<int>* output=getRootToNodePath(root,10);
    for (int  i = 0; i < output->size(); i++)
    {
        
        cout << output->at(i) << " ";
    }
    delete output;
    

    return 0;
}



