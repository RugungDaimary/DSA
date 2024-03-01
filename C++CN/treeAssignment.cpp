#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode *> children;
    TreeNode(T data)
    {
        this->data = data;
    }
    // ~TreeNode()
    // {
    //     for (int i = 0; i < root->children.size(); i++)
    //     {
    //         delete (root->children[i]);
    //     }
    // }
};

class Pair{
    public:
    TreeNode<int>* N;//Node of child with max sum
    int Sum;//sum of x's data and it's childs's data 

};
class Pair1
{
public:
    TreeNode<int> *Maximum;
    TreeNode<int> *secondMaximum;
};
// TAKING INPUT
TreeNode<int> *takeInput_Better()
{
    int rootData;
    cout << "Enter root Data\n";
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter num of children of " << front->data << endl;
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter " << i << "th Child of " << front->data << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
        cout << endl;
    }
    return root;
}
// PRINTING TREE
void printTree_Better(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << ",";
            pendingNodes.push(front->children[i]);
        }
        cout << endl;
    }
}

//check if an element is present or not
bool isPresent(TreeNode<int>* root,int x){
    if(root==NULL){
        return false;
    }
    if(root->data==x){
        return true;
    }
    for(int i=0;i<root->children.size();i++){
        // if (isPresent(root->children[i], x))
        // {
        //     return true;
        // }
        //or
        return isPresent(root->children[i],x);
    }
    return false;
    

}
//count nodes greater than X
int numNodesGreater(TreeNode<int>* root,int x){
    int count=0;
    if (root == NULL)
    {
        return 0;
    }
    
    for(int i=0;i<root->children.size();i++){
        count+=numNodesGreater(root->children[i],x);

    }
    if (root->data > x)
    {
        count++;
        return count;
    }
    return count;
}
// Node with maximum child sum
// int NodeSum(TreeNode<int>*root){
//     if(root==NULL){
//         return 0;
//     }
//     int sum = root->data; 
//     for (int i = 0; i < root->children.size(); i++)
//     {
//         sum += root->children[i]->data;
//     }
//     return sum;
// }
// TreeNode<int> *maxChildSumNode(TreeNode<int>* root){
//     TreeNode<int>* ans=root;
//     int sum=NodeSum(root);
//     for (int i = 0; i < root->children.size(); i++)
//     {
//         TreeNode<int> *child = maxChildSumNode(root->children[i]);
//         int xSum = NodeSum(child);
//         if(xSum>sum){
//             sum=xSum;
//             ans=child;
//         }        
//     } 
//     return ans;    
// }

//Another approach using class pair
Pair maxChildSumNode(TreeNode<int>*root){
    Pair ans;
    ans.N=root;
    ans.Sum=root->data;
    for(int i=0;i<root->children.size();i++){
        ans.Sum+=root->children[i]->data;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        Pair temp=maxChildSumNode(root->children[i]);
        if(temp.Sum>ans.Sum){
            ans.N=temp.N;
            ans.Sum=temp.Sum;
        }    
    }
    return ans;
}

//Structurally identical 
bool isIdentical(TreeNode<int>*root1,TreeNode<int>*root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    if(root1==NULL || root2==NULL)
    { // If one is NULL and the other is not, return false
        return false;//if both null reflected to above condition
    }

    if(root1->data!=root2->data){
        return false;
    }
    if(root1->children.size()!=root2->children.size()){
        return false;
    }
    //here children size is same
    for(int i=0;i<root1->children.size();i++){
        if(!isIdentical(root1->children[i], root2->children[i])){
            return false;
        }
        
    }
    // If all checks passed, the trees are identical
    return true;
}

// Next larger
TreeNode<int>* NextLarger(TreeNode<int>* root,int x){
    if (root == NULL){
        return NULL;
    }
        
    TreeNode<int>* largerNode=NULL;
    int ans=INT_MAX;
    if(root->data>x){
        largerNode=root;
        ans=root->data;   
    }
    for(int i=0;i<root->children.size();i++){
        TreeNode<int>* temp=NextLarger(root->children[i],x);
        if (temp != NULL && temp->data < ans && temp->data > x)
        {
            largerNode = temp;
            ans = temp->data;
        }  
    }
    return largerNode;
}

//other approach 
// TreeNode<int>* NextLarger(TreeNode<int>* root,int x){
//     if (root == NULL){
//         return NULL;
//     }
        
//     TreeNode<int>* largerNode=NULL;
    
//     if(root->data>x){
//         largerNode=root;
        
//     for(int i=0;i<root->children.size();i++){
//         TreeNode<int>* temp=NextLarger(root->children[i],x);
//         if (temp != NULL)
//         if(largerNode==NULL || temp->data<largerNode->data){
//             largerNode = temp;
//         }  
//     }
//     return largerNode;
// }



//Second Largest Element In Tree
Pair1 SecordLargestNode(TreeNode<int> *root)
{
    Pair1 ans;
    ans.Maximum = root;
    ans.secondMaximum = NULL;
    for (int i = 0; i < root->children.size(); i++)
    {
        Pair1 temp = SecordLargestNode(root->children[i]);
        if (ans.Maximum->data > temp.Maximum->data)
        {
            if (ans.secondMaximum == NULL || temp.Maximum->data > ans.secondMaximum->data)
            {
                ans.secondMaximum = temp.Maximum;
            }
        }
        else
        { // temp.maximum->data > ans.maximum->data
            TreeNode<int> *x = ans.Maximum;
            ans.Maximum = temp.Maximum;
            if (temp.secondMaximum == NULL || x->data > temp.secondMaximum->data)
            {
                ans.secondMaximum = x;
            }
            else
            {
                ans.secondMaximum = temp.secondMaximum;
            }
        }
    }
    return ans;
}

// Replace with depth
void helper(TreeNode<int>* root,int depth){
    if(root==NULL){
        return;
    }
    //replace root data with 0 and its childs's data with 1
    root->data=depth;
    for (int i = 0; i < root->children.size(); i++)
    {
        helper(root->children[i],depth+1);//as for recursion it's depth is depth+1
    }
}
void replaceWithDepth(TreeNode<int>* root){
    int depth=0;
    helper(root,depth);
    
}
int main()
{
    // Tree input:  1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
    /*
    TreeNode<int>* root=takeInput_Better();
    printTree_Better(root);
    int x;
    cout<<"Enter the element \n";
    cin>>x;
    if(isPresent(root,x)){
        cout<<"Present\n";
    }else{
        cout<<"Not Present\n";
    }
    cout<<"Number of Elements greater than "<<x<<" is "<<numNodesGreater(root,x)<<endl;

    cout<<endl;
    cout << maxChildSumNode(root)->data<<endl;
    */

   /*
    TreeNode<int> *root1 = takeInput_Better();
    TreeNode<int> *root2 = takeInput_Better();


    if (isIdentical(root1, root2)){
        cout<<"Identical\n";
    }else{
        cout<<"Not Identical\n";
    }
    */
    TreeNode<int> *root = takeInput_Better();
    // cout << "Next Larger Element is " << NextLarger(root,21)->data<<endl;



    // replaceWithDepth(root);
    // printTree_Better(root);

    // Pair ans=maxChildSumNode(root);
    // cout<<"The Node with max child sum is "<<ans.N->data<<endl;



    return 0;
}