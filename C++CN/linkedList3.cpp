//Insertion of a Node Recursively
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
// Node* takeInput(){
//     int data;
//     cout<<"Enter Data\n";
//     cin>>data;
//     Node*head=NULL;
//     Node*tail=NULL;
//     while (data!=-1)
//     {
//         Node* newNode=new Node(data);
//         if (head==NULL)
//         {
//             head=newNode;
//             tail=newNode;
//         }else{
//             tail->next=newNode;
//             tail=newNode;
//         }
//         cin>>data;
        
//     }
//     return head;
    

// }
// void print(Node* head){
//     while (head!=NULL)
//     {
//         cout<<head->data<<" ";
//         head=head->next;
//     }
    
// }
// Node* insertNode (Node*head,int i,int data){//here we need to pass reference
//     //base case
//     if(head==NULL){
//         return head;
//     }
    
//     if (i==0)//small calculatin
//     {
//         Node* newNode=new Node(data);
//         newNode->next=head;
//         head=newNode;
//         return head;
//     }
//     else{
//         // if (/* condition */)//i is equal to length of LL insert at last position
//         // {
//         //     /* code */
//         // }
        
//         Node *small = insertNode (head->next,i-1,data);
//         head->next=small;

//         return head;
//     }
   
    
// }
// int main(){
//     Node *head = takeInput();
//     print(head);
//     int i,data;
//     cout<<"\nEnter the Position & Data\n";
//     cin>>i>>data;
//     head=insertNode (head,i,data);
//     print(head);

//     return 0;
// }


//Delete a Node from a given position using Recursion
// #include<iostream>
//     using namespace std;
//     class Node{
//         public:
//         int data;
//         Node* next;
//         Node(int data){
//             this->data=data;
//             this->next=NULL;
//         }
//     };
//     Node* takeInput(){
//         int data;
//         cout<<"Enter Data\n";
//         cin>>data;
//         Node*head=NULL;
//         Node*tail=NULL;
//         while (data!=-1)
//         {
//             Node* newNode=new Node(data);
//             if (head==NULL)
//             {
//                 head=newNode;
//                 tail=newNode;
//             }else{
//                 tail->next=newNode;
//                 tail=newNode;
//             }
//             cin>>data;

//         }
//         return head;

//     }
//     void print(Node* head){
//         while (head!=NULL)
//         {
//             cout<<head->data<<" ";
//             head=head->next;
//         }

//     }

//     Node* deleteNode(Node*head,int i){
//         //base case
//         if (head==NULL)
//         {
//             return NULL;//or return head;
//         }
//         //samll calculation
//         if (i==0)
//         {
//             Node* a=head;
//             head=head->next;
//             delete a;
//             return head;
//         }else{
//             Node* small=deleteNode(head->next,i-1);
//             head->next=small;
//             return head;
//         }
        
        

//     }

//     int main(){
//         Node* head=takeInput();
//         print(head);
//         int i;
//         cout<<"\nEnter the Position to Delete\n";
//         cin>>i;
//         head=deleteNode(head,i);
//         print(head);

//     }

// Qn)Finding a node in LL
//  #include<iostream>
//  using namespace std;
//  class Node{
//      public:
//      int data;
//      Node* next;
//      Node(int data){
//          this->data=data;
//          this->next=NULL;
//      }
//  };
//  Node* takeInput(){
//      int data;
//      cout<<"Enter Data\n";
//      cin>>data;
//      Node*head=NULL;
//      Node*tail=NULL;
//      while (data!=-1)
//      {
//          Node* newNode=new Node(data);
//          if (head==NULL)
//          {
//              head=newNode;
//              tail=newNode;
//          }else{
//              tail->next=newNode;
//              tail=newNode;
//          }
//          cin>>data;

//     }
//     return head;

// }
// void print(Node* head){
//     while (head!=NULL)
//     {
//         cout<<head->data<<" ";
//         head=head->next;
//     }

