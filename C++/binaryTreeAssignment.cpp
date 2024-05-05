#include <bits/stdc++.h>
#include <queue>
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
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    { // destructor call
        delete left;
        delete right;
    }
};

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
//sum of nodes
int nodeSum(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    int sum=root->data;
    if(root->left!=NULL){
        sum += nodeSum( root->left);
    }
    if(root->right!=NULL){
        sum += nodeSum( root->right);
    }
    return sum;
}

// chack Balanced binary tree
// int height(BinaryTreeNode<int>* root){
//     if(root==NULL){
//         return 0;
//     }
//     return 1+ max(height(root->left),height(root->right));
// }

// bool isBalanced(BinaryTreeNode<int>* root){
//     if(root==NULL){
//         return true;
//     }
//     int leftHeight=height(root->left);
//     int rightHeight=height(root->right);
//     if(abs(leftHeight-rightHeight)<=1){
//         bool a = isBalanced(root->left);
//         bool b = isBalanced(root->right);
//         if (a && b)
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }
//     return false; 
// }

//better approach using pair class
pair<bool,int> isBalancedTree(BinaryTreeNode<int>* root){
    //here first=isBalanced, second=height
    pair<bool,int> ans;
    if(root==NULL){
        ans.first=true;
        ans.second=0;
        return ans;
    }
    pair<bool,int> leftAns=isBalancedTree(root->left);
    pair<bool,int> rightAns=isBalancedTree(root->right);
    if ((abs(leftAns.second - rightAns.second) <= 1)&&(leftAns.first && rightAns.first)) // both are true,
    { 
        ans.first=true;
    }
    else
    {
        ans.first=false;
    }
    ans.second = 1 + max(leftAns.second, rightAns.second);
    return ans;

 
}
bool isBalancedHelper(BinaryTreeNode<int>* root){
    pair<bool,int> ans=isBalancedTree( root);
    return ans.first;
}

// Level order traversal(level by level)
void levelorderTraversal(BinaryTreeNode<int>* root){
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(nullptr);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();
        if(front!=NULL){
            cout << front->data << " ";
            if (front->left != NULL)
            {
                pendingNodes.push(front->left);
            }
            if (front->right != NULL)
            {
                pendingNodes.push(front->right);
            }
        }else{//front==NULL
            cout<<endl;
            if (!pendingNodes.empty())
            {
                pendingNodes.push(nullptr);
            }else{
                break;
            }
        }  
    }
}


//remove leaf node
BinaryTreeNode<int>* removeLeafNode(BinaryTreeNode<int>* root){
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right!=NULL){
        BinaryTreeNode<int> *rightAns = removeLeafNode(root->right);
        root->right=rightAns;

    }
    if(root->left!=NULL && root->right==NULL){
        BinaryTreeNode<int> *leftAns = removeLeafNode(root->left);
        root->left=leftAns;
    }
    if (root->left != NULL && root->right != NULL)
    {
        BinaryTreeNode<int> *leftAns = removeLeafNode(root->left);
        BinaryTreeNode<int> *rightAns = removeLeafNode(root->right);
        root->left=leftAns;
        root->right=rightAns;
    }
    return root;
}


//level wise linkedlist
/*
template<typename T>
class Node{
    public:
    Node *next;
    T data;
    Node(T data){
        this->data=data;
        this->next=NULL;
    }
};
vector<BinaryTreeNode<int>*> levelwiseLinkedList(BinaryTreeNode<int>* root){
    vector<Node<int>*> outputHead;
    queue<BinaryTreeNode<int>*> pendingNode;
    if(root!=NULL){
        pendingNode.push(root);
        pendingNode.push(nullptr);
    }
    
    //for linked list creation
    Node<int>* head=NULL;
    Node<int>* tail=NULL;

    while (!pendingNode.empty())
    {
        BinaryTreeNode<int>* front=pendingNode.front();
        pendingNode.pop();
        if(front!=NULL){
            if(front->left!=NULL){
                pendingNode.push(front->left);
                
            }
            if(front->right!=NULL){
                pendingNode.push(front->right);
            }
            //new node creation
            Node<int> *newNode = new Node<int>(front->data);
            if(head==NULL){
                head=newNode;
                tail=newNode;
            }else{
                tail->next=newNode;
                tail=newNode;
            }
        }else{//front==NULL
            
            outputHead.push_back(head);
            //reset head and  tail with NULL for next level linked list
            head=NULL;
            tail=NULL;
            if(!pendingNode.empty()){
                pendingNode.push(nullptr);

            }else{
                break; 
            }
        }
        
    }
    return outputHead;
}

*/


//Zig Zag Tree print
void ZigZagPrint(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    stack<BinaryTreeNode<int>*> s1;
    stack<BinaryTreeNode<int>*> s2;
    s1.push(root);
    bool rightToLeft=true;
    while (!s1.empty()|| !s2.empty())

    {
        if(rightToLeft){
            while (!s1.empty())
            {
                BinaryTreeNode<int> *top = s1.top();
                s1.pop();
                cout << top->data << " ";
                if (top->left != NULL)
                {
                    s2.push(top->left);
                }
                if (top->right != NULL)
                {
                    s2.push(top->right);
                }
            }
        }else{
            while (!s2.empty())
            {
                BinaryTreeNode<int> *top = s2.top();
                s2.pop();
                cout << top->data << " ";
                if (top->right != NULL)
                {
                    s1.push(top->right);
                }
                if (top->left != NULL)
                {
                    s1.push(top->left);
                }
            }
        }
        cout << endl;
        rightToLeft = !rightToLeft;
    } 
    
}

int main(){
    // input: 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    // 1 2 3 4 5 -1 6 -1 -1 -1 -1 -1 7 -1 -1
    BinaryTreeNode<int>* root=takeInputLevelWise();
    // printTree_levelWise(root);
    levelorderTraversal(root);

    cout<<"Sum of Nodes "<<nodeSum(root)<<endl;

    // if(isBalanced(root)){
    //     cout<<"Balanced\n";
    // }else{
    //     cout<<"Not Balanced\n";
    // }

    // levelorderTraversal(root);


    // BinaryTreeNode<int> *removedLeafNode = removeLeafNode(root);
    // levelorderTraversal(removedLeafNode);

    ZigZagPrint(root);

   
    


    return 0;
}