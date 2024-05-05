#include<iostream>
#include<queue>
#include<vector>
using namespace std;
// Check Max-Heap
bool isMaxHeap(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        int parentIndex = i;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;
        if (leftChildIndex < n && a[parentIndex] < a[leftChildIndex])
        {
            return false;
        }
        if (rightChildIndex < n && a[parentIndex] < a[rightChildIndex])
        {
            return false;
        }
    }
    return true;
}
// Kth largest element
int KthLargest(int* a,int n,int k){
    priority_queue<int,vector<int>,greater<int> >p;
    for (int i = 0; i < k; i++)
    {  
        p.push(a[i]);   
    }
    for(int i=k;i<n;i++){
        if(a[i]>p.top()){
            p.pop();
            p.push(a[i]);
        }
    }
    return p.top();
    
}
//merge k sorted arrays
//Naive approach
// vector<int> mergeKsortedArrays(int k,int *a1,int n1,int*a2,int n2,int *a3,int n3,int *a4,int n4)
// {   
//     vector<int>ans;
//     for (int i = 0; i < n1; i++)
//     {
//         ans.push_back(a1[i]);
//     }
//     for (int i = 0; i < n2; i++)
//     {
//         ans.push_back(a2[i]);
//     }
//     for (int i = 0; i < n3; i++)
//     {
//         ans.push_back(a3[i]);
//     }
//     for (int i = 0; i < n4; i++)
//     {
//         ans.push_back(a4[i]);
//     }
//     sort(ans.begin(),ans.end());
//     return ans; 
// }
class data{
    public:
    int val, apos, vpos;
    data(int v,int ap,int vp){
        val=v;
        apos=ap;
        vpos=vp;
    }
};
class myComp{
    public:
    bool operator()(const data &d1,const data &d2){
        return d1.val>d2.val;
    }

};
vector<int> mergeKsortedArrays(vector<vector<int> > arr,int k){
    vector<int> ans;
    priority_queue<data, vector<data>, myComp> pq;
    for (int i = 0; i < k; i++)
    {
        data d(arr[i][0],i,0);
        pq.push(d);
    }
    while (!pq.empty())
    {
        data curr=pq.top();
        pq.pop();
        ans.push_back(curr.val);
        int ap=curr.apos;
        int vp=curr.vpos;
        if(vp+1<arr[ap].size()){
            data d(arr[ap][vp+1],ap,vp+1);
            pq.push(d);
        }
    }
    return ans;  
}

// Running median
int getMedian(priority_queue<int>&s, priority_queue<int, vector<int>, greater<int> >&g)
{
    if(s.size()>g.size()){
        return s.top();
    }else{
        return (s.top()+g.top())/2.0;
    }
}
void runningMedian(int *a,int n){
    priority_queue<int>s;
    priority_queue<int,vector<int>,greater<int> > g;
    s.push(a[0]);
    cout<<a[0]<<" ";
    for(int i=1;i<n;i++){
        int x=a[i];
        if(s.size()>g.size()){
            if(x<s.top()){
                g.push(s.top());
                s.push(x);
                s.pop();
            }else{
                g.push(x);
            
            }
            cout << getMedian(s, g) << " ";
        }else{//s.size()==g.size()
            if(x>s.top()){
                s.push(g.top());
                g.push(x);
                g.pop();
            }else{
                s.push(x);
                
            }
            cout << getMedian(s, g) << " ";
        }

    }
}

//Buy ticket
int timeTaken(int n,int *a,int k){
    queue<int>q;
    priority_queue<int>pq;
    int time=0;
    for (int i = 0; i < n; i++)
    {
        q.push(i);
        pq.push(a[i]);
    }
    while (!q.empty())
    {
        if (pq.top() == a[q.front()] ){
            if (k == q.front())
            {
                break;
            }
            time++;
            q.pop();
            pq.pop();
            
        }else{
            int x=q.front();
            q.pop();
            q.push(x);
        }
    }
    return time+1;
    
}


int main(){
    // int a[8]={40,30,18,6,14,11,9,4};
    // if(isMaxHeap(a,8)){
    //     cout<<"Max Heap\n";
    // }else{
    //     cout<<"Not a Max Heap\n";
    // }


    // int a[8] = {2,6,10,11,13,4,1,20};
    // cout<<KthLargest(a,8,4)<<endl;



    // int a[5] = {5,4,3,2,1};
    // runningMedian(a, 5);

    int a[]={3,9,4};
    cout<<"Time taken : "<<timeTaken(3,a,2)<<endl;


    return 0;
}