// }
// int getIndex(Node* head,int N){
//     Node* temp=head;
//     for (int i = 0; temp!=NULL; i++)
//     {
//         if (temp->data == N)
//         {
            
//             return i;
//         }
//         temp = temp->next;      
//     }
//     return -1;
// }
// int main(){
//     Node* head=takeInput();
//     print(head);
//     int N;
//     cout<<"\nEnter N\n";
//     cin>>N;
//     int ans=getIndex(head,N);
//     if (ans==-1)
//     {
//         cout<<"Not Present\n";
//     }else{
//         cout<<"Present at index "<<ans<<endl;
//     }
// }

//Finding Mid Point of LL
// #include<iostream>
// using namespace std;
//  class Node{
//      public:
//      int data;
//      Node* next;
//      Node(int data){
//          this->data=data;
//          this->next=NULL;
//      }
//  };
//  Node* takeInput(){
//      int data;
//      cout<<"Enter Data\n";
//      cin>>data;
//      Node* head=NULL;
//      Node* tail=NULL;
//      while (data!=-1)
//      {
//          Node* newNode=new Node(data);
//          if (head==NULL)
//          {
//              head=newNode;
//              tail=newNode;
//          }else{
//              tail->next=newNode;
//              tail=newNode;
//          }
//          cin>>data;

//     }
//     return head;

// }
// void print(Node* head){
//     while (head!=NULL)
//     {
//         cout<<head->data<<" ";
//         head=head->next;
//     }

// }
// int getMid(Node* head){
    

//     Node *slow = head->next;
//     Node *fast = head->next->next;
//     while (fast->next != NULL && fast->next->next != NULL)
//     {
//         slow = slow->next;
//         fast = fast->next;
//     }
//     return slow->data;
// }
// int main(){
//     Node* head=takeInput();
//     print(head);
//     cout<<endl;
//     cout<<"Mid element is "<<getMid(head)<<endl;

    
//     return 0;
// }

// // Append(add to the last) Last n to first(Some changes to be done)
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
//             tail = tail->next;
//         }

//         cin >> data;
//     }
//     return head;
// }
// int print(Node *head)
// {
//     int count = 0;
//     while (head != NULL)
//     {
//         cout << head->data << " ";
//         head = head->next;
//         count++;
//     }
//     cout << endl;
//     return count;
// }
// int getLength(Node *head)
// {
//     if (head == NULL)
//     {
//         return 0;
//     }
//     int small = getLength(head->next);
//     return 1 + small;
// }
// Node *append(Node *head, int N)
// {
//     Node *temp = head;
//     Node *tail = head;
//     int L = getLength(head);
//     int n = L - N;
//     for (int i = 0; i < n - 1; i++)
//     {
//         temp = temp->next;
//     }
//     Node *a = temp->next;
//     temp->next = NULL;
//     while (tail->next != NULL)
//     {
//         tail = tail->next;
//     }
//     tail->next = head;
//     head = a;
//     return head;

//     // int len = length(head);
//     // if (n < len && n != 0)
//     // {
//     //     int skip = len - n;
//     //     Node *current = head;
//     //     Node *prev = NULL;
//     //     while (skip)
//     //     {
//     //         prev = current;
//     //         current = current->next;
//     //         skip--;
//     //     }
//     //     prev->next = NULL;
//     //     Node *temp = current;
//     //     while (current->next != NULL)
//     //     {
//     //         current = current->next;
//     //     }
//     //     current->next = head;
//     //     head = temp;
//     // }
//     // return head;
// }
// int main()
// {
//     Node *head = takeInput();
//     print(head);

//     int N;
//     cout << "Enter the value of N\n";
//     cin >> N;
//     // Node* HEAD=append(head,L,N);
//     // print(HEAD);
//     print(append(head, N));
// }



