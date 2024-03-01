/*
#include <iostream>
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
int main()          
{
    Node n1(1);
    Node *head = &n1;
    
    Node n2(2);
    Node n3(3);
    // n1.next = &n2;
    head->next=&n2;
    n2.next=&n3;
    cout << head->data << endl;
    cout << head->next << endl;
    cout << n1.next << endl;
    cout << head << endl;

    return 0;
}
*/

/*
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }

};
//Printing the linkedlist
void print(Node* head){
    while ( head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    //here, head pointer becomes NULL that's why it won't enter into below loop,
    //so first node's address has been lost,we will not be able to access the
    // data again,we should not do that,we first have to put address of first node in
    //temp variable then use the tamp variable as pointer in traversing 
   
    while ( head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    

    Node* temp=head;//this is the correct approach to print linked list,here head 
    //pointer is not NULL
    while (temp != NULL)
    {
        cout << temp->data << " ";
        head = temp->next;
    }
}
void print1(Node* head){
    cout << endl;
    while (head->next != NULL) // here last node's data will not be accessed
    {
        cout << head->data << " ";
        head = head->next;
    }
}
int main(){
    
    //Statically
    Node n1(1);//creation of a node(node is created while making an object )
    Node* head=&n1;
    Node n2(2);
    n1.next=&n2;
    cout<<n1.data<<" "<<n2.data<<endl;
    //printing the value of n1 using head pointer
    cout<<head->data<<endl;
    //Dynamically
    Node* n3=new Node(4);
    Node* head=n3;
    Node* n4=new Node(7);
    n3->next=n4;
    

   //statically
   Node n1(1);
   Node* head=&n1;
   Node n2(2);
   n1.next=&n2;
   Node n3(3);
   Node n4(4);
   Node n5(5);
   n2.next=&n3;
   n3.next=&n4;
   n4.next=&n5;
   print(head);//pass by value
   print(head);
   print1(head);


   return 0;
}
*/
//DYNAMICALLY
// #include<iostream>
// using namespace std;
// class Node{
//     public:
//     int data;
//     Node* next;
//     Node(int data){
//         this->data=data;
//         this->next=NULL;
//     }

// };

// void print(Node* head){
//     Node* temp=head;
    
//     while (temp!=NULL)//this is used to print all the data
//     {
//         cout<<temp->data<<" ";
//         temp=temp->next;
//     }
//     // while (temp->next != NULL)
//     // {
//     //     cout << temp->data << " ";
//     //     temp = temp->next;
//     // }
// }
// int main(){
    
//     Node *n1=new Node(1);
//     Node *head=n1;
//     Node *n2=new Node(2);
//     n1->next=n2;
//     cout<<n1->next<<endl;
//     cout<<head->next<<endl;
//     cout<<n2->next<<endl;
//     Node* n3=new Node(3);
//     Node* n4=new Node(4);
//     Node* n5=new Node(5);
//     n2->next=n3;
//     n3->next=n4;
//     n4->next=n5;
//     cout<<n4->data<<endl;
//     cout<<endl;
//     print(head);
//     cout<<endl;
//     print(head);//call by value
//     return 0;
// }


//Qn
// #include<iostream>
// using namespace std;
// class Node
// {
// public:
//     int data;
//     Node *next;
//     Node(int data)
//     {
//         this->data = data;
//         this->next = NULL;
//     }
// };

// void print(Node *head)
// {
//     Node *temp = head;

//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// int main()
// {

//     Node *node1 = new Node(10);
//     Node *node2 = new Node(20);
//     Node *node3 = new Node(20);
//     Node *node4 = new Node(20);
//     node1->next = node2;
//     node2->next = node3;
//     node3->next = node4;
//     print(node2);
// }
