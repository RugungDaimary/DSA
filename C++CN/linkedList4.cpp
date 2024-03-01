//  Qn)Merge two sorted LL
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
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
//Time COmplexity: O(n2)
// Node* mergeTwoLL(Node*h1,Node*h2){
//     Node* fT=NULL;
//     Node* fH=NULL;
//     for (int i = 0; h1!=NULL && h2!=NULL; i++)
//     {
       
//         if (h1->data< h2->data)
//         {
//             fT = fH = h1;
//             h1=h1->next;
            
//             for (int  j = 0;h1!=NULL && h2!=NULL; j++)
//             {
//                 if (h2->data<h1->data)
//                 {
//                     fT->next=h2;
//                     fT=fT->next;
//                     h2=h2->next;
//                 }else{
//                    fT->next=h1;
//                    fT=fT->next;
//                    h1=h1->next;
//                 }
                
//             }
            

//          }
//         else{//h2->data<h1->data
//             fT=fH=h2;
//             h2=h2->next;
//             for (int j = 0; h1 != NULL && h2 != NULL; j++)
//             {
//                 if (h1->data < h2->data)
//                 {
//                     fT ->next= h1;
//                     fT=fT->next;
//                     h1 = h1->next;
//                 }
//                 else
//                 {
//                     fT->next = h2;
//                     fT=fT->next;
//                     h2 = h2->next;
//                 }
//             }
//         }
            
//     }
//     if (h1!=NULL)
//     {
//         fT->next=h1;
//     }else{
//         fT->next=h2;
//     }
//     return fH;
    
// }

// OR Much better
Node *mergeTwoLL(Node *h1, Node *h2)
{
    if(h1==NULL){
        return h2;
    }
    if (h2==NULL)
    {
        return h1;
    }
    Node* fH=NULL;
    Node* fT=NULL;
    if (h1->data<h2->data)
    {
        fH=fT=h1;
        h1=h1->next;
    }
    else{
        fH=h2;
        fT=h2;
        h2=h2->next;
    }
    while (h1!='\0'&& h2!='\0')
    {
        if (h1->data<h2->data)
        {
            fT->next=h1;
            fT=fT->next;
            h1=h1->next;
        }
        else if(h2->data<=h1->data){
            fT->next=h2;
            fT=fT->next;
            h2=h2->next;
        }
        
    }
    while ((h1!=NULL))
    {
        fT->next=h1;
        fT=fT->next;
        h1=h1->next;
    }
    while (h2!=NULL)
    {
        fT->next=h2;
        fT=fT->next;
        h2=h2->next;
    }
    return fH;
    
    
    
}
int main(){
    Node* h1=takeInput();
    Node* h2=takeInput();
    // print(h1);
    // cout<<endl;
    // print(h2);
    cout<<endl;
    Node* h=mergeTwoLL(h1,h2);
    cout<<"Merged LinkedList : ";
    print(h);
    cout<<endl;


    
    return 0;
}

/*
//Sorted LL
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *previous;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->previous = NULL;
    }
};
int getMin(Node *head)
{
    return head->data;
}
int getMax(Node *head)
{
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    return temp->data;
}
Node *deleteMin(Node *head)
{
    Node *temp = head;
    head->previous->next = head->next;
    head->next->previous = head->previous;
    head = head->next;
    delete temp;
    return head;
}
Node *deleteMax(Node *head)
{
    Node *temp = head->previous;
    head->previous = temp->previous;
    temp->previous->next = head;
    delete temp;
    return head;
}
Node *takeInput()
{
    int data;
    cout << "Enter the data : " << endl;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    Node *temp = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            temp = newNode;
        }
        else if (head->next == NULL)
        {
            tail->next = newNode;
            tail = tail->next;
        }
        else
        {
            tail->next = newNode;
            tail->previous = temp;
            temp = temp->next;
            tail = tail->next;
        }
        cin >> data;
    }
    head->previous = tail;
    tail->next = head;
    return head;
}
void print(Node *head)
{
    Node *temp = head;
    int i = 0;
    while (temp != head || i == 0)
    {
        cout << temp->data << " ";
        temp = temp->next;
        i++;
    }
    cout << endl;
}
int main()
{
    Node *head;
    head = takeInput();
    print(head);
    cout << "Minimum value data : " << getMin(head) << endl;
    cout << "Maximum value data : " << getMax(head) << endl;
    head = deleteMin(head);
    print(head);
    head = deleteMax(head);
    print(head);
    return 0;
}

*/