// PRINT REVERSE LINKED LIST using recursion
//   #include<iostream>
//   using namespace std;
//    class Node{
//        public:
//        int data;
//        Node* next;
//        Node(int data){
//            this->data=data;
//            this->next=NULL;
//        }
//    };
//    Node* takeInput(){
//        int data;
//        cout<<"Enter Data\n";
//        cin>>data;
//        Node*head=NULL;
//        Node*tail=NULL;
//        while (data!=-1)
//        {
//            Node* newNode=new Node(data);
//            if (head==NULL)
//            {
//                head=newNode;
//                tail=newNode;
//            }else{
//                tail->next=newNode;
//                tail=newNode;
//            }
//            cin>>data;
//     }
//     return head;
// }
// void print(Node* head){
//     while (head!=NULL)
//     {
//         cout<<head->data<<" ";
//         head=head->next;
//     }

// }
// void printList(Node* head){
//     //base case 
//     if (head==NULL)
//     {
//         return;
//     }
//     if (head->next==NULL)
//     {
//         cout<<head->data<<" ";
//     }else{
//         printList(head->next);
//         cout<<head->data<<" ";
//     }
// }

// int main(){
//     Node* head=takeInput();
//     cout<<"List is :-> ";
//     print(head);
//     cout<<endl;
//     cout<<"Reverse Linked List is :-> ";
//     printList(head);
//     cout<<endl;

// }


//Qn)Check Palindrome or not
/* Thoda pending hai
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
Node* reverseList(Node* y){
    //base case
    Node* a=NULL;
    if (y==NULL)
    {
        return 0;
    }
    if (y->next==NULL)
    {
       
        cout<<y->data<<" ";
        return y;
    }else{
       a= reverseList(y->next);
      
        cout<<y->data<<" ";
        //return a;
       
    }
    return a;

}
bool checkPalindrome(Node* head){
    Node* temp=head;
    Node*h1=head;
    Node* h2 = NULL;
    Node* y=head;
    int count=1;
    for (;temp->next!=NULL ; count++)
    {
        temp=temp->next;
    }
   // cout<<count<<endl;
    int mid=(count+1)/2;
    int i=1;
    while (i<=mid)
    {
        y=y->next;
        i++;
    }
    cout<<endl;
    cout<<y->data<<endl;
    
    h2=reverseList(y);
    while (h2->next!=NULL)
    {
        if (h1->data == h2->data)
        {
            h1 = h1->next;
            h2= h2->next;
        }
        h2=h2->next;
        return true;
    }
    return false;
}

int main(){
    Node* head=takeInput();
    cout<<endl;
    if (checkPalindrome(head))
    {
       cout<<"Palindrome\n";
    }else{
        cout<<"Not Palindrome\n";
    }
    
    

}

*/

//Finding a node in List
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
// int getIndex(Node* head,int data){
//     Node* temp=head;
//     for (int i = 0; temp!=NULL; i++)
//     {
//         if (data==temp->data)
//         {
//            // cout<<"Index " <<i<<endl;
//             return i;
//         }
        
//         temp=temp->next;
//     }
//     return -1;
// }
// int main(){
//     Node* head=takeInput();
//     print(head);
//     int data;
//     cout<<"\nEnter data to search\n";
//     cin>>data;
//     int ans = getIndex(head, data);
//     if (ans == -1)
//     {
//         cout<<"Not Found\n";
//     }else{
//         cout << "Index : " << ans << endl;
//     }
    
     
    
//     return 0;
// }



// Qn)Eliminate the Dublicate in Sorted linked list
//  #include<iostream>
//  using namespace std;
//   class Node{
//       public:
//       int data;
//       Node* next;
//       Node(int data){
//           this->data=data;
//           this->next=NULL;
//       }
//   };
//   Node* takeInput(){
//       int data;
//       cout<<"Enter Data\n";
//       cin>>data;
//       Node*head=NULL;
//       Node*tail=NULL;
//       while (data!=-1)
//       {
//           Node* newNode=new Node(data);
//           if (head==NULL)
//           {
//               head=newNode;
//               tail=newNode;
//           }else{
//               tail->next=newNode;
//               tail=newNode;
//           }
//           cin>>data;

