/*
#include<iostream>
using namespace std;
template <typename T>
// since we need to create linkedList that's why we have to make Node class
class Node
{
public:
    T data;
    Node<T>* next;
    Node(T data ){
        this->data=data;
        next=NULL;
    }
};
template<typename T>//one more need to specify,we need to specify for every class
class Stack{
    Node<T>* head;
    int size;//number of element present in stack
    public:
    Stack(){
        head=NULL;
        size=0;
    }
    int Size(){
        return size;

    }
    bool isEmpty(){
        // if ( head==NULL)
        // {
        //     return true;
        // }else{
        //     return false;
        // }
        return size==0;
    }
    void push(T element){
        Node<T> *newNode = new Node<T>(element);
        newNode->next = head;
        head = newNode;
        size++;    
    }
    T pop(){
        if (head==NULL)
        {
            cout<<"\nStack is Empty ";
            return 0;
            
        }
        T ans = head->data;
        Node<T> *temp = head; // if we delete head first then LL will be lost,we need
        // to save the address of head first in temp variable & move head to next.
        head = head->next;
        delete temp;
        size--;
        return ans;
    }
     T top(){
        if (head==NULL)
        {
            cout<<"\nStack is Empty ";
            return 0;
        }else{
            return head->data;
        }
        

    }
    



};
int main(){
    Stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.Size() << endl;
    s.pop();
    cout<<s.Size()<<endl;
    cout<<s.isEmpty()<<endl;
    cout<<"Top Element is "<<s.top()<<endl;
    s.pop();
    s.pop();
    cout << "Top Element is " << s.top() << endl;
}
*/

//Inbuilt Stack(using Template)
//In inbuilt stack pop() function doesn't return the deleted element.If we want 
//print the deleted element we have to first call top() function then pop().
#include<iostream>
using namespace std;
#include<stack>
int main(){
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    // cout<<s.empty()<<endl;
    // cout<<s.size()<<endl;
    // cout<<s.top()<<endl;
    // s.pop();
    // cout<<s.top()<<endl;
    // s.pop();
    // s.pop();
    // s.pop();
    // cout<<s.top()<<endl;
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}