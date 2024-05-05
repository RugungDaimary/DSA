#include<bits/stdc++.h>
#include<queue>
using namespace std;
template<typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode* left; 
    BinaryTreeNode* right;

    BinaryTreeNode(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }

    ~BinaryTreeNode(){//destructor call
        delete left;
        delete right;
    }

};

void printTree(BinaryTreeNode<int>* root){
    if (root==NULL)
    {
        return;
    }
    cout<<root->data<<": ";
    if (root->left!=NULL)
    {
        cout<<"L"<<root->left->data<<",";
    }
    if (root->right!=NULL)
    {
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    
    printTree(root->left);
    printTree(root->right);
    
}

BinaryTreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter Root Data\n";
    cin>>rootData;
    if (rootData==-1)
    {
        return NULL;
    }
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* leftChild=takeInput();
    BinaryTreeNode<int>* rightChild=takeInput();
    root->left=leftChild;
    root->right=rightChild;
    return root;
}

BinaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter root Data\n";
    cin>>rootData;
    if (rootData==-1)
    {
        return NULL;
    }
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() !=0)
    {
        BinaryTreeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter left child of "<<front->data<<endl;
        int leftChildData;
        cin>>leftChildData;
        if (leftChildData!=-1)
        {
            BinaryTreeNode<int>* child=new BinaryTreeNode<int>(leftChildData);
            front->left=child;
            pendingNodes.push(child);
        }
        cout<<"Enter right child of "<<front->data<<endl;
        int rightChildData;
        cin>>rightChildData;
        if (rightChildData!=-1)
        {
            BinaryTreeNode<int>* child=new BinaryTreeNode<int>(rightChildData);
            front->right=child;
            pendingNodes.push(child);
        }
        
    }
    return root;
    
}
void printTree_levelWise(BinaryTreeNode<int>*root){
    if(root==NULL){
        return;
    }
    queue<BinaryTreeNode<int>*>pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        BinaryTreeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<":";
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
        cout<<endl;
    }
}
int countNodes(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    int leftNodes=0;
     if (root->left != NULL)
    {
        leftNodes=countNodes(root->left);
    }
    int rightNodes =0;
    if (root->right != NULL)
    {
        rightNodes=countNodes(root->right);
    }
    return 1+ leftNodes+rightNodes;
    //or
    // return 1+countNodes(root->left)+countNodes(root->right);
    
}
//is Node Present?
bool isPresent(BinaryTreeNode<int>* root,int x){
    if(root==NULL){
        return false;
    }
    if(root->data==x){
        return true;
    }
    if(isPresent(root->left,x)){
        return true;
    }
    if(isPresent(root->right,x)){
        return true;
    }
    return false;
}
//Finding Height of Binary Tree
int getHeight(BinaryTreeNode<int>* root){
    if (root==NULL)
    {
        return 0;
    }  
    int leftHeight=getHeight(root->left);
    int rightHeight=getHeight(root->right);
    return 1+max(leftHeight,rightHeight);   
}
// Mirror Binary tree
void MirrorBinaryTree(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    if(root->left!=NULL){
        BinaryTreeNode<int>* temp=root->left;
        root->left = root->right;
        root->right = temp;
        
    }
    MirrorBinaryTree(root->left);
    MirrorBinaryTree(root->right);
}
//Inorder Traversal
void inorderPrint(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    inorderPrint(root->left);
    cout << root->data<<" ";
    inorderPrint(root->right);
}

