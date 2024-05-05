// #include <iostream>
// #include<vector>
// #include<queue>
// using namespace std;
// template<typename T>
// class TreeNode{
//     public:
//     T data;
//     vector<TreeNode<T> *> children;
//     TreeNode(T data){
//         this->data=data;

//     }
// };
// //simple tree print
// // void printTree(TreeNode<int>* root){
// //     if(root==NULL){//edge case(if send NULL tree) not the base case
// //         return;
// //     }
// //     //here by default in generic tree base case not required
// //     cout<<root->data<<":";
// //     for(int i=0;i<root->children.size();i++){
// //         cout<<root->children[i]->data<<",";
// //     }
// //     cout<<endl;
// //     for (int i = 0; i < root->children.size(); i++)
// //     {
// //         printTree(root->children[i]);
// //     }
// // }
// void printTree_Better(TreeNode<int>* root){
//     if(root==NULL){
//         return;
//     }
//     queue<TreeNode<int>* >pendingNodes;
//     pendingNodes.push(root);
//     while(pendingNodes.size()!=0){
//         TreeNode<int>* front=pendingNodes.front();
//         pendingNodes.pop();
//         cout<<front->data<<":";
//         for(int i=0;i<front->children.size();i++){
//             cout << front->children[i]->data<<",";
//             pendingNodes.push(front->children[i]);
//         }
//         cout<<endl;
//     }
    
// }
// // TreeNode<int> *takeInput()
// // {
// //     int rootData;
// //     cout << "Enter root Data\n";
// //     cin >> rootData;
// //     TreeNode<int> *root = new TreeNode<int>(rootData);

// //     int n;
// //     cout << "Enter the num of child of " << rootData << ": ";
// //     cin >> n;
// //     for (int i = 0; i < n; i++)
// //     {
// //         TreeNode<int> *child = takeInput();
// //         root->children.push_back(child);
// //     }

// //     return root;
// // }
// TreeNode<int> *takeInput_Better()
// {
//     int rootData;
//     cout << "Enter root Data\n";
//     cin >> rootData;
//     TreeNode<int> *root = new TreeNode<int>(rootData);
//     queue<TreeNode<int> *> pendingNodes;
//     pendingNodes.push(root);
//     while (pendingNodes.size() != 0)
//     {
//         TreeNode<int> *front = pendingNodes.front();
//         pendingNodes.pop();
//         cout << "Enter num of children of " << front->data << endl;
//         int numChild;
//         cin >> numChild;
//         for (int i = 0; i < numChild; i++)
//         {
//             int childData;
//             cout << "Enter " << i << "th Child of " << front->data << endl;
//             cin >> childData;
//             TreeNode<int>* child=new TreeNode<int> (childData);
//             front->children.push_back(child);
//             pendingNodes.push(child);
//         }
//         cout<<endl;
//     }
//     return root; 
// }

// int main(){
//     // TreeNode<int>* root=new TreeNode<int>(1);
//     // TreeNode<int>* node1=new TreeNode<int>(2);
//     // TreeNode<int>* node2=new TreeNode<int>(3);
//     // TreeNode<int>* node3=new TreeNode<int>(4);
//     // TreeNode<int>* node4=new TreeNode<int>(5);
//     // TreeNode<int>* node5=new TreeNode<int>(6);
//     // root->children.push_back(node1);
//     // root->children.push_back(node2);
//     // node1->children.push_back(node3);
//     // node2->children.push_back(node4);
//     // node3->children.push_back(node5);
//     TreeNode<int> *root = takeInput_Better();
//     printTree_Better(root);

//     return 0;
// }










#include<iostream>
#include<vector>
#include<queue>
using namespace std;
template<typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode*> children;
    TreeNode(T data){
        this->data=data;
    }
    ~TreeNode(){
        for (int i = 0; i < root->children.size(); i++)
        {
            delete(root->children[i]);
        }
    }

};
//TAKING INPUT
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
            TreeNode<int>* child=new TreeNode<int> (childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
        cout<<endl;
    }
    return root;
}
//PRINTING TREE
void printTree_Better(TreeNode<int>* root){
    if(root==NULL){
        return;
    }
    queue<TreeNode<int>* >pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        TreeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<":";
        for(int i=0;i<front->children.size();i++){
            cout << front->children[i]->data<<",";
            pendingNodes.push(front->children[i]);
        }
        cout<<endl;
    }

}