//     }
//     return head;

// }
// void print(Node* head){
//     while (head!=NULL)
//     {
//         cout<<head->data<<" ";
//         head=head->next;
//     }

// }
// void eliminateDuplicate(Node* head){
//     Node* t1=head;
//     Node* t2=head->next;
//     if (head==NULL || head->next==NULL)
//     {
//         return;
//     }
//     while (t2!=NULL)
//     {
//         if (t1->data==t2->data)
//         {
//            Node * x=t2;
//         //    cout<<t2->data<<" ";

//            delete x;

//            t2=t2->next;

//         }else{
//             t1->next=t2;
//             t1 = t1->next;
//             t2 = t2->next;
//         }

//     }
//     t1->next=t2;

// }

// int main(){
//     Node* head=takeInput();
//     print(head);
//     cout<<endl;

//     eliminateDuplicate(head);
//     cout<<"\nAfter Elimination of dublicates : ";

//     print(head);
//     cout<<endl;

// }

// REVERSE A LINKED LIST
//  #include <iostream>
//    using namespace std;
//     class Node{
//         public:
//         int data;
//         Node* next;
//         Node(int data){
//             this->data=data;
//             this->next=NULL;
//         }
//     };
//     Node* takeInput(){
//         int data;
//         cout<<"Enter Data\n";
//         cin>>data;
//         Node*head=NULL;
//         Node*tail=NULL;
//         while (data!=-1)
//         {
//             Node* newNode=new Node(data);
//             if (head==NULL)
//             {
//                 head=newNode;
//                 tail=newNode;
//             }else{
//                 tail->next=newNode;
//                 tail=newNode;
//             }
//             cin>>data;
//      }
//      return head;
//  }
//  void print(Node* head){
//      while (head!=NULL)
//      {
//          cout<<head->data<<" ";
//          head=head->next;
//      }

// }
// Node *reverseLL(Node *head)
// {
//      // Two Pointer Approach
//      Node *prev = NULL;
//      Node *curr = head;
//      if (curr == NULL)
//      {
//          cout << "No linked List\n";
//          return NULL;
//      }
//      Node *forward = head->next;

//      while (curr != NULL)
//      {
//          forward = curr->next;
//          curr->next = prev;
//          prev = curr;

//          curr = forward;
//      }
//      return prev;
// }

// int main(){
//     Node* head=takeInput();
//     cout<<"List is :-> ";
//     print(head);
//     cout<<endl;
//     cout<<"Reverse Linked List is :-> ";
//     print(reverseLL(head));
//     cout<<endl;

// }

// Palindrome Check
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

int getLength(Node *head)
{
    if (head == NULL)
    {
         return 0;
    }
    else
    {
         return getLength(head->next) + 1;
    }
}
Node *reverseList(Node *head)
{
    // Two Pointer Approach
    Node *prev = NULL;
    Node *curr = head;
    if (curr == NULL)
    {

         return NULL;
    }
    Node *forward = head->next;

    while (curr != NULL)
    {
         forward = curr->next;
         curr->next = prev;
         prev = curr;

         curr = forward;
    }
    return prev;
}
bool isPalindrome(Node *head)
{
    // Write your code here.
    int L = getLength(head);
    Node *temp = head;
    for (int i = 0; i < L / 2; i++)
    {
         temp = temp->next;
    }
    Node *HEAD = reverseList(temp);
    while (HEAD != NULL)
    {
         if (HEAD->data != head->data)
         {
                return false;
         }
         else
         {
                HEAD = HEAD->next;
                head = head->next;
         }
    }
    return true;
}
int main(){
    Node* head=takeInput();
    print(head);
    cout<<endl;
    if (isPalindrome(head))
    {
        cout<<"Palindrome\n";
    }else{
        cout<<"Not a Palindrome\n";
    }
    
}