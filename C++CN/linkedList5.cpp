//CIRCULAR SINGLY LINKED LIST
// #include <iostream>
// using namespace std;
// class Node
// {
// public:
//     int data;
//     Node* next; 
//     Node(int data)
//     {
//         this->data = data;
//         this->next = NULL;     
//     }
// };
// Node *takeInput()
// {
//     int data;
//     cout << "Enter Data\n";
//     cin >> data;
//     Node *head = NULL;
//     Node *tail = NULL;
//     while (data != -1)
//     {
//         Node *newNode = new Node(data);
//         if (head == NULL)
//         {
//             head = newNode;
//             tail = newNode;
//         }
//         else
//         {
//             tail->next = newNode;
//             tail = tail->next;
//         }
//         cin >> data;
//     }
//     tail->next=head;
//     return head;
// }
// void print(Node *head)
// {
//     Node* temp=head->next;
//     cout<<head->data<<" ";
//     while (temp!= head)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
// }
// int getLength(Node* head){
//     Node* temp=head->next;
//     int count=1;
//     while (temp!=head)
//     {
//         temp=temp->next;
//         count++;
//     }
    
//     return count;
// }
// Node* insertAt_0th(Node* head){
    
    
// }
// int main()
// {
//     Node *head = takeInput();
   
//     print(head);
//     cout<<"\nLenght of CIRCULAR Singly Linked List is "<<getLength(head->next)<<endl;
// }



//Merge Sort
#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
Node *takeInput()
{
    int data;
    cout << "Enter Data\n";
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        cin >> data;
    }
    tail->next = head;
    return head;
}
void print(Node *head)
{
    Node *temp = head->next;
    cout << head->data << " ";
    while (temp != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int getLength(Node* head){
    int i=1;
    while (head!=NULL)
    {
        head=head->next;
        i++;
    }
    return i;
    
}
Node* mergeSort(Node* head){
    int L=getLength(head);
    Node* temp=head;
    for (int i = 0; i < (L/2)-1; i++)
    {
        temp=temp->next;
    }
    Node* HEAD=temp->next;
   
    
}
int main(){
    Node* head=takeInput();
    print(head);
    cout<<getLength(head);

}