//Reverse LL using Recursion
//Here time complexity is O(n2)

// #include <iostream>
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
//             tail = newNode;
//         }
//         cin >> data;
//     }
//     return head;
// }
// void print(Node *head)
// {
//     while (head != NULL)
//     {
//         cout << head->data << " ";
//         head = head->next;
//     }
// }

// Node* reverseLL(Node* head){
//     if (head==NULL || head->next==NULL)
//     {
//         return head;
//     }
//     Node *smallAns = reverseLL(head->next);
//     Node *temp = smallAns;
//     while (temp->next!=NULL)
//     {
//         temp=temp->next;
//     }
    
//     temp->next = head;
//     head->next = NULL;
//     return smallAns;

    
// }
// int main()
// {
//     Node *head = takeInput();
//     // print(head);
//     cout << endl;
//     head= reverseLL(head);
//     print(head);
//     cout << endl;
// }


//BETTER WAY
// #include <iostream>
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
// class Pair{//to return the multiple value from a function,here we return object of Pair class
//     public:
//     Node* head;
//     Node* tail;

// };
// Pair reverseLL(Node* head){
//     if (head==NULL || head->next==NULL)
//     {
//         Pair ans;
//         ans.head=head;
//         ans.tail=head;
//         return ans;
//     }
//     Pair samllAns = reverseLL(head->next);
//     samllAns.tail->next=head;
//     head->next=NULL;
//     Pair ans;
//     ans.head=samllAns.head;
//     ans.tail=head;
//     return ans;
// }
// Node * reverseLL_better(Node* head){
//     return reverseLL(head).head;
// }
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
//             tail = newNode;
//         }
//         cin >> data;
//     }
//     return head;
// }
// void print(Node *head)
// {
//     while (head != NULL)
//     {
//         cout << head->data << " ";
//         head = head->next;
//     }
// }
// int main(){
//     Node* head=takeInput();
//     // print(head);
//     head=reverseLL_better(head);
//     print(head);
// }



//MUCH BETTER
// #include <iostream>
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
// Node* reverseLL(Node* head){
//     if (head==NULL || head->next==NULL)
//     {
//         return head;
//     }
//     Node* smallAns = reverseLL(head->next);
//     Node* tail=head->next;
//     tail->next=head;
//     head->next=NULL;
//     return smallAns;
// }

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
//             tail = newNode;
//         }
//         cin >> data;
//     }
//     return head;
// }
// void print(Node *head)
// {
//     while (head != NULL)
//     {
//         cout << head->data << " ";
//         head = head->next;
//     }
// }
// int main(){
//     Node* head=takeInput();
//     // print(head);
//     head = reverseLL(head);
//     print(head);
// }



//Using Iteration
//SEGMENTATION FAULT

// #include <iostream>
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
// Node* reverseLL(Node* head){
//     Node* curr=head;
//     Node* prev=NULL;
//     Node* nxt=head->next;
//     for (int i = 0; nxt!=NULL; i++)
//     {
//         curr->next = prev;
//         curr = curr->next;
//         prev = prev->next;
//         nxt = nxt->next;
//     }
//     // curr->next = prev;

//     return curr;   
// }

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
//             tail = newNode;
//         }
//         cin >> data;
//     }
//     return head;
// }
// void print(Node *head)
// {
//     while (head != NULL)
//     {
//         cout << head->data << " ";
//         head = head->next;
//     }
// }
// int main(){
//     Node* head=takeInput();
//     head=reverseLL(head);    
//     print(head);
// }
