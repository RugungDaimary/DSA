// Using Dynamic Araay we can remove the size constraint in Stack which is entered by User
//Stack Implementation using vector
/*
#include<iostream>
#include<climits>
#include<vector>
using namespace std;

class Stack {
    vector<int> data;

public:
    Stack() {
        // No need to initialize size, vector handles it
    }

    int size() {
        return data.size();
    }

    bool isEmpty() {
        return data.empty();
    }

    void push(int element) {
        data.push_back(element);
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return INT_MIN;
        } else {
            int topElement = data.back();
            data.pop_back();
            return topElement;
        }
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return INT_MIN;
        } else {
            return data.back();
        }
    }
};

int main() {
    Stack s;
    cout << "Size " << s.size() << endl;
    cout << s.isEmpty() << endl;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout << "Size " << s.size() << endl;
    s.push(50);
    cout << "Size " << s.size() << endl;
    cout << "Top Element " << s.top() << endl;
    s.pop();
    cout << "Top Element " << s.top() << endl;
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


//Using Array
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