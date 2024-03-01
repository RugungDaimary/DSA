//Taking Input In Linked List

// #include<iostream>
// using namespace std;
// class Node{
//     public:
//     int data;
//     Node* next;
//     Node(int data){
//         this-> data=data;
//         this->next=NULL;
//     }
// };
// Node* takeInput(){
//     int data;
//     cout<<"Enter data\n";
//     cin>>data;
//     Node *head=NULL;//initialll head points to NULL,means linkedlist is empty
//     while (data!=-1)//not a good method to create linkedList
//     {   
//         Node *newNode=new Node(data);
//         if (head==NULL)
//         {
//             head = newNode;
//         }else{
//             Node *temp=head;
//             while (temp->next!=NULL)
//             {
//                 temp=temp->next;
//             }
//             temp->next=newNode;     
//         }
//         cin>>data;  
//     }
//     return head;
    
// }
// void print(Node* head){
//     while (head!=NULL)
//     {
//         cout<<head->data<<" ";
//     }
//     head=head->next;
    
// }
// int main(){
//     Node* head=takeInput();
//     print(head);
    
//     return 0;

// }

//Better way

// #include<iostream>
// using namespace std;
// class Node{
//     public:
//     int data;
//     Node *next;
//     Node(int data){
//         this->data=data;
//         this->next=NULL;
//     }

// };

// Node *takeInput_better(){
//     int data;
//     cout<<"Enter data\n";
//     cin>>data;
//     Node *head=NULL;
//     Node *tail=NULL;
//     while (data!=-1)
//     {
//         Node *newNode=new Node(data);
//         if (head==NULL)
//         {
//             head=newNode;
//             tail=newNode;
//         }
//         else{
//             tail->next=newNode;
//            // tail=newNode;
//             tail=tail->next;
//         }
//         // tail->next = newNode;
//         // // tail=newNode;
//         // tail = tail->next;
//         cin >> data;
        
//     }
//     return head;
    
// }
// void print(Node *head){
//     while (head!=NULL)
//     {
//         cout<<head->data<<" ";
//         head=head->next;
//     }
    
// }

// int main(){

//     Node *head = takeInput_better();
//     print(head);

    
//     return 0;
// }



// Qn) Length of Singly LinkedList
// #include<iostream>
// using namespace std;
// class Node{
//     public:
//     int data;
//     Node *next;
//     Node(int data){
//         this->data=data;
//         this->next=NULL;

//     }

// };
// Node* takeInput(){
//     int data;
//     cout<<"Enter Data\n";
//     cin>>data;
//     Node *head=NULL;
//     Node *tail=NULL;
//     int count=0;
//     while (data!=-1)
//     {

//         Node *newNode=new Node(data);
//         if (head==NULL)
//         {
//             head=newNode;
//             tail=newNode;
//         }else{
//             tail->next=newNode;
//             tail=newNode;
//         }
//         cin>>data;
//         count++;
        
//     }
//     cout<<"Lenght of LinkedList = "<<count<<endl;
//     return head;
    
// }
// void print(Node *head){
//     while (head!=NULL)
//     {
//         cout<<head->data<<" ";
//         head=head->next;
//     }
//     cout<<endl;
    
// }
// int main(){
//     Node *head=takeInput();
//     cout<<"Linked List : ";
//     print(head);

    
//     return 0;
// }

//Qn)Printing i th data of a singly linked list
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
//         tail->next = newNode;
//         tail = tail->next;
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

// void getData(Node *head, int i)
// {
//     Node *temp = head;
//     for (int count = 0; temp != NULL; count++)
//     {
//         if (i == count)
//         {
//             cout << temp->data << endl;
//         }
//         temp = temp->next;
        
//     }
// }
// int main()
// {
//     Node *head = takeInput();
//     // print(head);
//     int i;
//     cout << "\nEnter the position\n";
//     cin >> i;
//     getData(head, i);

//     return 0;
// }

//OR
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
// Node* takeInput(int i){
//     int data;
//     cout<<"Enter Data\n";
//     cin>>data;
//     Node* head=NULL;
//     Node* tail=NULL;
//     int count=0;
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
//         count++;       
//     }
//     //cout<<"Size of LinkedList is "<<count<<endl;
//     Node* temp=head;
//     for (int j = 0; j < count; j++)
//     {
//         if (i==j && i<count)       
//         {
//             cout<<temp->data<<endl;          
//         }       
//         temp = temp->next;
//     }
//     if (i>count)
//     {
//         cout<<"Invalid Position\n";
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
// int main(){
//     int i;
//     cout << "Enter the position\n";
//     cin >> i;
//     Node *head=takeInput(i);
//     //print(head);
//     return 0;
// }


//Insertion of a node at a given position
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
//     cout<<"Enter the data\n";
//     cin>>data;
//     Node* head=NULL;
//     Node* tail=NULL;
//     while (data!=-1)
//     {
//         Node* newNode=new Node(data);
//         if (head==NULL)
//         {
//             head=newNode;
//             tail=newNode;
//         }else{
//             tail->next=newNode;
//             tail=tail->next;
//         }
//         cin>>data;

        
//     }
//     return head;
    
