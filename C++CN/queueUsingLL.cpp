
#include<iostream>
using namespace std;
template<typename T>
class Node{
    public:
    T data;
    Node<T>* next;
    Node(T data){
        this->data=data;
        this->next=NULL;
    }   
};
template<typename T>
class Queue{
    Node<T>* head;
    Node<T>* tail;
    int size;
    public:
    Queue(){
        head=NULL;
        tail=NULL;
        size=0;
    }
    void enqueue(T element){
        Node<T>* newNode = new Node<T>(element);
        if(head==NULL){
            head=newNode;
            tail=newNode; 
        }
        tail->next=newNode; 
        tail=tail->next;
        size++;
       
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size==0;
    }
    T front(){
        if (isEmpty())
        {
            cout<<"Queue is Empty\n";
            return 0;
        }
        return head->data;
    }
    T dequeue(){
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return 0;
        }
        T ans=head->data;
        Node<T> *temp=head;
        head = head->next;
        delete temp;
        size--;  
        return ans;     
    }

};
int main(){
    Queue<int>q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout<<q.getSize()<<endl;
    cout<<q.front()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.getSize()<<endl;

    return 0;
}

//Queue using inbuilt 
// #include<iostream>
// using namespace std;
// #include<queue>
// int main(){
//     queue<int>q;
//     q.push(10);
//     q.push(20);
//     q.push(30);
//     q.push(40);
//     // cout<<q.front()<<endl;
//     // cout<<q.size()<<endl;
//     // q.pop();
//     // cout<<q.front()<<endl;
//     // cout<<q.empty()<<endl;
    
//     while (!q.empty())
//     {
//         cout<<q.front()<<endl;
//         q.pop();
//     }
    
//     cout<<q.size()<<endl;
    
//     return 0;
// }