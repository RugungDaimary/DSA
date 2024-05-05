//min priority Queue
/*
#include<iostream>
#include<vector>
using namespace std;
class PriorityQueue{
    vector<int> pq;
    public:
    PriorityQueue(){
        //by default size of pq is zero
    }
    bool isEmpty(){
        return pq.size()==0;
    }
    int getSize(){//returns the size of elements or no of elements present in Heap
        return pq.size();

    }
    int getMin(){
        if(isEmpty()){
            return 0; // PriorityQueue is empty
        }
        return pq[0];
    }
    void insert(int element){
        pq.push_back(element);
        int childIndex=pq.size()-1;

        while (childIndex>0)
        {
            int parentIndex=(childIndex-1)/2;
            if(pq[childIndex]<pq[parentIndex]){
                swap(pq[childIndex],pq[parentIndex]);
            }
            else{
                break;
            }
            childIndex=parentIndex;
        }
    }
    int remove(){
        if(isEmpty()){
            return 0;
        }
        int ans=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        //down headfify
        int parentIndex=0;
        int leftChildIndex=2*parentIndex+1;
        int rightChildIndex=2*parentIndex+2;
        while (leftChildIndex<pq.size())
        {
            int minIndex=parentIndex;//intialised with parenet index then compare with it's childs
            if(pq[leftChildIndex]<pq[minIndex]){
                minIndex=leftChildIndex;
            }
            if(pq[rightChildIndex]<pq[minIndex] && rightChildIndex<pq.size()){
                minIndex=rightChildIndex;
            }
            if(minIndex==parentIndex){//if no change in minIndex
                break;
            }
            swap(pq[minIndex],pq[parentIndex]);
            parentIndex=minIndex;
            leftChildIndex=2*parentIndex+1;
            rightChildIndex=2*parentIndex+2;

        }
        return ans;

    }



};
int main(){
    PriorityQueue p;
    p.insert(15);
    p.insert(1);
    p.insert(19);
    p.insert(24);
    p.insert(17);
    p.insert(68);
    p.insert(77);
    cout<<endl;
    cout<<p.getSize()<<endl;
    cout<<p.getMin()<<endl;
    while (!p.isEmpty())
    {
        cout<<p.remove()<<" ";
    }
    cout<<endl;


    return 0;
}
*/

/*
//MAX priority Queue
#include<iostream>
#include<queue>
using namespace std;
class PriorityQueue{
    int size;
    vector<int>p;
    public:
    PriorityQueue(){
        size=0;
    }
    int getSize(){
        return p.size();

    }
    bool isEmpty(){
        return p.size()==0;

    }
    int getMax(){
        if(isEmpty()){
            return 0;
        }
        return p[0];

    }
    void insert(int element){
        p.push_back(element);
        int childIndex=p.size()-1;
        while (childIndex>0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (p[childIndex] > p[parentIndex])
            {
                swap(p[childIndex], p[parentIndex]);
            }
            else
            {
                break; // found it's position
            }
            childIndex = parentIndex;
        }
    }

    int removeMax()
    {
        if (isEmpty())
        {
            return 0;
        }

        int ans = p[0];         // Store the maximum element to return later
        p[0] = p[p.size() - 1]; // Replace the root with the last element
        p.pop_back();           // Remove the last element from the heap

        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        while (leftChildIndex < p.size())
        {
            int maxIndex = parentIndex; // Initialize with the parent index, then compare with its children

            if (p[leftChildIndex] > p[maxIndex])
            {
                maxIndex = leftChildIndex;
            }

            if (rightChildIndex < p.size() && p[rightChildIndex] > p[maxIndex])
            {
                maxIndex = rightChildIndex;
            }

            if (maxIndex == parentIndex)
            {
                break; // If no change in maxIndex, the heap property is already satisfied
            }

            swap(p[maxIndex], p[parentIndex]);
            parentIndex = maxIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }

        return ans; // Return the maximum element that was removed
    }
};
int main(){
    PriorityQueue pq;
    pq.insert(15);
    pq.insert(1);
    pq.insert(19);
    pq.insert(24);
    pq.insert(17);
    pq.insert(68);
    pq.insert(77);
    cout << endl;
    cout << pq.getSize() << endl;
    cout << pq.getMax() << endl;
    while (!pq.isEmpty())
    {
        cout << pq.removeMax() << " ";
    }
    cout << endl;
}
*/

