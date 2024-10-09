
// #include<iostream>
// #include<climits>
// using namespace std;
// class Stack{
//     int* data;//here we don't know the size,that's why we are making pointer only ,In constructor call we will take size from user 
//     int nextIndex;//and then will point it to *data;
//     int capacity;
//     public:
//     Stack(int totalSize){
//          data=new int[totalSize]; //dynamically created
//          nextIndex=0;
//          capacity=totalSize;
//     }
//     //return the number of elements present in my stack
//     int size(){
//         return nextIndex;
//     }
//     bool isEmpty(){
//         /*
//         if (nextIndex==0)
//         {
//             return true;
//         }else{
//             return false;
//         }
//         */
//        return nextIndex==0;//if newxtIndex=0,returns true else returns false
        
//     }

//     //insert element
//     void push(int element){//doesn't return anything,that's why return type is void 
//     if (nextIndex==capacity)
//     {
//         cout<<"Stack is Full\n";
//     }
//     data[nextIndex]=element;
//     nextIndex++;
    
         
//     }
//     //delete element
//     int pop(){//return type will be int,cuz after deleting the element we need to return the deleted element
//         if (isEmpty())
//         {
//             cout<<"Stack is Empty\n";
//             return INT_MIN;//just to indicate that my stack is empty,we return INT_MIN
//         }
        
//         nextIndex--;
//         return data[nextIndex];
//     }
//     // read top element
//     int top(){
//         if (isEmpty())
//         {
//             cout << "Stack is Empty\n";
//             return INT_MIN; // just to indicate that my stack is empty,we return INT_MIN
//         }
//         // cout<<data[nextIndex-1]<<endl;
//          return data[nextIndex - 1];
    
       
//     }

// };
// int main(){
//     Stack s(4);//object of stack is created//here we have to pass the size of the array
//     //which is bad habit
//     s.push(10);
//     s.push(20);
//     s.push(30);
//     s.push(40);
//     s.push(50);
//     cout<<s.top()<<endl;
//     cout<<s.pop()<<endl;
//     cout << s.top() << endl; 

//     return 0;
// }


//BEST WAY ->

//Using Dynamic Araay we can remove the size constraint in Stack which is entered by User
/*
#include<iostream>
#include<climits>
using namespace std;
class Stack{
    int *data;
    int nextIndex;
    int capacity;
    public:
    Stack(){
        data=new int[4];//just took a value to initialize the size
        nextIndex=0;
        capacity=4;
    }
    int size(){
        return nextIndex;
    }
    bool isEmpty(){
        // if (nextIndex==0)
        // {
        //     return true;
        // }else{
        //     return false;
        // }
        return nextIndex==0;
        
    }
    void push(int element){
        if (nextIndex==capacity)
        {
            int *newData=new int[2*capacity];
            for (int i = 0; i < capacity; i++)
            {
                newData[i]=data[i];
            }
            capacity *=2;
            delete []data;
            data=newData;
            
        }
        data[nextIndex]=element;
        nextIndex++;
        
    }
    int pop(){
        if (isEmpty())
        {
            cout<<"Stack is Empty\n";
            return INT_MIN;
        }
        else{
            nextIndex--;
            return data[nextIndex];
        }
        
    }
    int top(){
        if (isEmpty())
        {
            cout<<"Stack is Empty\n";
            return INT_MIN;
        }else{
            return data[nextIndex-1];
        }
        
    }

};
int main(){
    Stack s;
    cout << "Size " << s.size() << endl;
    cout<<s.isEmpty()<<endl;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout << "Size "<<s.size() << endl;
    s.push(50);
    cout << "Size " << s.size() << endl;
    cout << "Top Element "<<s.top()<<endl;
    s.pop();
    cout<<"Top Element "<<s.top()<<endl;
    s.push(60);
    s.push(70);
    s.push(80);

    s.push(90);
    cout << s.size() << endl;
    s.push(100);
    cout << s.size() << endl;

    return 0;
}
*/

#include <iostream>
using namespace std;
template <typename T>
class Stack
{
    T * data;
    int nextIndex;
    int capacity;

public:
    Stack()
    {
        data=new T[4];
        capacity = 4;
        nextIndex = 0;
    }
    int size()
    {
        return nextIndex;
    }
    bool isEmpty()
    {
        return nextIndex == 0;
    }
    void push(T element)
    {
        if (nextIndex == capacity)
        {
            T *newData = new T[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            capacity *= 2;
            delete[] data;
            data = newData;
        }
        data[nextIndex] = element;
        nextIndex++;
    }
    T top()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return data[nextIndex - 1];
        }
    }
    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty\n";
            return -1;
        }
        nextIndex--;
        return data[nextIndex];
    }
};
int main()
{
    Stack<int> s;
    cout << s.isEmpty() << endl;
    s.push(1);
    s.push(1);
    s.push(1);
    s.push(1);
    s.push(1);
    s.push(1);
    cout << s.top() << endl;

    return 0;
}

//reversing stack without using extra space
/*
#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int x)
{
    if (s.empty())
    {
        s.push(x);
        return;
    }
    int y = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(y);
}

void reverseStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int x = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, x);
}
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    reverseStack(s);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    // Output: 1 2 3 4 5
    return 0;
}
*/