// COUNTING NODES
int numNodes(TreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
  
    int ans=1;
    for (int  i = 0; i < root->children.size(); i++)
    {
        ans+=numNodes(root->children[i]);
    }
    return ans;
    
}
// SUM OF NODES
int sumNodes(TreeNode<int>* root){
    int sum=0;
    if(root==NULL){
        return 0;
    }
    else{
        sum+=root->data;
        for (int i = 0; i < root->children.size(); i++)
        {
            TreeNode<int> *temp = root->children[i];
            int x=sumNodes(temp);
            sum+=x;
        }
        return sum;
    }
}

//Node with largest data 
#include<climits>
int largestData(TreeNode<int>* root){
    if(root==NULL){
        return INT_MIN;
    }
    int largest=root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int>* temp=root->children[i];
        int smallProblem=largestData(temp);
        if(smallProblem>largest){
            largest=smallProblem;
        }
    }
    return largest;
}


//Height of Generic Tree
int height(TreeNode<int> *root)
{
    if (root->children.size() == 0)
    {
        return 1; // Leaf node has a height of 1
    }

    int maxHeight = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *temp = root->children[i];
        int childHeight = height(temp);
        maxHeight = max(maxHeight, childHeight);
    }

    return maxHeight + 1; // Add 1 to account for the current node
}

//Depth of Node(print Node data at depth K)
void printAtLevel_K(TreeNode<int>*root,int k){
    if(root==NULL){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
        return;

    }else{
        for(int i=0;i<root->children.size();i++){
            printAtLevel_K(root->children[i],k-1);
        }
    }
}

//Count leaf Nodes
int numLeafNodes(TreeNode<int>* root){
    int num=0;
    if(root==NULL){
        return 0;
    }
    if(root->children.size()==0){
        return 1;
    }
    for(int i=0;i<root->children.size();i++){
        int small=numLeafNodes(root->children[i]);
        num+=small;
    }
    return num;
}

//Pre-Order Tree Traversal
void preorder(TreeNode<int>* root){
    // for input: 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
    //output:1 2 5 6 3 7 8 9 4
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++){
        preorder(root->children[i]);
    }
}
//Post-Order Traversal
void postorder(TreeNode<int>* root){
    // for input: 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
    // output:5 6 2 7 9 8 3 4 1
    if(root==NULL){
        return;
    }
    for(int i=0;i<root->children.size();i++){
        postorder(root->children[i]);
    }
    cout<<root->data<<" ";
}

//Deleting Tree
void deleteTree(TreeNode<int>*root){
    //If we delete root first,we won't be able to delete all childrens
    //so we have to follow like postorder traversal 
    for (int i = 0; i < root->children.size(); i++)
    {
        deleteTree(root->children[i]);
    }
    delete root;
}

int main()
{   //Tree input:  1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
    TreeNode<int> *root = takeInput_Better();
    printTree_Better(root);
    cout<<"Number of Nodes "<<numNodes(root)<<endl;
    cout<<endl;
    cout<<"Sum of Nodes "<<sumNodes(root)<<endl;
    cout<<endl;
    cout<<"Largest Data "<<largestData(root)<<endl;

    cout<<endl;

    cout<<"Height of Tree "<<height(root)<<endl;
    cout<<endl;
    cout<<"At level K : ";
    printAtLevel_K(root,2);

    cout<<endl;
    cout<<"No of Leaf Nodes : "<<numLeafNodes(root)<<endl;
    cout<<endl;
    postorder(root);
    cout<<endl;



    
   // deleteTree(root);//one way of deleting tree
    delete root;// Destructor call
    return 0;
}