// }


// Node* insertNode(Node* head,int i,int data){//i here the position
//     Node* newNode=new Node(data);
//     Node *temp=head;
//     if(i==0){
//         newNode->next=head;
//         head=newNode;
//         return head;//the updated value of head should be returned to main
//         //if we insert 0th position then only return is required,otherwise void return type 
//     }
//     for (int count = 0; count < i-1 && temp!=NULL ; count++)
//     {
//         temp=temp ->next;
//         // count++;
//     }
    
//     if (temp!=NULL)
//     {
//         Node *a = temp->next;
//         temp->next = newNode;
//         newNode->next = a;
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
// int main(){
//     Node* head=takeInput();
//     print(head);
//     int i, data;
//     cout<<"\nEnter the position and data\n";
//     cin>>i>>data;
//     head=insertNode(head,i,data);
//     print(head);
//     cout<<endl;

//     return 0;
// }


//Deletion a node from a given position
// #include<iostream>
// using namespace std;
// class Node{
//     public:
//     int data;
//     Node *next;
//     Node(int data){
//         this->data=data;
//         this->next=NULL;
//     }

// };
// Node* takeInput(){
//     int data;
//     cout<<"Enter the data\n";
//     cin>>data;
//     Node* head=NULL;
//     Node* tail=NULL;

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
// void print(Node*head){
//     while (head!=NULL)
//     {
//         cout<<head->data<<" ";
//         head=head->next;
//     }
    
// }
// Node* deleteNode(Node* head,int i){
//     Node * temp=head;
//     Node * a=NULL;
//     Node * b=NULL;
//     if(i==0){
//         Node* first=head;
//         head=head->next;
//         delete first;
//         return head;
        
//     }
//     for (int count = 0; count <i-1 && temp!=NULL; count++)
//     {
//         temp=temp->next;  
//     }
//     if (temp != NULL && temp->next != NULL)
//     {
//         a=temp->next;
//         b=a->next;
//         temp->next=b;
//         delete a;
//     }
    
    
   
//     return head;
// }
// int main(){
//     Node* head=takeInput();
//     print(head);
//     int i;
//     cout<<"\nEnter Position\n";
//     cin>>i;
//     head=deleteNode(head,i);
//     print(head);

//     return 0;
// }

//Length of LinkedList Recursively
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
//     Node* head=NULL;
//     Node* tail=NULL;
    
//     while (data!=-1)
//     {
//         Node* newNode=new Node(data);
//         if(head==NULL){
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
// int getLength(Node* head){
//     if (head==NULL)
//     {
//         return 0;
//     }
//     int small=getLength( head->next);
//     return small+1;

// }
// int main(){
//     Node* head=takeInput();
//     print(head);
//     int ans=getLength(head);
//     cout<<"\nLength : "<<ans<<endl;
    
//     return 0;
// }
























// #include <iostream>
// using namespace std;
// class Node
// {
// public:
//     int value;
//     Node *next;
//     Node *previous;
//     Node(int data)
//     {
//         this->value = data;
//         this->next = NULL;
//         this->previous = NULL;
//     }
// };
// int getMin(Node *head)
// {
//     return head->value;
// }
// int getMax(Node *head)
// {
//     Node *temp = head->previous;
//     return temp->value;

//     // Node *temp=head;
//     //  while(temp->next!=Null)
//     //  {
//     //      temp=temp->next;                // By SLL
//     //  }
//     //  return temp->value;
// }
// void deleteMax(Node *head)
// {
//     Node *temp = head->previous;
//     Node *ptr = temp->previous;
//     ptr->next = head;
//     head->previous = ptr;
//     // delete max node
// }
// void deleteMin(Node *head)
// {
//     Node *temp = head;
//     head = head->next;
//     head->previous = temp->previous;
//     Node *ptr = temp->previous;
//     ptr->next = head;
//     // delete min node
// }
// Node *takeInput()
// {
//     int data;
//     cout<<"Enter Data\n";
//     cin>>data;
//     Node* head=NULL;
//     Node* tail=NULL;
//     while (data!=-1)
//     {
//         Node* newNode=new Node(data);
//         if ()
//         {
//             head=newNode;
//             tail=newNode;
//         }
//         tail->next=newNode;
//         tail->previous=
        

//     }
    
//     // int data1;
//     // cin >> data1;
//     // Node *head = NULL;
//     // // Node *newNode = Node new newNode;
//     // Node *n1(data1);
//     // int data;
//     // cin >> data;
//     // Node *n2(data);
//     // while (data != -1)
//     // {
//     //     // insert data in increasing order
//     //     n1->next = n2;
//     //     n2->previous = n1;
//     //     n1 = n2;
//     //     cin >> data;
//     // }
//     // n2->next = head;
//     // head->previous = n2;
// }
// int main()
// {

//     // Node *head = takeInput();
//     // getMax(head);
//     // getMin(head);
//     // deleteMax(head);
//     // deleteMin(head);
//     return 0;
// }