//Preoreder Traversal
void preorderPrint(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

// Postorder Traversal
void postorderPrint(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    postorderPrint(root->left);
    postorderPrint(root->right);
    cout << root->data << " ";
}


//Construct Binary Tree from inorder and preorder array
/*
int rootIndexIn(vector<int> &inorder, int rootData)
{
    for (int i = 0; i < inorder.size(); i++)
    {
        if (inorder[i] == rootData)
        {
            return i;
        }
    }
    return -1;
}

BinaryTreeNode<int> *Helper(vector<int> &preorder, vector<int> &inorder, int inS, int inE, int preS, int preE)
{
    if (inS > inE)
    {
        return NULL;
    }
    int rootData = preorder[preS];
    int rootIndex = rootIndexIn(inorder, rootData);

    int leftInS = inS;
    int leftInE = rootIndex - 1;
    int rightInS = rootIndex + 1;
    int rightInE = inE;

    int leftPreS = preS + 1;
    int leftPreE = leftInE - leftInS + leftPreS;
    int rightPreS = leftPreE + 1;
    int rightPreE = preE;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    root->left = Helper(preorder, inorder, leftInS, leftInE, leftPreS, leftPreE);
    root->right = Helper(preorder, inorder, rightInS, rightInE, rightPreS, rightPreE);
    return root;
}

BinaryTreeNode<int> *constructTree(vector<int> &preorder, vector<int> &inorder)
{
    int n = preorder.size();
    return Helper(preorder, inorder, 0, n - 1, 0, n - 1);
}
*/

// Construct Binary Tree from inorder and postorder array
int rootIndexIn(vector<int> &inorder, int rootData)
{
    for (int i = 0; i < inorder.size(); i++)
    {
        if (inorder[i] == rootData)
        {
            return i;
        }
    }
    return -1;
}
BinaryTreeNode<int>* bulidTreeHelper(vector<int>&postorder,vector<int>&inorder,int postS,int postE,int inS,int inE){
    if (inS > inE)
    {
        return NULL;
    }
    int rootData = postorder[postE];
    int rootIndex = rootIndexIn(inorder, rootData);

    int leftInS = inS;
    int leftInE = rootIndex - 1;
    int rightInS = rootIndex + 1;
    int rightInE = inE;

    int leftPostS = postS;
    int leftPostE = postS+(rootIndex-inS)-1;
    int rightPostS = leftPostE + 1;
    int rightPostE = postE-1;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    root->left = bulidTreeHelper(postorder, inorder, leftPostS, leftPostE, leftInS, leftInE);
    root->right = bulidTreeHelper(postorder, inorder, rightPostS, rightPostE, rightInS, rightInE);
    return root;
}
BinaryTreeNode<int>* bulidTree(vector<int>&postorder,vector<int>& inorder){
    int n=postorder.size();
    return bulidTreeHelper(postorder,inorder,0,n-1,0,n-1);

}


// diameter of binary Tree
int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}
int diameter(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);
    return max(option1, max(option2, option3));
}
// better approach for diameter
//  class PAIR{
//      public:
//      int height;
//      int diameter;
//  };
//  PAIR Diameter(BinaryTreeNode<int>* root){
//  }
// using inbuilt pair class
pair<int, int> heightDiameter(BinaryTreeNode<int> *root)
{
    pair<int, int> p; // first=height and second=diameter
    if (root == NULL)
    {
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);
    int leftHei = leftAns.first;
    int leftDia = leftAns.second;
    int rightHei = rightAns.first;
    int rightDia = rightAns.second;

    int height = 1 + max(leftHei, rightHei);
    int diameter = max(leftHei + rightHei, max(leftDia, rightDia));
    p.first = height;
    p.second = diameter;
    return p;
}



// Minimum and Maximum in the Binary Tree
pair<int, int> MinMax(BinaryTreeNode<int> *root)
{

    pair<int, int> ans; // first=min  second=max
    if (root == NULL)
    {
        ans.first = INT_MAX;
        ans.second = INT_MIN;
        return ans;
    }
    int x = root->data;
    pair<int, int> leftData = MinMax(root->left);
    pair<int, int> rightData = MinMax(root->right);
    int minimum = min(root->data, min(leftData.first, rightData.first));
    int maximum = max(root->data, max(leftData.second, rightData.second));
    ans.first = minimum;
    ans.second = maximum;
    return ans;
}
int main(){

    //input: 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    
    
    /*
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* node1=new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* node2=new BinaryTreeNode<int>(3);
    root->left=node1;
    root->right=node2;
    */

   
   
    // BinaryTreeNode<int>* root=takeInput();
    // BinaryTreeNode<int>* root=takeInputLevelWise();
    // printTree_levelWise(root);




    // cout<<"Number of Nodes "<<countNodes(root)<<endl;



    // int x;
    // cout<<"Enter x\n";
    // cin>>x;
    // if (isPresent(root,x))
    // {
    //     cout<<"Present\n";
    // }else{
    //     cout<<"Not Present\n";
    // }



    // cout<<"Height of Tree is "<<getHeight(root)<<endl;



    // MirrorBinaryTree(root);
    // printTree_levelWise(root);



    // inorderPrint(root);



    // preorderPrint(root);
    
    /*
    vector<int>preorder;
    //1,2,4,5,3,6,7
    cout<<"Enter Prorder data\n";
    preorder.push_back(1);
    preorder.push_back(2);
    preorder.push_back(4);
    preorder.push_back(5);
    preorder.push_back(3);
    preorder.push_back(6);
    preorder.push_back(7);
    vector<int>inorder;
    //4,2,5,1,6,3,7
    cout<<"Enter Inorder data\n";
    inorder.push_back(4);
    inorder.push_back(2);
    inorder.push_back(5);
    inorder.push_back(1);
    inorder.push_back(6);
    inorder.push_back(3);
    inorder.push_back(7);

    BinaryTreeNode<int>* root=constructTree(preorder,inorder);
    printTree_levelWise(root);
    */




    vector<int>postorder;
    //4,5,2,6,7,3,1
    cout<<"Enter Postorder data\n";
    preorder.push_back(4);
    preorder.push_back(5);
    preorder.push_back(2);
    preorder.push_back(6);
    preorder.push_back(7);
    preorder.push_back(3);
    preorder.push_back(1);
    vector<int>inorder;
    //4,2,5,1,6,3,7
    cout<<"Enter Inorder data\n";
    inorder.push_back(4);
    inorder.push_back(2);
    inorder.push_back(5);
    inorder.push_back(1);
    inorder.push_back(6);
    inorder.push_back(3);
    inorder.push_back(7);

    BinaryTreeNode<int>* root=bulidTree(postorder,inorder);
    printTree_levelWise(root);




    delete root;

    // pair<int,int>p=heightDiameter(root);
    // cout<<"Height "<<p.first<<endl;
    // cout<<"Diameter "<<p.second<<endl;

    // pair<int,int> ans=MinMax(root);
    // cout<<"Minimum "<<ans.first<<endl;
    // cout<<"Maximum "<<ans.second<<endl;

    return 0;
}