/*
//optimisation of Min heap(inplace heap sort)
//min heap (will print in decreasing order)
#include<iostream>
using namespace std;
void inplaceMinHeapSort(int *p, int n)
{
    // i is the starting point of unsorted array
    //for creation of heap
    for (int i = 1; i < n; i++)
    {
        int childIndex = i; 
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (p[childIndex] < p[parentIndex])
            {
                swap(p[childIndex], p[parentIndex]);
            }else{
                break;
            }
            
            childIndex = parentIndex;
            
        }
    }
    //for sorting heap in decreasing  order(removing elements)
    int size=n;
    while (size>1)
    {
        swap(p[0], p[size - 1]);
        size--;
        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        while (leftChildIndex < size)
        {
            int minIndex = parentIndex; 

            if (p[leftChildIndex] < p[minIndex])
            {
                minIndex = leftChildIndex;
            }

            if (rightChildIndex < size && p[rightChildIndex] < p[minIndex])
            {
                minIndex = rightChildIndex;
            }

            if (minIndex == parentIndex)
            {
                break; // If no change in maxIndex, the heap property is already satisfied
            }

            swap(p[minIndex], p[parentIndex]);
            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
    }
     
}
// for sorting in increasing order we have to use max heap
void inplaceMaxHeapSort(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int childIndex = i;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (a[childIndex] > a[parentIndex])
            {
                swap(a[childIndex], a[parentIndex]);
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }
    int size = n;
    while (size > 1)
    {
        swap(a[0], a[size - 1]);
        size--;
        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;
        while (leftChildIndex < size)
        {
            int maxIndex = parentIndex;
            if (a[leftChildIndex] > a[maxIndex])
            {
                maxIndex = leftChildIndex;
            }
            if (rightChildIndex < size && a[rightChildIndex] > a[maxIndex])
            {
                maxIndex = rightChildIndex;
            }
            if (maxIndex == parentIndex)
            {
                break;
            }
            swap(a[maxIndex], a[parentIndex]);
            parentIndex = maxIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
    }
}
int main(){
    int input[5]={5,1,2,0,8};
    inplaceMinHeapSort(input,5);
    for(int i=0;i<5;i++){
        cout<<input[i]<<" ";
    }
    cout<<endl;
    inplaceMaxHeapSort(input,5);
    for(int i=0;i<5;i++){
        cout<<input[i]<<" ";
    }

    return 0;
}

*/


//Inbuilt Priority Queue
//max priority queue
// #include<iostream>
// #include<queue>
// using namespace std;
// int main(){
//     priority_queue<int>p;//max priority quueue
//     p.push(9);
//     p.push(39);
//     p.push(7);
//     p.push(50);
//     p.push(56);
//     p.push(86);
//     p.push(30);
//     cout<<"Size -> "<<p.size()<<endl;
//     cout<<"Max element : "<<p.top()<<endl;
//     // while(!p.empty()){
//     //     cout<<p.top()<<" ";
//     //     p.pop();
//     // }
//     p.pop();
//     p.pop();
//     cout << "Size -> " << p.size() << endl;
//     cout << "Max element : " << p.top() << endl;
//     while (!p.empty())
//     {
//         cout << p.top() << " ";
//         p.pop();
//     }

//     return 0;
// }

//min priority queue
// #include<iostream>
// #include<queue>
// using namespace std;
// int main(){
//     priority_queue<int,vector<int>,greater<int> >p;//max priority quueue
//     p.push(9);
//     p.push(39);
//     p.push(7);
//     p.push(50);
//     p.push(56);
//     p.push(86);
//     p.push(30);
//     cout<<"Size -> "<<p.size()<<endl;
//     cout<<"Min element : "<<p.top()<<endl;
//     // while(!p.empty()){
//     //     cout<<p.top()<<" ";
//     //     p.pop();
//     // }
//     p.pop();
//     p.pop();
//     cout << "Size -> " << p.size() << endl;
//     cout << "Min element : " << p.top() << endl;
//     while (!p.empty())
//     {
//         cout << p.top() << " ";
//         p.pop();
//     }

//     return 0;
// }



//Qn)
// k-sorted array
#include<iostream>
#include<queue>
using namespace std;
//K sorted Array
void kSortedArray(int *a,int n ,int k){
    priority_queue<int> pq;//max heap
    for (int i = 0; i < k; i++)
    {
        pq.push(a[i]);
    }
    int j=0;
    for(int i=k;i<n;i++){
        a[j]=pq.top();
        pq.pop();
        pq.push(a[i]);
        j++;

    }
    while (!pq.empty())
    {
        a[j]=pq.top();
        pq.pop();
        j++;
    }
    
}


// k smallest element
vector<int> kSmallestElements(int* a,int n,int k){
    priority_queue<int> p;
    vector<int>v;
    for (int i = 0; i < k; i++)
    {
        p.push(a[i]);
    }
    for (int i = k; i < n; i++)
    {
        if(a[i]<p.top()){
            p.pop();
            p.push(a[i]);
        }
    }
    while (!p.empty())
    {
        v.push_back(p.top());
        p.pop();
    }
    return v;
       
}

// K largest elements
vector<int> kLargestElements(int* a,int n,int k){
    priority_queue<int,vector<int>, greater<int> >p;
    vector<int>v;
    for(int i=0;i<k;i++){
        p.push(a[i]);
    }
    for(int i=k;i<n;i++){
        if(a[i]>p.top()){
            p.pop();
            p.push(a[i]);
        }
    }
    while (!p.empty())
    {
        v.push_back(p.top());
        p.pop();
    }
    return v;
    
}

int main(){
    ////k smallest
    // int a[5]={10,12,6,7,9};
    // int k=3;
    // kSortedArray(a,5,k);
    // for(int i=0;i<5;i++){
    //     cout<<a[i]<<" ";
    // }

    ////  k largest
    int a[13] = { 2,12,9,16,10,5,3,20,25,11,1,8,6 };
    vector<int> v = kLargestElements(a, 13, 4);
    for(int i=0;i<v.size();i++ ){
        cout<<v[i]<<" ";
    }

    



    return 0;
}
